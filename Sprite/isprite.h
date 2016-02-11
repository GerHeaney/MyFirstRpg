#ifndef BASESPRITE_H
#define BASESPRITE_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "Visitor/ivisitor.h"



class ISprite
{
public:
    virtual void accept(IVisitor* v)= 0;

    SDL_Surface *getSurface() const;
    void setSurface(SDL_Surface *value);

    SDL_Texture *getImage() const;
    void setImage(SDL_Texture *value);

    SDL_Rect getRect() const;
    void setRect(const SDL_Rect &value);

    SDL_Renderer *getRenderer() const;
    void setRenderer(SDL_Renderer *value);

protected:
    SDL_Surface * surface;
    SDL_Texture * image;
    SDL_Rect rect;
    SDL_Renderer *renderer;
};

#endif // BASESPRITE_H
