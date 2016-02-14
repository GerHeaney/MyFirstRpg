#include "enemysprite.h"

EnemySprite::EnemySprite(SDL_Renderer *gameRenderer, std::string path)
{

    renderer = gameRenderer;
    surface = IMG_Load(path.c_str());
    image = SDL_CreateTextureFromSurface(renderer,surface);

        if(image == NULL)
        {
            std::cout << "Couldn't load " << path.c_str() << std::endl;

        }
        rect.x = 0;
        rect.y = 0;
        rect.w = surface->w;
        rect.h = surface->h;

        posRect = {0,0,surface->w,surface->h};

}


void EnemySprite::accept(IVisitor *v)
{
    v->visit(this);

}

SDL_Surface *EnemySprite::getSurface() const
{
    return surface;
}

void EnemySprite::setSurface(SDL_Surface *value)
{
    surface = value;
}

SDL_Texture *EnemySprite::getImage() const
{
    return image;
}

void EnemySprite::setImage(SDL_Texture *value)
{
    image = value;
}

SDL_Rect EnemySprite::getRect() const
{
    std::cout << "get enemt sprite x and y location is " << rect.x << " and " << rect.y << std::endl;

    return rect;
}

void EnemySprite::setRect(const SDL_Rect &value)
{
    rect = value;
}

SDL_Renderer *EnemySprite::getRenderer() const
{
    return renderer;
}

void EnemySprite::setRenderer(SDL_Renderer *value)
{
    renderer = value;
}

void EnemySprite::setPosition(int x, int y)
{
    posRect.x = x;
    posRect.y = y;

}

SDL_Rect EnemySprite::getPosRect() const
{
    return posRect;
}

