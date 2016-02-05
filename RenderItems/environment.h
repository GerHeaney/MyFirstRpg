#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include "GameSetup/sdl_setup.h"
#include "RenderItems/csprite.h"
#include "RenderItems/tree.h"
#include <vector>


class Environment
{
public:
    Environment(SDL_setup *setup, int screenWidth, int screenHeight);
    ~Environment();
    void DrawBack(SDL_Rect * passedCamera);
    void DrawFront(SDL_Rect * passedCamera);
    void Update();
    int getLevelWidth();
    int getLevelHeight();

private:

    CSprite* grass;
    Tree* tree;
    std::vector<Tree*> trees;
};

#endif // ENVIRONMENT_H
