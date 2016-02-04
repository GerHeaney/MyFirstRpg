#include "maincharacter.h"

MainCharacter::MainCharacter(SDL_setup * gameSetup,int width,int height, int levelW, int levelH)
{

    setup = gameSetup;
   camera = {0,0,width,height};

    screenWidth = 1024;
    screenHeight = 1024;
    levelWidth = levelW;
    levelHeight = levelH;

    MoveRight = false;
    MoveLeft = false;
    MoveUp = false;
    MoveDown = false;
    isMoving = false;

    timeCheck = SDL_GetTicks();
    currentFrame = 0;
    //frameSpeed = 0;

    frameX = 0;
    frameY = 0;
   // renderer = gameRenderer;
    image = NULL;
    XPos = 0;
    YPos = 0;
    xOrigin = 0;
    yOrigin = 0;

    surface = IMG_Load("resources/belf.png");
    image = SDL_CreateTextureFromSurface(setup->getRenderer(),surface);

        if(image == NULL)
        {
            std::cout << "Couldn't load " << "path.c_str()" << std::endl;

        }
    playerRect.x = 0;
    playerRect.y = 0;
    playerRect.w = surface->w/4;
    playerRect.h = surface->h/4;

    cameraX = 0;
    cameraY = 0;

   // player = new CSprite(setup->getRenderer(),"resources/belf.png",300,240,32,48);

    //setOrigin(getWidth()/2.0f,getHeight());

    //player->setInitFrame();
    //move = new KeyboardMovement();
    player = new CSprite(setup->getRenderer(),"resources/belf.png",XPos,YPos,levelW,levelH);
    std::cout << "new sprite created" << std::endl;
    player->setupAnimation(4,4);
    player->setX(5);




}
MainCharacter::~MainCharacter()
{
    delete player;

}

CSprite *MainCharacter::getPlayer()
{
    return player;
}

void MainCharacter::setPlayer(CSprite *value)
{
    player = value;
}
void MainCharacter::Draw()
{

    player->Draw();
    /*
     Movement was originally in the player class but this is incorrect The player should not
     need to know about the camera or the level height. Separation of concerns is a major factor
     in OO design and this was necessary to rework the code

    std:: cout << "camera.x is " << camera.x << std::endl;
    Set rendering space and render to screen
    SDL_Rect renderQuad = {XPos- camera.x,YPos - camera.y,surface->w/4,surface->h/4 };
    SDL_RenderCopy( setup->getRenderer(), image, &playerRect, &renderQuad );
    Promising line of thought
    player->DrawBackground();
    */
}
void MainCharacter::setInitFrame(int startFrame,int row)
{
  player->setInitFrame(startFrame,row);
}
//void MainCharacter::render(int x, int y, SDL_Renderer* gRenderer )
//{



//        //Set rendering space and render to screen
//        SDL_Rect renderQuad = {x,y,32,48 };
//        SDL_RenderCopy( gRenderer, mTexture, &gSpriteClips[frame], &renderQuad );
//}
/*
   if(timeCheck +10 < SDL_GetTicks())
   {

       if(MoveLeft)
       {
           playAnimation(0,3,1,120);
           if(XPos <=0) {XPos == 0;}
           else{ XPos -=2;}
           //player->setX(x);
       }
       if(MoveRight)
       {
           playAnimation(0,3,2,120);
           if(XPos + playerRect.w >=levelWidth ) {XPos == levelWidth;}
           else{ XPos +=2;}
           //player->setX(x);
       }
       if(MoveDown)
       {
           playAnimation(0,3,0,120);
           if(YPos + playerRect.h >=levelHeight){YPos ==levelHeight;}
           else{YPos +=2;}
          ;
           //player->setY(y);
       }
       if(MoveUp)
       {
           playAnimation(0,3,3,120);
           if(YPos <=0){YPos ==0;}
           else{YPos -=2;}
           //player->setY(y);
       }
       timeCheck = SDL_GetTicks();
   }

}



void MainCharacter::playAnimation(int startFrame, int endFrame,int row, float speed)
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
         playerRect.x =  currentFrame * (surface->w/frameX);
         playerRect.y = row *(surface->h/frameY);
         playerRect.w = surface->w/frameX;
         playerRect.h = surface->h/frameY;
        frameSpeed = SDL_GetTicks();
    }
}
void MainCharacter::setupAnimation(int passedX, int passedY)
{
    frameX = passedX;
    frameY = passedY;
}
*/
void MainCharacter::setCamera(){
    player->setCamera();

    camera.x = ( XPos + 32 / 2 ) - camera.w / 2;
    camera.y = ( YPos + 48 / 2 ) - camera.h / 2 ;



    if( camera.x < 0 )
                {
                    camera.x = 0;
                }
                if( camera.y < 0 )
                {
                    camera.y = 0;
                }
                if( camera.x > levelWidth - camera.w )
                {
                    camera.x = levelWidth - camera.w;
                }
                if( camera.y > levelHeight - camera.h )
                {
                    camera.y = levelHeight - camera.h;
                }

}

void MainCharacter::setX(int X)
{
    XPos = X;
    camera.x = (XPos - xOrigin);
}
void MainCharacter::setY(int Y)
{
    YPos = Y;
    camera.y = (YPos - yOrigin);
}
void MainCharacter::setPosition(int X, int Y)
{
    XPos = X;
    camera.x = (XPos - xOrigin);

    YPos = Y;
    camera.y = (YPos - yOrigin);
}
int MainCharacter::getX()
{
   return XPos;
}
int MainCharacter::getY()
{
    return YPos;
}
void MainCharacter::setOrigin(int X, int Y)
{
//    xOrigin = X;
//    yOrigin = Y;
//    std::cout << "X and Y are " << X <<" " << Y << std::endl;
//    setPosition(getX(),getY());
   player->setOrigin(X,Y);
}

int MainCharacter::getWidth()
{
    return playerRect.w;
}

void MainCharacter::setWidth(int value)
{
    playerRect.w = value;
}

int MainCharacter::getHeight()
{
    return playerRect.h;
}

void MainCharacter::setHeight(int value)
{
    playerRect.h = value;
}
SDL_Rect MainCharacter::getCamera()
{
    return player->getCamera();
}
int MainCharacter::getCameraX()
{
    return camera.x;
}
int MainCharacter::getCameraY()
{
    return camera.y;
}

bool MainCharacter::GetMoving()
{
    if (isMoving == true)
    {
        return true;
    }
    return false;
}

void MainCharacter::setIsMoving(bool value)
{
    isMoving = value;
}
