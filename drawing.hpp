#include<SDL.h>
#pragma once
class Drawing{
    public:
        //The window renderer
    static SDL_Renderer* gRenderer;
    //global reference to png image sheets
    

    static SDL_Texture* gTexture ;
//global reference to png image sheets
    static SDL_Texture* assets_up;
    static SDL_Texture* assets_down;
    static SDL_Texture* assets_left;
    static SDL_Texture* assets_right;

    
};