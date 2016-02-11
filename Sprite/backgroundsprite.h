#ifndef BACKGROUNDSPRITE_H
#define BACKGROUNDSPRITE_H
#include "Sprite/isprite.h"


class BackgroundSprite : ISprite
{
public:
    BackgroundSprite(SDL_Renderer *gameRenderer, std::string path);
    virtual void accept(IVisitor* v);

    virtual SDL_Surface *getSurface() const;
    virtual void setSurface(SDL_Surface *value);

    virtual SDL_Texture *getImage() const;
    virtual void setImage(SDL_Texture *value);

    virtual SDL_Rect getRect() const;
    void setRect(const SDL_Rect &value);

    virtual SDL_Renderer *getRenderer() const;
    virtual void setRenderer(SDL_Renderer *value);

private:



};

#endif // BACKGROUNDSPRITE_H
