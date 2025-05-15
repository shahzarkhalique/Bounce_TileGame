
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <SDL_mixer.h>

class Splash{
    //Screen dimension constants
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;
    Mix_Music *Music = NULL;
    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    int state=0;

public:

    bool loadInstructions();
    int runner();
    bool init();
    bool loadMedia();
    void close();
    SDL_Texture* loadTexture( std::string path );
    void run();
};

