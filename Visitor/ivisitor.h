#ifndef VISITOR
#define VISITOR
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>

class BaseSprite;
class CSprite;

class IVisitor
{
public:
    virtual void visit(BaseSprite * sprite)= 0;
    virtual void visit(CSprite * sprite) = 0;
};

#endif // VISITOR

