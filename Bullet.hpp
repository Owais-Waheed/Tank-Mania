#pragma once
# include <SDL.h>
# include "Tank.hpp"

class Bullet
{
    SDL_Rect src_Rect_bullet_down;
    
    bool Collision;   //Status of Collision
    int current_direct;  //Direction and axis of assets
    friend class Tank;  


    public:

    SDL_Rect mover_rect_bullet;
    Bullet(SDL_Rect mover_rect , int current);

    ~Bullet();
    void draw();

    
    // fires the bullet in the direction of tank.
    // friend void Tank::fire(Bullet a);

    void fire(SDL_Keycode);
    void Reload();



};
