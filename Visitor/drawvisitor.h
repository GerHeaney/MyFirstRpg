#ifndef DRAWVISITOR_H
#define DRAWVISITOR_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "Visitor/ivisitor.h"

class DrawVisitor : public IVisitor
{
public:
    DrawVisitor();
    void visit(BaseSprite * sprite);
    void visit(CSprite * sprite);

};

#endif // DRAWVISITOR_H
