#ifndef MOVINGSPRITE_H
#define MOVINGSPRITE_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "Sprite/isprite.h"

class MovingSprite: public ISprite
{
public:
    MovingSprite(SDL_Renderer *gameRenderer, std::string path);
    ~MovingSprite();
    virtual void accept(IVisitor* v);

    virtual SDL_Surface *getSurface() const;
    virtual void setSurface(SDL_Surface *value);

    virtual SDL_Texture *getImage() const;
    virtual void setImage(SDL_Texture *value);

    virtual SDL_Rect getRect() const;
    virtual void setRect(const SDL_Rect &value);

    virtual SDL_Renderer *getRenderer() const;
    virtual void setRenderer(SDL_Renderer *value);
    void setPosition(int X, int Y);
    void setOrigin(int X, int Y);
    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

    SDL_Rect getPositionRect() const;
    void setPositionRect(int x, int y);

    void setInitFrame(int startFrame,int row);
    void setupAnimation(int passedX, int passedY);
    void playAnimation(int startFrame, int endFrame,int row, float speed);

private:
    int XPos;
    int YPos;
    SDL_Rect  positionRect;
    int currentFrame;
    int frameSpeed;

    int frameX;
    int frameY;



};

#endif // MOVINGSPRITE_H
