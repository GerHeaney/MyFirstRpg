#include "Sprite/backgroundsprite.h"

BackgroundSprite::BackgroundSprite(SDL_Renderer *gameRenderer, std::string path)
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


}

BackgroundSprite::~BackgroundSprite()
{

}

void BackgroundSprite::accept(IVisitor *v)
{
    v->visit(this);

}

SDL_Surface *BackgroundSprite::getSurface() const
{
    return surface;
}

void BackgroundSprite::setSurface(SDL_Surface *value)
{
    surface = value;
}

SDL_Texture *BackgroundSprite::getImage() const
{
    return image;
}

void BackgroundSprite::setImage(SDL_Texture *value)
{
    image = value;
}

SDL_Rect BackgroundSprite::getRect() const
{
    return rect;
}

void BackgroundSprite::setRect(const SDL_Rect &value)
{
    rect = value;
}

SDL_Renderer *BackgroundSprite::getRenderer() const
{
    return renderer;
}

void BackgroundSprite::setRenderer(SDL_Renderer *value)
{
    renderer = value;
}

void BackgroundSprite::setPosition(int X, int Y)
{

}

void BackgroundSprite::setSize(int w, int h)
{

    rect.w = w;
    rect.h = h;
}

