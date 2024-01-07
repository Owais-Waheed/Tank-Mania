#pragma once
#include "game.hpp"
#include "Player1.hpp"
#include "Player2.hpp"
#include "Bullet.hpp"
#include  <vector>
#include "drawing.hpp"


SDL_Renderer* Drawing::gRenderer = NULL;
// SDL_Texture* Drawing::assets = NULL;

//Current displayed texture
SDL_Texture* Drawing::gTexture = NULL;
//global reference to png image sheets
SDL_Texture* Drawing::assets_up=NULL;
SDL_Texture* Drawing::assets_down=NULL;
SDL_Texture* Drawing::assets_left=NULL;
SDL_Texture* Drawing::assets_right=NULL;

bool Game::init()
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

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;

	Drawing::assets_down = loadTexture("Assets/Assets_D.png");
    Drawing::assets_left = loadTexture("Assets/Assets_L.png");
    Drawing::assets_right = loadTexture("Assets/Assets_R.png");
    Drawing::assets_up = loadTexture("Assets/Assets_U.png");
    Drawing::gTexture = loadTexture("Assets/Level_1.png");


    if(Drawing::assets_down==NULL || Drawing::assets_left == NULL || Drawing::assets_right == NULL || Drawing::assets_up == NULL || Drawing::gTexture == NULL )
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	// music = Mix_LoadMUS( "beat.wav" );

	// if(music == NULL){
	// 	printf("Unable to load music: %s \n", Mix_GetError());
	// 	success = false;
	// }
	return success;
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(Drawing::assets_up);
    SDL_DestroyTexture(Drawing::assets_down);
    SDL_DestroyTexture(Drawing::assets_left);
    SDL_DestroyTexture(Drawing::assets_right);
	Drawing::assets_right , Drawing::assets_up , Drawing::assets_down , Drawing::assets_left =NULL;
	
	//Destroy window
	SDL_DestroyRenderer( Drawing::gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	Drawing::gRenderer = NULL;


	IMG_Quit();
	// Mix_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
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
void Game::run( )
{
	bool quit = false;
	SDL_Event e;

	// HUMania humania;
	Tank* t_array[2] ;
	// Bullet* b_array[2];
	std::vector<Bullet*> bullets1 ;
	std::vector<Bullet*> bullets2;

	//2 for Grey // 1 for brown // 0 for blue.
	t_array[0] = new Player1(0);


	SDL_Rect srcRect_blue_flag_down = {256,235,42,61};
	SDL_Rect srcRect_red_flag_down = {379,235,42,61};
	SDL_Rect moverRect_red_flag_down = {900,250,42,61};
	SDL_Rect moverRect_blue_flag_down = {100,250,42,61};

	// 5 for purple; // 4 for green ; // 3 for pink ;
	t_array[1] = new Player2(3);

	// for (int i = 0 ; i<2 ; i++)
	// {
	// 	b_array[i] = new Bullet(t_array[i]->moverRect_tank_1);

	// }

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

			// }
			if(SDL_KEYDOWN == e.type)	
			{
				// p1.moveTank(e.key.keysym.sym);
				// p2.moveTank(e.key.keysym.sym);
				// tank_2_move();

				for (int i = 0 ; i<2 ; i++)
				{
					t_array[i]->moveTank(e.key.keysym.sym);
					if(e.key.keysym.sym == SDLK_SPACE)
					{
						bullets1.push_back(new Bullet(t_array[0]->moverRect_tank_1 , t_array[0]->current_direction));
						
					} 
					else if(e.key.keysym.sym == SDLK_RETURN)
					{
						bullets2.push_back(new Bullet(t_array[1]->moverRect_tank_1 , t_array[1]->current_direction));
						
					} 
				}


			}
		}

		SDL_RenderClear(Drawing::gRenderer); //removes everything from renderer
		SDL_RenderCopy(Drawing::gRenderer, Drawing::gTexture, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************

		// humania.drawObjects();

			SDL_RenderCopy(Drawing::gRenderer, Drawing::assets_down, &srcRect_red_flag_down, &moverRect_red_flag_down );
			SDL_RenderCopy(Drawing::gRenderer, Drawing::assets_down, &srcRect_blue_flag_down, &moverRect_blue_flag_down );


				for (int i = 0 ; i<2 ; i++)
				{
					if(not (t_array[i]->collison))
					{
					t_array[i]->draw_tank(t_array[i]->current_direction);
					}
				}
					
				
				int a = 0;
				while (a < bullets1.size())
				{
					// if(not (t_array[1]->collison))
					// {
					
					
					bullets1[a]->draw();// called to render object on screen
					t_array[1]-> collison = SDL_HasIntersection( &t_array[1]->moverRect_tank_1 , &bullets1[a]->mover_rect_bullet);
					// called to move object 
					a++;
					// }
				}
				int b=0 ;
				while (b < bullets2.size())
				{
					bullets2[b]->draw();// called to render object on screen
					
					// called to move object 
					b++;
				}
		//****************************************************************
    	SDL_RenderPresent(Drawing::gRenderer); //displays the updated renderer

	    SDL_Delay(100);	//causes sdl engine to delay for specified miliseconds
	}
			
}
