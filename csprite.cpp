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
    crop.w = surface->w;
    crop.h = surface->h;

    XPos = x;
    YPos = y;

    xOrigin = 0;
    yOrigin = 0;

    currentFrame = 0;
    //frameSpeed = 0;

    frameX = 0;
    frameY = 0;



    cameraW = w;
    cameraH = h;

    camera.x = rect.x ;
    camera.y = rect.y;
    camera.w = surface->w;
    camera.h = surface->h;


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


    SDL_RenderCopy(renderer,image,&crop,&rect);

}
void CSprite::DrawBackground(SDL_Rect * clip)
{
    SDL_Rect renderQuad = { 0, 0, 0, 0 };

    //Set clip rendering dimensions
    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    SDL_RenderCopy(renderer,image,clip,&renderQuad);
}

void CSprite::setX(float X)
{
    XPos = X;
    rect.x = int(XPos - xOrigin);
}
void CSprite::setY(float Y)
{
    YPos = Y;
    rect.y = int(YPos - yOrigin);
}
void CSprite::setPosition(float X, float Y)
{
    XPos = X;
    rect.x = int(XPos - xOrigin);

    YPos = Y;
    rect.y = int(YPos - yOrigin);
}
float CSprite::getX()
{
   return XPos;
}
float CSprite::getY()
{
    return YPos;
}
void CSprite::setOrigin(float X, float Y)
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
    rect.w = value;
}

int CSprite::getHeight()
{
    return surface->h;
}

void CSprite::setHeight(int value)
{
    rect.h = value;
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

//float *CSprite::getCameraX()
//{
//    return cameraX;
//}

//void CSprite::setCameraX(float* value)
//{
//    cameraX = value;





//}

//float *CSprite::getCameraY()
//{
//    return cameraY;
//}

//void CSprite::setCameraY(float *value)
//{

//    cameraY = value;
//    camera.y = rect.y + *cameraY ;

//}
void CSprite::setupAnimation(int passedX, int passedY)
{
    frameX = passedX;
    frameY = passedY;
}
void CSprite::setCamera(){
    camera.x = int(( XPos + 32 / 2 ) - cameraW / 2);
    camera.y = int(( YPos + 48 / 2 ) - cameraH / 2) ;



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
