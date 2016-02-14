#ifndef CAMERA_H
#define CAMERA_H
#include "Sprite/backgroundsprite.h"


class Camera
{
public:
    Camera();

    int getCameraX();
    void setCameraX(int value);

    int getCameraY();
    void setCameraY(int value);

    int getCameraW();
    void setCameraW(int value);

    int getCameraH();
    void setCameraH(int value);

    SDL_Rect getCamera() const;
    void setCamera(int x, int y, BackgroundSprite *stage);
private:
     SDL_Rect camera;


};

#endif // CAMERA_H
