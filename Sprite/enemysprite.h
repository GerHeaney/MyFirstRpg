#ifndef ENEMYSPRITE_H
#define ENEMYSPRITE_H
#include "Sprite/isprite.h"

class EnemySprite : public ISprite
{
public:
    EnemySprite(SDL_Renderer *gameRenderer, std::string path);
    ~EnemySprite();
    virtual void accept(IVisitor* v);

    virtual SDL_Surface *getSurface() const;
    virtual void setSurface(SDL_Surface *value);

    virtual SDL_Texture *getImage() const;
    virtual void setImage(SDL_Texture *value);
    virtual SDL_Rect getRect() const;


    virtual void setRect(const SDL_Rect &value);

    virtual SDL_Renderer *getRenderer() const;
    virtual void setRenderer(SDL_Renderer *value);
    virtual void setPosition(int x, int y);
    SDL_Rect getPosRect() const;

private:

    SDL_Rect posRect;




};

#endif // ENEMYSPRITE_H
