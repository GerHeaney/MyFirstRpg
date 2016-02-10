#include "Visitor/drawvisitor.h"
#include "RenderItems/csprite.h"
DrawVisitor::DrawVisitor()
{

}

void DrawVisitor::visit(BaseSprite *sprite)
{
    printf("Hello from base");

}

void DrawVisitor::visit(CSprite *sprite)
{
    sprite->Draw();

}
