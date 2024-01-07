#pragma once
# include "Player1.hpp"

void Player1::moveTank(SDL_Keycode key)
{
// 0 means facing down , 1 mean facing up , 2 mean facing right , 3 mean facing left .
    if (key == SDLK_w)
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
    else if (key == SDLK_s) // 0 means facing down , 1 mean facing up , 2 mean facing right , 3 mean facing left .
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
    else if (key == SDLK_d)
	{
        rotate_clockwise();
    }
    else if (key == SDLK_a) 
	{
        rotate_anticlockwise();
    }
    else if (key == SDLK_KP_SPACE)
	{
        // std::cout<<"hello";
        //fire();
    }
    // update(gRenderer, assets);
}
