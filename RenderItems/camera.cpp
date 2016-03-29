#include "camera.h"

Camera::Camera()
{
    camera = {0,0,0,0};

}

Camera::~Camera()
{

}

int Camera::getCameraX()
{
    return camera.x;
}

void Camera::setCameraX(int value)
{
    camera.x = value;
}

int Camera::getCameraY()
{
    return camera.y;
}

void Camera::setCameraY(int value)
{
    camera.y = value;
}

int Camera::getCameraW()
{
    return camera.w;
}

void Camera::setCameraW(int value)
{
    camera.w = value;
}

int Camera::getCameraH()
{
    return camera.h;
}

void Camera::setCameraH(int value)
{
    camera.h = value;
}


SDL_Rect Camera::getCamera() const
{
    return camera;
}

void Camera::setCamera(int x, int y, BackgroundSprite *stage)
{
    camera.x = int( x + 32 / 2  - camera.w / 2);
    camera.y = int( y + 48 / 2  - camera.h / 2) ;
//    std::cout <<"camera x is " << camera.x << std::endl;
//    std::cout <<"camera y is " << camera.y << std::endl;





    if( camera.x < 0 )
                {
                    camera.x = 0;
                }
                if( camera.y < 0 )
                {
                    camera.y = 0;
                }
                if( camera.x > stage->getSurface()->w - camera.w )
                {
                    std::cout <<"camera x is greater than the amount and is " << camera.x <<std::endl;
                    camera.x = stage->getSurface()->w - camera.w;
                     std::cout <<"camera x is greater than the amount and is now " << camera.x <<std::endl;
                }
                if( camera.y > stage->getSurface()->h - camera.h )
                {
                    camera.y = stage->getSurface()->h - camera.h;
                }
}

