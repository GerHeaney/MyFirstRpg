#ifndef VISITOR
#define VISITOR
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>

class ISprite;
class CSprite;
class BackgroundSprite;
class MovingSprite;
class EnemySprite;
class MenuSprite;

class IVisitor
{
public:
    virtual void visit(ISprite * sprite)= 0;
    virtual void visit(CSprite * sprite) = 0;
    virtual void visit(BackgroundSprite * sprite) = 0;
    virtual void visit(MovingSprite * sprite) = 0;
    virtual void visit(EnemySprite * sprite) = 0;
    virtual void visit(MenuSprite * sprite) = 0;
};

#endif // VISITOR

