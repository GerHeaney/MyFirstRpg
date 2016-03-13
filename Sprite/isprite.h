#ifndef BASESPRITE_H
#define BASESPRITE_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "Visitor/ivisitor.h"
#include "GameSetup/sdl_setup.h"



class ISprite
{
public:
    virtual ~ISprite() {}
    virtual void accept(IVisitor* v)= 0;

    virtual SDL_Surface *getSurface() const =0;
    virtual void setSurface(SDL_Surface *value)= 0;

    virtual SDL_Texture *getImage() const = 0;
    virtual void setImage(SDL_Texture *value) = 0;

    virtual SDL_Rect getRect() const = 0;
    virtual void setRect(const SDL_Rect &value) = 0;

    virtual SDL_Renderer *getRenderer() const = 0;
    virtual void setRenderer(SDL_Renderer *value) = 0;
    virtual void setPosition(int X, int Y) = 0;
    virtual void setPositionRect(int x, int y) = 0;
    virtual SDL_Rect getPositionRect() = 0;

    virtual void setInitFrame(int startFrame,int row) = 0;

protected:
    SDL_Surface * surface;
    SDL_Texture * image;
    SDL_Rect rect;
    SDL_Renderer *renderer;
};

#endif // BASESPRITE_H
