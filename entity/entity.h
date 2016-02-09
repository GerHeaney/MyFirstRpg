#ifndef ENTITY_H
#define ENTITY_H

#include <stdio.h>
#include <string>
#include <iostream>
#include "RenderItems/csprite.h"
#include "GameSetup/sdl_setup.h"


class Entity
{
public:

    void setOrigin(int X, int Y);
    void Draw();
    void DrawBackground(SDL_Rect * camera);
    CSprite *getPlayer();
    void setPlayer(CSprite *value);
    void setCamera();
    void setInitFrame(int startFrame,int row);
    SDL_Rect getCamera();
    bool GetMoving();
    void setIsMoving(bool value);
    Entity(SDL_setup * gameSetup, int width, int height, std::string name, std::string path);

protected:
    bool isMoving;
    std::string name;
    CSprite* player;
    SDL_setup *setup;

};

#endif // ENTITY_H
