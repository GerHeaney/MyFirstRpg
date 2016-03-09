#ifndef MENUSPRITE_H
#define MENUSPRITE_H
#include "Sprite/isprite.h"

class MenuSprite : public ISprite
{
public:

    MenuSprite(SDL_Renderer *gameRenderer, std::string path);
    ~MenuSprite();
    virtual void accept(IVisitor* v);

    virtual SDL_Surface *getSurface() const;
    virtual void setSurface(SDL_Surface *value);

    virtual SDL_Texture *getImage() const;
    virtual void setImage(SDL_Texture *value);

    virtual SDL_Rect getRect() const;
    void setRect(const SDL_Rect &value);
    void setPositionRect(int x, int y);

    void setInitFrame(int startFrame,int row);

    virtual SDL_Renderer *getRenderer() const;
    virtual void setRenderer(SDL_Renderer *value);
    virtual void setPosition(int X, int Y);
    void setSize(int x,int y,int w, int h);
    SDL_Rect getPositionRect();

private:
    SDL_Rect positionRect;



};

#endif // MENUSPRITE_H
