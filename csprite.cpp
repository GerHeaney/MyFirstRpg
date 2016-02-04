#include "csprite.h"

CSprite::CSprite(SDL_Renderer * gameRenderer, std::string path, int x, int y, int w, int h)
{

    renderer = gameRenderer;
    image = NULL;

    surface = IMG_Load(path.c_str());
    image = SDL_CreateTextureFromSurface(renderer,surface);

        if(image == NULL)
        {
            std::cout << "Couldn't load " << path.c_str() << std::endl;

        }
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;


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



    cameraW = w;
    cameraH = h;

    camera.x = rect.x;
    camera.y = rect.y;
    camera.w = 1200;
    camera.h = 900;
    frameX = 0;
    frameY = 0;


}
//CSprite::CSprite(SDL_Renderer * gameRenderer, std::string path,int x, int y)
//{

//    renderer = gameRenderer;
//    image = NULL;

//    SDL_Surface * surface = IMG_Load(path.c_str());
//    image = SDL_CreateTextureFromSurface(renderer,surface);

//        if(image == NULL)
//        {
//            std::cout << "Couldn't load " << path.c_str() << std::endl;

//        }
//    rect.x = x;
//    rect.y = y;
//    rect.w = surface->w;
//    rect.h = surface->h;



//}

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

    SDL_Rect renderQuad = {XPos- camera.x, YPos - camera.y, 0, 0 };

    //Set clip rendering dimensions
    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    SDL_RenderCopy(renderer,image,clip,&rect);
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

int CSprite::getHeight()
{
    return surface->h;
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
    camera.x = int(( XPos + 32 / 2 ) - camera.w / 2);
    camera.y = int(( YPos + 48 / 2 ) - camera.h / 2) ;



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
                std::cout << "level width is " << cameraW << std::endl;
                std::cout << "camera width is " << camera.w << std::endl;
}
