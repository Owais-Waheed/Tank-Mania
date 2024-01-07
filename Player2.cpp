#pragma once
# include "Player2.hpp"
# include <iostream>

void Player2::moveTank(SDL_Keycode key)
{
// 0 means facing down , 1 mean facing up , 2 mean facing right , 3 mean facing left .
    if (key == SDLK_UP)
	{
        if (current_direction == 0)
		{
			moveSouth();
		}

		else if(current_direction == 1)
		{
			moveNorth();
		}

		else if(current_direction == 2)
		{
			moveEast();
		}

		else if(current_direction == 3)
		{
			moveWest();
		}
    }
    else if (key == SDLK_DOWN) // 0 means facing down , 1 mean facing up , 2 mean facing right , 3 mean facing left .
	{
        if (current_direction == 0)
		{
			moveNorth();
		}

		else if(current_direction == 1)
		{
			moveSouth();
		}

		else if(current_direction == 2)
		{
			moveWest();
		}

		else if(current_direction == 3)
		{
			moveEast();
		}
    }
    else if (key == SDLK_RIGHT)
	{
        rotate_clockwise();
    }
    else if (key == SDLK_LEFT) 
	{
        rotate_anticlockwise();
    }
    else if (key == SDLK_KP_ENTER)
	{
        std::cout<<"inside move tank";
        //fire();
    }
    // update(gRenderer, assets);
}
