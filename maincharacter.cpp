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
    playerRect.w = surface->w;
    playerRect.h = surface->h;

    cameraX = 0;
    cameraY = 0;

   // player = new CSprite(setup->getRenderer(),"resources/belf.png",300,240,32,48);
    setupAnimation(4,4);
    setInitFrame(0,0);
    //setOrigin(getWidth()/2.0f,getHeight());

    //player->setInitFrame();

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

   // std:: cout << "camera.x is " << camera.x << std::endl;
    //Set rendering space and render to screen
    SDL_Rect renderQuad = {XPos- camera.x,YPos - camera.y,surface->w/4,surface->h/4 };
    SDL_RenderCopy( setup->getRenderer(), image, &playerRect, &renderQuad );
    //Promising line of thought
    //player->DrawBackground();
}
//void MainCharacter::render(int x, int y, SDL_Renderer* gRenderer )
//{



//        //Set rendering space and render to screen
//        SDL_Rect renderQuad = {x,y,32,48 };
//        SDL_RenderCopy( gRenderer, mTexture, &gSpriteClips[frame], &renderQuad );
//}
void MainCharacter::Move()      
{


   switch(setup->getMainEvent()->type)
   {
   case SDL_KEYDOWN:

       switch(setup->getMainEvent()->key.keysym.sym)
       {
         case SDLK_UP:
           MoveUp = true;
           isMoving = true;
           break;
          case SDLK_DOWN:
           MoveDown = true;
            isMoving = true;
           break;
          case SDLK_LEFT:
           MoveLeft = true;
            isMoving = true;
           break;
          case SDLK_RIGHT:
           MoveRight = true;
            isMoving = true;
           break;
          default:
              break;
       }



       break;
   case SDL_KEYUP:

   switch(setup->getMainEvent()->key.keysym.sym)
   {
     case SDLK_UP:
       playAnimation(0,0,3,120);
       MoveUp = false;
       isMoving = false;

       break;
      case SDLK_DOWN:
       playAnimation(0,0,0,120);
       MoveDown = false;
       isMoving = false;


       break;
      case SDLK_LEFT:
       playAnimation(0,0,1,120);
       MoveLeft = false;
       isMoving = false;


       break;
      case SDLK_RIGHT:
       playAnimation(0,0,2,120);
       MoveRight = false;
       isMoving = false;


       break;
      default:
          break;
   }
       break;
   default:
       break;
   }

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

void MainCharacter::setInitFrame(int startFrame,int row)
{
     playerRect.x = startFrame * (surface->w/frameX);
     playerRect.y = row *(surface->h/frameY);
     playerRect.w = surface->w/frameX;
     playerRect.h = surface->h/frameY;
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
void MainCharacter::setCamera(){
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
float MainCharacter::getX()
{
   return XPos;
}
float MainCharacter::getY()
{
    return YPos;
}
void MainCharacter::setOrigin(int X, int Y)
{
    xOrigin = X;
    yOrigin = Y;
    setPosition(getX(),getY());
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
    return camera;
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
