#pragma once
# include <SDL.h>
#include "drawing.hpp"
#include <cstring>
#include "Bullet.hpp"

class Tank
{
    protected:
    // SDL_Rect moverRect_tank_1  ;
    SDL_Rect tank_up  ;
    SDL_Rect tank_down  ;
    SDL_Rect tank_left ;
    SDL_Rect tank_right  ;
    // int current_direction ;
    int yJump = 10;
    int xJump = 10;

    // Bullet a;

    public:
    bool collison = false ;
    SDL_Rect moverRect_tank_1;
    int current_direction = 0 ;
    Tank(int colour) ;// 0 for blue ; 1 for brown ; 2 for Grey // player 2 3 for pink ; 4 for green ; 5 for purple



    // int yJump = 10;
    // int xJump = 10;

    // int current_direction = 0; // 0 means facing down , 1 mean facing up , 2 mean facing right , 3 mean facing left .

    virtual void moveTank(SDL_Keycode key) = 0;
    void draw_tank(int current_pos );
    void rotate_clockwise();
    void rotate_anticlockwise();
    void moveSouth();
    void moveNorth();
    void moveEast();
    void moveWest();

    ~Tank();

};

  