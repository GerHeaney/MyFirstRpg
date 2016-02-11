#include "Visitor/drawvisitor.h"
#include "Sprite/csprite.h"
#include "Sprite/backgroundsprite.h"

DrawVisitor::DrawVisitor()
{

}

void DrawVisitor::visit(ISprite *sprite)
{
    printf("Hello from base");

}

void DrawVisitor::visit(CSprite *sprite)
{

}

void DrawVisitor::visit(BackgroundSprite *sprite)
{
     SDL_Rect rect = sprite->getRect();
    SDL_RenderCopy(sprite->getRenderer(),sprite->getImage(),&rect,&rect);

}
