#pragma once
# include "Tank.hpp"


class Player1 : public Tank 
{
    public:

    Player1(int color):Tank(color) // 0 for blue ; 1 for brown ; 2 for Grey // player 2 0 for pink ; 1 for green ; 2 for purple
    {
        
    };

    void moveTank(SDL_Keycode key);


};
