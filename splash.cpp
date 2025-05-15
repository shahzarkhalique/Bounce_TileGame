#include "splash.hpp"
#include "drawing.hpp"
#include "game.hpp"

SDL_Renderer* Drawing::gRenderer = NULL;
SDL_Texture* Drawing::assets = NULL;

bool Splash::init()
{
	//Initialization flag
	bool success = true;


	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}
		if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
                printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                success = false;
        }

		//Create window
		gWindow = SDL_CreateWindow( "Bouncy Bounce :)", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			Drawing::gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( Drawing::gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( Drawing::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

			}
		}
	}

	return success;
}

bool Splash::loadMedia()
{
	//Loading success flag
	bool success = true;
	
	Music= Mix_LoadMUS("mainscreen.mp3");
	Mix_PlayMusic(Music,-1);
    gTexture = loadTexture("play.png");
	if(gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	
	if(Music==NULL)
    {
        printf("Unable to run due to error: %s\n",Mix_GetError());
        success =false;
    }
	return success;	
}

void Splash::close()
{
	//Free loaded images
	
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( Drawing::gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	Drawing::gRenderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Splash::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( Drawing::gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}
int Splash::runner(){
		
		Game* game = new Game();
    	if (game->Init()) {
        game->Run();
		}
    		// Clean up
    	delete game;	
		return 0;
}
bool Splash::loadInstructions()
{
	
	bool success = true;
	
	
    gTexture = loadTexture("Instructions.png");
	if(gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	return success;
}
void Splash::run()
{
	bool quit = false;
	SDL_Event e;

	

	while( !quit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}

			if(e.type == SDL_MOUSEBUTTONDOWN){
			//this is a good location to add pigeon in linked list.
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
				if ( state==0 && xMouse > 530 && xMouse < 640 && yMouse > 130 && yMouse < 200)
				{
					state=1;
				}
				else if(state==0 && xMouse > 538 && xMouse < 627 && yMouse > 330 && yMouse < 400)
				{

					quit=true;
				}
				else if(state==0 && xMouse > 503 && xMouse < 682 && yMouse > 240 && yMouse < 300)
				{
					state=2;
					loadInstructions();	
					
				}
				else if(state==2 && xMouse > 603 && xMouse < 752 && yMouse > 400 && yMouse < 550)
				{
					state=0;
					loadMedia();
				}
				else if (state==1)
				{
					state=0;
					runner();
						
				}
				
			}
		}
		
    

		SDL_RenderClear(Drawing::gRenderer); //removes everything from renderer
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL);//Draws background to renderer
    	SDL_RenderPresent(Drawing::gRenderer); //displays the updated renderer
	    SDL_Delay(100);	//causes sdl engine to delay for specified miliseconds
		
		
	}
			
}
