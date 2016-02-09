#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include <stdio.h>
#include <string>
#include <iostream>
#include "RenderItems/csprite.h"
#include "GameSetup/sdl_setup.h"
#include "Entity/entity.h"



class MainCharacter: public Entity
{
public:
    MainCharacter(SDL_setup *gameSetup, int width, int height, std::string playerName, std::string path);
    ~MainCharacter();




    void setOrigin(int X, int Y);
    void Draw();
    CSprite *getPlayer();
    void setPlayer(CSprite *value);
    void setCamera();
    void setInitFrame(int startFrame,int row);
    SDL_Rect getCamera();   
    bool GetMoving();
    void setIsMoving(bool value);

private:

    bool isMoving;
//    std::string name;
//    CSprite* player;
//    SDL_setup *setup;




};

#endif // MAINCHARACTER_H
