# include "Bullet.hpp"

Bullet::Bullet(SDL_Rect mover_rect , int current_position)  //Default CONSTRUCTOR taking position of tank.
{
    src_Rect_bullet_down = {270,168,15,15};
    mover_rect_bullet = mover_rect;
    mover_rect_bullet.x += 15;
    mover_rect_bullet.y += 15;
    mover_rect_bullet.w = 20;
    mover_rect_bullet.h = 20;
    current_direct = current_position;
    Collision = false;
}

void Bullet::draw()   //Rendering Bullet on the Screen
{
    SDL_RenderCopy(Drawing::gRenderer , Drawing:: assets_down , &src_Rect_bullet_down , &mover_rect_bullet);

    //Moving Bullet according to the axis of the Tank.
    
    if(current_direct == 0) // 0 means facing down , 1 mean facing up , 2 mean facing right , 3 mean facing left .
    {
        mover_rect_bullet.y += 30;
    }
    else if(current_direct == 1)
    {
        mover_rect_bullet.y -= 30;
    }
    else if(current_direct == 2)
    {
        mover_rect_bullet.x += 30;
    }

    else if(current_direct == 3)
    {
        mover_rect_bullet.x -= 30;
    }
}

// void Bullet::fire()




// void Tank::fire(Bullet a) 
// {
//     SDL_RenderCopy(Drawing::gRenderer , Drawing::assets_down , &a.src_Rect_bullet_down , &a.mover_rect_bullet);
// }