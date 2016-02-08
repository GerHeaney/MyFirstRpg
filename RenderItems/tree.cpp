#include "tree.h"

Tree::Tree(SDL_setup *setup, int x, int y)
{
    tree = new CSprite(setup->getRenderer(),"resources/tree.png",x,y,64,128);
}
void Tree::Draw(SDL_Rect * passedCamera)
{
    tree->Draw();
}

