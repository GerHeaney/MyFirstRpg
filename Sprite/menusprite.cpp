#include "menusprite.h"

MenuSprite::MenuSprite(SDL_Renderer *gameRenderer, std::string path)
{
    renderer = gameRenderer;
    surface = IMG_Load(path.c_str());
    image = SDL_CreateTextureFromSurface(gameRenderer,surface);

        if(image == NULL)
        {
            std::cout << "Couldn't load " << path.c_str() << std::endl;

        }
        rect.x = 0;
        rect.y = 0;
        rect.w = surface->w;
        rect.h = surface->h;


        positionRect = {0,0,surface->w,surface->h};

}

MenuSprite::~MenuSprite()
{
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(image);
}

void MenuSprite::accept(IVisitor *v)
{
    v->visit(this);

}

SDL_Surface *MenuSprite::getSurface() const
{
    return surface;
}

void MenuSprite::setSurface(SDL_Surface *value)
{
    surface = value;
}

SDL_Texture *MenuSprite::getImage() const
{
    return image;
}

void MenuSprite::setImage(SDL_Texture *value)
{
    image = value;
}

SDL_Rect MenuSprite::getRect() const
{
    return rect;
}

void MenuSprite::setRect(const SDL_Rect &value)
{
    rect = value;
}

void MenuSprite::setPositionRect(int x, int y)
{

    positionRect.x = x;
    positionRect.y = y;
}

void MenuSprite::setInitFrame(int startFrame, int row)
{

}

SDL_Renderer *MenuSprite::getRenderer() const
{
    return renderer;
}

void MenuSprite::setRenderer(SDL_Renderer *value)
{
    renderer = value;
}

void MenuSprite::setPosition(int X, int Y)
{
    positionRect.x = X;
    positionRect.y = Y;
}

void MenuSprite::setSize(int x, int y, int w, int h)
{
    positionRect.x = x;
    positionRect.y = y;
    positionRect.w = w;
    positionRect.h = h;
}

SDL_Rect MenuSprite::getPositionRect()
{
    return positionRect;
}

