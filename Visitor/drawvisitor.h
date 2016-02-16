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
    ~DrawVisitor();
    void visit(ISprite * sprite);
    void visit(CSprite * sprite);
    void visit(BackgroundSprite * sprite);
    void visit(MovingSprite * sprite);
    void visit(EnemySprite * sprite);
    void visit(MenuSprite * sprite);

};

#endif // DRAWVISITOR_H
