#include "Visitor/drawvisitor.h"
#include "Sprite/csprite.h"
#include "Sprite/backgroundsprite.h"
#include "Sprite/movingsprite.h"
#include "Sprite/enemysprite.h"
#include "Sprite/menusprite.h"

DrawVisitor::DrawVisitor()
{

}

DrawVisitor::~DrawVisitor()
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
    SDL_Rect srcRect = sprite->getRect();
    SDL_Rect dstRect = {0,0,srcRect.w,srcRect.h};
    SDL_RenderCopy(sprite->getRenderer(),sprite->getImage(),&srcRect,&dstRect);

}
void DrawVisitor::visit(MovingSprite *sprite)
{
    SDL_Rect posRect = sprite->getPositionRect();
    SDL_Rect srcRect = sprite->getRect();

    SDL_RenderCopy(sprite->getRenderer(),sprite->getImage(),&srcRect,&posRect);

}

void DrawVisitor::visit(EnemySprite *sprite)
{
    SDL_Rect posRect = sprite->getPosRect();
    SDL_Rect srcRect = sprite->getRect();
    SDL_Rect dstRect = {0,0,srcRect.w,srcRect.h};
    SDL_RenderCopy(sprite->getRenderer(),sprite->getImage(),&srcRect,&posRect);



}

void DrawVisitor::visit(MenuSprite *sprite)
{
    SDL_Rect srcRect = sprite->getRect();
    SDL_Rect posRect = sprite->getPosRect();

    SDL_RenderCopy(sprite->getRenderer(),sprite->getImage(),&srcRect,&posRect);

}
