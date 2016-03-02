#include "movingsprite.h"

MovingSprite::MovingSprite(SDL_Renderer *gameRenderer, std::string path)
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
        rect.w = surface->w/4;
        rect.h = surface->h/4;

        positionRect = {0,0,surface->w/4,surface->h/4};

        currentFrame = 0;
        frameSpeed = 0;
        frameX = 4;
        frameY = 4;

}

MovingSprite::~MovingSprite()
{
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(image);
}
void MovingSprite::accept(IVisitor *v)
{
    v->visit(this);

}

SDL_Surface *MovingSprite::getSurface() const
{
    return surface;
}

void MovingSprite::setSurface(SDL_Surface *value)
{
    surface = value;
}

SDL_Texture *MovingSprite::getImage() const
{
    return image;
}

void MovingSprite::setImage(SDL_Texture *value)
{
    image = value;
}

SDL_Rect MovingSprite::getRect() const
{
    return rect;
}

void MovingSprite::setRect(const SDL_Rect &value)
{
    rect = value;
}

SDL_Renderer *MovingSprite::getRenderer() const
{
    return renderer;
}

void MovingSprite::setRenderer(SDL_Renderer *value)
{
    renderer = value;
}



int MovingSprite::getX() const
{
    return XPos;
}

void MovingSprite::setX(int value)
{
    XPos = value;
}

int MovingSprite::getY() const
{
    return YPos;
}

void MovingSprite::setY(int value)
{
    YPos = value;
}

SDL_Rect MovingSprite::getPositionRect()
{
    return positionRect;
}

void MovingSprite::setPositionRect(int x, int y)
{
    positionRect.x = x;
    positionRect.y = y;
}
void MovingSprite::setOrigin(int X, int Y)
{

    setPosition(getX(),getY());
}
void MovingSprite::setPosition(int X, int Y)
{
    XPos = X;
    YPos = Y;


}
void MovingSprite::setupAnimation(int passedX, int passedY)
{
    frameX = passedX;
    frameY = passedY;
}
void MovingSprite::setInitFrame(int startFrame,int row)
{
    rect.x = startFrame * (surface->w/frameX);
    rect.y = row *(surface->h/frameY);
    rect.w = surface->w/frameX;
    rect.h = surface->h/frameY;
}

void MovingSprite::playAnimation(int startFrame, int endFrame,int row, float speed)
{
    if(frameSpeed + speed < SDL_GetTicks())
    {

        if(endFrame  <= currentFrame)
        {
            currentFrame = startFrame;
        }
        else
        {
            currentFrame++;
        }

        rect.x =  currentFrame * (surface->w/frameX);
        rect.y = row *(surface->h/frameY);
        rect.w = surface->w/frameX;
        rect.h = surface->h/frameY;
        frameSpeed = SDL_GetTicks();

    }
}
