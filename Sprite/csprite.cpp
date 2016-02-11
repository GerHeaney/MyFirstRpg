#include "csprite.h"

CSprite::CSprite(SDL_Renderer * gameRenderer, std::string path, int x, int y)
{

    renderer = gameRenderer;
    surface = IMG_Load(path.c_str());
    image = SDL_CreateTextureFromSurface(renderer,surface);

        if(image == NULL)
        {
            std::cout << "Couldn't load " << path.c_str() << std::endl;

        }
    rect.x = x;
    rect.y = y;
    rect.w = 0;
    rect.h = 0;


    crop.x = 0;
    crop.y = 0;
    crop.w = surface->w/4;
    crop.h = surface->h/4;

    XPos = x;
    YPos = y;

    xOrigin = 0;
    yOrigin = 0;

    currentFrame = 0;
    frameSpeed = 0;

    frameX = 4;
    frameY = 4;



    cameraW = surface->w;
    cameraH = surface->h;

    camera.x = rect.x;
    camera.y = rect.y;
    camera.w = 0;
    camera.h = 0;
    frameX = 0;
    frameY = 0;


}
void CSprite::accept(IVisitor *v)
{
    v->visit(this);
}

CSprite::~CSprite()
{



}

void CSprite::Draw()
{

    SDL_Rect renderQuad = {XPos- camera.x,YPos - camera.y,surface->w/4,surface->h/4 };

    SDL_RenderCopy( renderer, image, &crop, &renderQuad );

  //  SDL_RenderCopy(renderer,image,&crop,&crop);

}
void CSprite::DrawBackground(SDL_Rect * clip)
{
   // rect.x = XPos- camera.x;
//    rect.y = YPos- camera.y;

    SDL_Rect renderQuad = {0, 0,0,0};

    //Set clip rendering dimensions
    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;

    }
    SDL_RenderCopy(renderer,image,clip,&renderQuad);

}

void CSprite::setX(int X)
{
    XPos = X;
     camera.x = (XPos - xOrigin);

}
void CSprite::setY(int Y)
{
    YPos = Y;
     camera.y = (YPos - yOrigin);

}
void CSprite::setPosition(int X, int Y)
{
    XPos = X;
    camera.x = (XPos - xOrigin);


    YPos = Y;
    camera.y = (YPos - yOrigin);

}
int CSprite::getX()
{
   return XPos;
}
int CSprite::getY()
{
    return YPos;
}
void CSprite::setOrigin(int X, int Y)
{
    xOrigin = X;
    yOrigin = Y;
    setPosition(getX(),getY());
}

int CSprite::getWidth()
{
    return surface->w;
}

void CSprite::setWidth(int value)
{
    cameraW = value;

}

void CSprite::setSpriteSize(int W, int H)
{

}

int CSprite::getHeight()
{
    return surface->h;
}

int CSprite::getCropWidth()
{
    return crop.w;
}



int CSprite::getCropHeight()
{
    return crop.h;
}
void CSprite::setHeight(int value)
{
    cameraH = value;
}
void CSprite::setInitFrame(int startFrame,int row)
{
    crop.x = startFrame * (surface->w/frameX);
    crop.y = row *(surface->h/frameY);
    crop.w = surface->w/frameX;
    crop.h = surface->h/frameY;
}

void CSprite::playAnimation(int startFrame, int endFrame,int row, float speed)
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

        crop.x =  currentFrame * (surface->w/frameX);
        crop.y = row *(surface->h/frameY);
        crop.w = surface->w/frameX;
        crop.h = surface->h/frameY;
        frameSpeed = SDL_GetTicks();
    }
}

int CSprite::getCameraX()
{
    return camera.x;
}

void CSprite::setCameraX(int value)
{
    camera.x = value;

}

int CSprite::getCameraY()
{
    return camera.y;
}

void CSprite::setCameraY(int value)
{

    camera.y = value;

}

int CSprite::getCameraW()
{
    return camera.w;
}

void CSprite::setCameraW(int value)
{
    rect.w = value;
    camera.w = value;
}

int CSprite::getCameraH()
{
    return camera.h;
}


void CSprite::setCameraH(int value)
{
    rect.h = value;
    camera.h = value;
}

SDL_Rect CSprite::getCamera() const
{
    return camera;
}
void CSprite::setupAnimation(int passedX, int passedY)
{
    frameX = passedX;
    frameY = passedY;
}
void CSprite::setCamera(){
    camera.x = int( XPos + 32 / 2  - camera.w / 2);
    camera.y = int( YPos + 48 / 2  - camera.h / 2) ;





    if( camera.x < 0 )
                {
                    camera.x = 0;
                }
                if( camera.y < 0 )
                {
                    camera.y = 0;
                }
                if( camera.x > cameraW - camera.w )
                {                   
                    camera.x = cameraW - camera.w;
                }
                if( camera.y > cameraH - camera.h )
                {
                    camera.y = cameraH - camera.h;
                }

}
