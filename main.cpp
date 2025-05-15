

#include "main.hpp"

int main(int argc, char* argv[]) {

    // Create the game object
    int current_state=0;
    Splash splash;
    
    
    srand(time(NULL));
    if( !splash.init() ){
		printf( "Failed to initialize!\n" );
        
	}
		//Load media
    if( !splash.loadMedia() ){
        printf( "Failed to load media!\n" );
    }

    splash.run();
    splash.close();
    

    
	
    
    
return 0;
}

