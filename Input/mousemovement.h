#ifndef MOUSEMOVEMENT_H
#define MOUSEMOVEMENT_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <math.h>
#include "Entity/maincharacter.h"
#include "GameSetup/sdl_setup.h"

class MouseMovement
        {
public:

    MouseMovement(SDL_setup *setup,MainCharacter *belf);
    ~MouseMovement();

    double getDistance(int x1,int y1,int x2,int y2);

    int getFollowPointX() const;
    void setFollowPointX(int value);

    int getFollowPointY() const;
    void setFollowPointY(int value);
    void Move();

    float getAngle() const;
    void setAngle(float value);

    int getMouseX() const;
    void setMouseX(int value);

    int getMouseY() const;
    void setMouseY(int value);





private:

    MainCharacter * player;

    SDL_setup *gameSetup;

     float * pCamX;
     float * pCamY;

    float cameraX;
    float cameraY;
    int mouseX;
    int mouseY;
    int timeCheck;

    bool follow;
    int followPointX;
    int followPointY;
    float distance;
    float angle;
    bool stopAnimation;

};

#endif // MOUSEMOVEMENT_H
