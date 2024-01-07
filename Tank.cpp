#pragma once
# include "Tank.hpp"


void Tank::draw_tank(int current_pos )
    {   
        switch(current_pos)
        {
            case 0:
             SDL_RenderCopy(Drawing::gRenderer, Drawing::assets_down, &tank_down , &moverRect_tank_1);
             break;
            
            case 1:
                SDL_RenderCopy(Drawing::gRenderer, Drawing::assets_up, &tank_up , &moverRect_tank_1);
                break;

            case 2:
                SDL_RenderCopy(Drawing::gRenderer, Drawing::assets_right, &tank_right , &moverRect_tank_1);
                break;

            case 3:
                SDL_RenderCopy(Drawing::gRenderer, Drawing::assets_left, &tank_left , &moverRect_tank_1);
                break;

        }

    }


    void Tank::moveSouth(){ 
        if (moverRect_tank_1.y+yJump < 570)moverRect_tank_1.y+=yJump;    
    }
    void Tank::moveNorth(){
        if (moverRect_tank_1.y-yJump > 30)moverRect_tank_1.y-=yJump;
        else moverRect_tank_1.y = 0;
    }
    void Tank::moveEast(){
        if (moverRect_tank_1.x+xJump < 970)moverRect_tank_1.x+=xJump;
    }
    void Tank::moveWest(){
        if (moverRect_tank_1.x-xJump > 30)moverRect_tank_1.x-=xJump;
    }

    void Tank:: rotate_clockwise() // 0 means facing down , 1 mean facing up , 2 mean facing right , 3 mean facing left .
    {
        if (current_direction == 0)
        {
            draw_tank(3);
            current_direction = 3;
        }

        else if(current_direction == 1)
        {
            // SDL_RenderCopy(gRenderer, assets_down, &srcRect_tank_1_right , &moverRect_tank_1);
            draw_tank(2);
            current_direction = 2;
        }

        else if(current_direction == 2)
        {
            // SDL_RenderCopy(gRenderer, assets_down, &srcRect_tank_1_down , &moverRect_tank_1);
            draw_tank(0);
            current_direction = 0;
        }

        else if(current_direction == 3)
        {
            // SDL_RenderCopy(gRenderer, assets_down, &srcRect_tank_1_up , &moverRect_tank_1);
            draw_tank(1);
            current_direction = 1;
        }
    }

  void  Tank:: rotate_anticlockwise() // 0 means facing down , 1 mean facing up , 2 mean facing right , 3 mean facing left .
    {
        if (current_direction == 0)
        {
            // SDL_RenderCopy(gRenderer, assets_down, &srcRect_tank_1_right , &moverRect_tank_1);
            draw_tank(2);
            current_direction = 2;
        }

        else if(current_direction == 1)
        {
            // SDL_RenderCopy(gRenderer, assets_down, &srcRect_tank_1_left , &moverRect_tank_1);
            draw_tank(3);
            current_direction = 3;
        }

        else if(current_direction == 2)
        {
            // SDL_RenderCopy(gRenderer, assets_down, &srcRect_tank_1_up , &moverRect_tank_1);
            draw_tank(1);
            current_direction = 1;
        }

        else if(current_direction == 3)
        {
            // SDL_RenderCopy(gRenderer, assets_down, &srcRect_tank_1_down , &moverRect_tank_1);
            draw_tank(0);
            current_direction = 0;
        }
    }

Tank::Tank(int colour)
    {
        switch(colour) //2 for Grey // 1 for brown // 0 for blue.
        {
            case 0: // 0 for blue.
                moverRect_tank_1 = { 250 , 250 , 50,50} ;
                tank_up = {401,201,93,92};
                tank_down ={6,7,93,92} ;
                tank_left = {201,6,92,93};
                tank_right = {7,401,92,93} ;
                break;

            case 1: // 1 for brown 
                moverRect_tank_1 = { 250 , 250 , 50,50} ;
                tank_up = {289,203,92,90} ;
                tank_down = {119,7,92,90} ;
                tank_left = {203,119,90,92} ;
                tank_right = {7,289,90,92} ;

                break;

            case 2: //2 for Grey
                moverRect_tank_1 = { 250 , 250 , 50,50} ;
                tank_up = {176,202,94,92};
                tank_down ={230,6,94,92} ;
                tank_left = {202,230,92,94};
                tank_right = {60,176,92,94} ;

                break;

            case 3: // 3 for pink ;
                moverRect_tank_1 = { 750 , 250 , 50,50} ;
                tank_up = {401,79,95,93};
                tank_down ={4,128,95,93} ;
                tank_left = {79,4,93,95};
                tank_right = {128,401,93,95} ;

                break;

            case 4: // 4 for green ;
                moverRect_tank_1 = { 750 , 250 , 50,50} ;
                tank_up = {59,201,93,93};
                tank_down ={348,6,93,93} ;
                tank_left = {201,348,93,93};
                tank_right = {6,59,93,93} ;

                break;


            case 5: // 5 for purple;
                moverRect_tank_1 = { 750 , 250 , 50,50} ;
                tank_up = {287,79,94,92};
                tank_down ={119,129,94,92} ;
                tank_left = {79,119,92,94};
                tank_right = {129,287,92,94} ;

                break;

            // 5 for purple; // 4 for green ; // 3 for pink ;



        }

        
    }

Tank::~Tank()
{
    
}