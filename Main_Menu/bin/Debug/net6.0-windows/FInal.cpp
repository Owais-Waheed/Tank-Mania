# include <iostream>
# include <SDL.h>
# include <SDL_image.h>
#include <stdio.h>
#include <SDL_mixer.h>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;


//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image as texture
SDL_Texture* loadTexture( std::string path );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Current displayed texture
SDL_Texture* gTexture = NULL;
//global reference to png image sheets
SDL_Texture* assets_up=NULL;
SDL_Texture* assets_down=NULL;
SDL_Texture* assets_left=NULL;
SDL_Texture* assets_right=NULL;




Mix_Music *bgMusic = NULL;

// Variables for objects for demo .
SDL_Rect srcRect_tank_1 = {6,7,95,93};
SDL_Rect srcRect_tank_2 = {4,128,95,93};
SDL_Rect srcRect_flag_1 = {256 , 235, 42 ,61} ;
SDL_Rect srcRect_flag_2 = {379, 235,42 ,61} ;

SDL_Rect moverRect_tank_1 = { 250 , 250 , 50,50} ;
SDL_Rect moverRect_tank_2 = { 750 , 250 , 50,50} ;
SDL_Rect moverRect_flag_1 = { 100 , 250 , 30 , 20} ;
SDL_Rect moverRect_flag_2 = { 900 , 250 , 30 , 20} ;


bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
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

		//Create window
		gWindow = SDL_CreateWindow( "Tank Wars!!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				// if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				// {
				// 	printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
				// 	success = false;
				// }
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	assets_down = loadTexture("Assets_D.png");
    assets_left = loadTexture("Assets_L.png");
    assets_right = loadTexture("Assets_R.png");
    assets_up = loadTexture("Assets_U.png");
    gTexture = loadTexture("Level_1.png");


    if(assets_down==NULL || assets_left == NULL || assets_right == NULL || assets_up == NULL || gTexture == NULL )
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	// bgMusic = Mix_LoadMUS( "beat.wav" );

	// if(bgMusic == NULL){
	// 	printf("Unable to load music: %s \n", Mix_GetError());
	// 	success = false;
	// }
	return success;
}

void close()
{
	//Free loaded images
	SDL_DestroyTexture(assets_up);
    SDL_DestroyTexture(assets_down);
    SDL_DestroyTexture(assets_left);
    SDL_DestroyTexture(assets_right);
	assets_right , assets_up , assets_down , assets_left =NULL;
	
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	// Mix_FreeMusic(bgMusic);
	// bgMusic = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	// Mix_Quit();
	SDL_Quit();
}

SDL_Texture* loadTexture( std::string path )
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
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

int main( int argc, char* args[] )
{

        SDL_RenderClear( gRenderer );

	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
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

				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					if(e.type == SDL_MOUSEBUTTONDOWN)	
                        {
                            
                        }

					// update();	
				}

		}

		//SDL_RenderClear(gRenderer); //removes everything from renderer
		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************

		//humania.drawObjects();
        SDL_RenderCopy(gRenderer, assets_down, &srcRect_flag_1 , &moverRect_flag_1);
        SDL_RenderCopy(gRenderer, assets_down, &srcRect_flag_2 , &moverRect_flag_2);
		SDL_RenderCopy(gRenderer, assets_down, &srcRect_tank_1 , &moverRect_tank_1);
        SDL_RenderCopy(gRenderer, assets_down, &srcRect_tank_2 , &moverRect_tank_2);
        // SDL_RenderCopy(gRenderer, assets_down, &srcRect_flag_1 , &moverRect_flag_1);
        // SDL_RenderCopy(gRenderer, assets_down, &srcRect_flag_2 , &moverRect_flag_2);


		//****************************************************************
    	SDL_RenderPresent(gRenderer); //displays the updated renderer

	    // SDL_Delay(100);	//causes sdl engine to delay for specified miliseconds
	}
    
			
} 
    }
	close();

	return 0;

}
