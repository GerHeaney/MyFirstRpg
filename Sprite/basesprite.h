#ifndef BASESPRITE_H
#define BASESPRITE_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "Visitor/ivisitor.h"



class BaseSprite
{
public:
    virtual void accept(class IVisitor*)= 0;


};

#endif // BASESPRITE_H
