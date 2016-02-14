#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include <stdio.h>
#include <string>
#include <iostream>
#include "Sprite/movingsprite.h"
#include "GameSetup/sdl_setup.h"
#include "Entity/entity.h"



class MainCharacter: public Entity
{
public:
    MainCharacter(SDL_setup *gameSetup, int width, int height, std::string playerName, std::string path);
    ~MainCharacter();




    void setOrigin(int X, int Y);
    void Draw();
    MovingSprite *getSprite();
    void setSprite(MovingSprite *value);
    void setCamera();
    void setInitFrame(int startFrame,int row);
    SDL_Rect getCamera();   
    bool GetMoving();
    void setIsMoving(bool value);

private:

    bool isMoving;

   MovingSprite * playerSprite;
//    std::string name;
//    CSprite* player;
//    SDL_setup *setup;




};

#endif // MAINCHARACTER_H
