#ifndef GAMERENDERER_H
#define GAMERENDERER_H

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include "RenderItems/csprite.h"
#include "GameSetup/sdl_setup.h"


class GameRenderer
{
public:
    GameRenderer();

private:
    std::vector<CSprite*> renderobjects;
};

#endif // GAMERENDERER_H
