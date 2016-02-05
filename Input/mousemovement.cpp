#include "mousemovement.h"

MouseMovement::MouseMovement(SDL_setup *setup, MainCharacter *belf, float *passedX, float *passedY)
{
    gameSetup = setup;
    player = belf;
    cameraX = 0;
    cameraY = 0;

    pCamX = &cameraX;
    pCamY = &cameraY;
    mouseX = 0;
    mouseY = 0;
    timeCheck = SDL_GetTicks();
    follow = false;
    distance = 0;
    angle = 0;
    stopAnimation = false;

}

double MouseMovement::getDistance(int x1, int y1, int x2, int y2)
{
    double differenceX = x1 - x2;
    double differenceY = y1 - y2;
    double difference = sqrt((differenceX * differenceX)+(differenceY * differenceY));
    return difference;
}

int MouseMovement::getFollowPointX() const
{
    return followPointX;
}

void MouseMovement::setFollowPointX(int value)
{
    followPointX = value;
}

int MouseMovement::getFollowPointY() const
{
    return followPointY;
}

void MouseMovement::setFollowPointY(int value)
{
    followPointY = value;
}




void MouseMovement::Move()
{

  //  player->setCameraX(pCamX);
  //  player->setCameraY(pCamY);
    std::cout << *pCamX << std::endl;
    float radian = atan2(followPointY -cameraY,followPointX - cameraX);
    angle = (radian * (180/M_PI)) + 180;



    if(gameSetup->getMainEvent()->type == SDL_MOUSEBUTTONDOWN || gameSetup->getMainEvent()->type == SDL_MOUSEMOTION)
    {
        SDL_GetMouseState(&mouseX,&mouseY);

        if (gameSetup->getMainEvent()->button.button == SDL_BUTTON_LEFT)
        {
            followPointX = cameraX - mouseX + 300;
            followPointY = cameraY - mouseY + 240;
            follow = true;
        }
    }
    if(timeCheck +10 < SDL_GetTicks() && follow)
    {

        distance = getDistance(cameraX,cameraY,followPointX,followPointY);
        if(distance == 0)
        {
            stopAnimation = true;
        }
        else
        {
            stopAnimation = false;
        }

        if(distance > 15)
        {
            if(cameraX != followPointX)
            {
                cameraX = (cameraX -((cameraX - followPointX)/distance)*1.5f);
            }

            if(cameraY != followPointY)
            {
                cameraY =(cameraY -((cameraY - followPointY)/distance)*1.5f);
            }
          //  std::cout << angle << std::endl;

        }
        else
            follow = false;
        timeCheck = SDL_GetTicks();

    }
}

float MouseMovement::getAngle() const
{
    return angle;
}

void MouseMovement::setAngle(float value)
{
    angle = value;
}

int MouseMovement::getMouseX() const
{
    return mouseX;
}

void MouseMovement::setMouseX(int value)
{
    mouseX = value;
}

int MouseMovement::getMouseY() const
{
    return mouseY;
}

void MouseMovement::setMouseY(int value)
{
    mouseY = value;
}

