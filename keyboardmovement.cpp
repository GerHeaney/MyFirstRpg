#include "keyboardmovement.h"

KeyboardMovement::KeyboardMovement(SDL_setup * passedSetup, MainCharacter *passedPlayer)
{


    player = passedPlayer;
    setup = passedSetup;
    MoveRight = false;
    MoveLeft = false;
    MoveUp = false;
    MoveDown = false;

    timeCheck = SDL_GetTicks();
    x = player->getX();
    y = player->getY();



}

void KeyboardMovement::Move()
{

     std:: cout << "x  is " << x << std::endl;
    switch(setup->getMainEvent()->type)
    {
    case SDL_KEYDOWN:

        switch(setup->getMainEvent()->key.keysym.sym)
        {
          case SDLK_UP:
            MoveUp = true;
            break;
           case SDLK_DOWN:
            MoveDown = true;
            break;
           case SDLK_LEFT:
            MoveLeft = true;
            break;
           case SDLK_RIGHT:
            MoveRight = true;
            break;
           default:
               break;
        }



        break;
    case SDL_KEYUP:

    switch(setup->getMainEvent()->key.keysym.sym)
    {
      case SDLK_UP:
        player->playAnimation(0,0,3,120);
        MoveUp = false;

        break;
       case SDLK_DOWN:
        player->playAnimation(0,0,0,120);
        MoveDown = false;

        break;
       case SDLK_LEFT:
        player->playAnimation(0,0,1,120);
        MoveLeft = false;

        break;
       case SDLK_RIGHT:
        player->playAnimation(0,0,2,120);
        MoveRight = false;

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
            player->playAnimation(0,3,1,120);
            x -=1;
            player->setX(x);
        }
        if(MoveRight)
        {
            player->playAnimation(0,3,2,120);
           x +=1;
            player->setX(x);
        }
        if(MoveDown)
        {
            player->playAnimation(0,3,0,120);
            y +=1;
            player->setY(y);
        }
        if(MoveUp)
        {
            player->playAnimation(0,3,3,120);
            y -=1;
            player->setY(y);
        }
        timeCheck = SDL_GetTicks();
    }
}
