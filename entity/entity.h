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
    Entity();

protected:
    bool isMoving;
    std::string name;
    CSprite* player;
    SDL_setup *setup;

};

#endif // ENTITY_H
