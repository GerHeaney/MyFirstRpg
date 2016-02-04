#ifndef TREE_H
#define TREE_H
#include "sdl_setup.h"
#include "csprite.h"

class Tree
{
public:
    Tree(SDL_setup *setup, int x, int y);

    void Draw(SDL_Rect *passedCamera);
private:
    CSprite * tree;
};

#endif // TREE_H
