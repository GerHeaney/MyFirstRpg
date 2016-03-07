#include "keyboardmovement.h"

KeyboardMovement::KeyboardMovement(SDL_setup * passedSetup, Entity *passedPlayer, int width, int height)
{


    player = (MainCharacter*)passedPlayer;
    MoveRight = false;
    MoveLeft = false;
    MoveUp = false;
    MoveDown = false;
    levelHeight = height;
    levelWidth = width;

    timeCheck = SDL_GetTicks();




}

KeyboardMovement::~KeyboardMovement()
{
//    delete player;
//    delete setup;

}

void KeyboardMovement::Move(SDL_setup * setup)
{
    x = player->getSprite()->getX();
    y = player->getSprite()->getY();





    while(SDL_PollEvent(setup->getMainEvent()))
    {
//    switch(setup->getMainEvent()->type)
//    {
//    case SDL_KEYDOWN:
    if(setup->getMainEvent()->type == SDL_KEYDOWN && setup->getMainEvent()->key.repeat == 0 )
    {

        switch(setup->getMainEvent()->key.keysym.sym)
        {
          case SDLK_UP:
            MoveUp = true;
            player->setIsMoving(true);
            break;
           case SDLK_DOWN:
            MoveDown = true;
            player->setIsMoving(true);
            break;
           case SDLK_LEFT:
            MoveLeft = true;
            player->setIsMoving(true);
            break;
           case SDLK_RIGHT:
            MoveRight = true;
             player->setIsMoving(true);
            break;
           default:
               break;
        }

}


    if(setup->getMainEvent()->type == SDL_KEYUP)
    {
    switch(setup->getMainEvent()->key.keysym.sym)
    {
      case SDLK_UP:
        player->getSprite()->playAnimation(0,0,3,120);
        MoveUp = false;
        player->setIsMoving(false);

        break;
       case SDLK_DOWN:
        player->getSprite()->playAnimation(0,0,0,120);
        MoveDown = false;
        player->setIsMoving(false);


        break;
       case SDLK_LEFT:
        player->getSprite()->playAnimation(0,0,1,120);
        MoveLeft = false;
        player->setIsMoving(false);


        break;
       case SDLK_RIGHT:
        player->getSprite()->playAnimation(0,0,2,120);
        MoveRight = false;
        player->setIsMoving(false);


        break;
       default:
           break;
    }

    }
}
    if(timeCheck +10 < SDL_GetTicks())
    {

        if(MoveLeft)
       {
            player->getSprite()->playAnimation(0,3,1,120);
            if(x <=0) {player->getSprite()->setX(0);}
            else{ player->getSprite()->setX(x -2);}

            //player->setX(x);
        }
        if(MoveRight)
        {
            player->getSprite()->playAnimation(0,3,2,120);
            if(player->getSprite()->getX() + /* must fix thisplayer->getSprite()->getCropWidth()*/32  >=levelWidth ) {player->getSprite()->setX(levelWidth - 32)/*player->getSprite()->getCropWidth())*/;}
            else{ player->getSprite()->setX(x + 2);}

            //player->setX(x);
        }
        if(MoveDown)
        {
            player->getSprite()->playAnimation(0,3,0,120);
            if(player->getSprite()->getY() + 48 >=levelHeight){player->getSprite()->setY(levelHeight - 48);}
            else{player->getSprite()->setY(y + 2);}



            //player->setY(y);
        }
        if(MoveUp)
        {
            player->getSprite()->playAnimation(0,3,3,120);
            if(y <=0){player->getSprite()->setY(0);}
            else{player->getSprite()->setY(y - 2);}

            //player->setY(y);
        }
        timeCheck = SDL_GetTicks();
    }

}

void KeyboardMovement::Stop()
{
    MoveUp = false;
    MoveDown = false;
    MoveLeft = false;
    MoveRight = false;
}
