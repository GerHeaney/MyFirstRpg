#include "keyboardmovement.h"

KeyboardMovement::KeyboardMovement(SDL_setup * passedSetup, Entity *passedPlayer, int width, int height)
{


    player = passedPlayer;
    setup = passedSetup;
    MoveRight = false;
    MoveLeft = false;
    MoveUp = false;
    MoveDown = false;
    levelHeight = height;
    levelWidth = width;

    timeCheck = SDL_GetTicks();




}

void KeyboardMovement::Move()
{
    x = player->getPlayer()->getX();
    y = player->getPlayer()->getY();


    switch(setup->getMainEvent()->type)
    {
    case SDL_KEYDOWN:

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



        break;
    case SDL_KEYUP:

    switch(setup->getMainEvent()->key.keysym.sym)
    {
      case SDLK_UP:
        player->getPlayer()->playAnimation(0,0,3,120);
        MoveUp = false;
        player->setIsMoving(false);

        break;
       case SDLK_DOWN:
        player->getPlayer()->playAnimation(0,0,0,120);
        MoveDown = false;
        player->setIsMoving(false);


        break;
       case SDLK_LEFT:
        player->getPlayer()->playAnimation(0,0,1,120);
        MoveLeft = false;
        player->setIsMoving(false);


        break;
       case SDLK_RIGHT:
        player->getPlayer()->playAnimation(0,0,2,120);
        MoveRight = false;
        player->setIsMoving(false);


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
            player->getPlayer()->playAnimation(0,3,1,120);
            if(x <=0) {player->getPlayer()->setX(0);}
            else{ player->getPlayer()->setX(x -2);}
            std::cout << "player x position is " << player->getPlayer()->getX() << std::endl;
            std::cout << " x variable is " << x << std::endl;
            //player->setX(x);
        }
        if(MoveRight)
        {
            player->getPlayer()->playAnimation(0,3,2,120);
            if(player->getPlayer()->getX() + player->getPlayer()->getCropWidth()  >=levelWidth ) {player->getPlayer()->setX(levelWidth -player->getPlayer()->getCropWidth());}
            else{ player->getPlayer()->setX(x + 2);}
            std::cout << "xpos is " << player->getPlayer()->getX() << std::endl;
            std::cout << "camera.x is " << player->getPlayer()->getCameraX() << std::endl;

            //player->setX(x);
        }
        if(MoveDown)
        {
            player->getPlayer()->playAnimation(0,3,0,120);
            if(player->getPlayer()->getY() + player->getPlayer()->getCropHeight() >=levelHeight){player->getPlayer()->setY(levelHeight - player->getPlayer()->getCropHeight());}
            else{player->getPlayer()->setY(y + 2);}
            std::cout << "player y position is " << player->getPlayer()->getY() << std::endl;
            std::cout << " y variable is " << y << std::endl;


            //player->setY(y);
        }
        if(MoveUp)
        {
            player->getPlayer()->playAnimation(0,3,3,120);
            if(y <=0){player->getPlayer()->setY(0);}
            else{player->getPlayer()->setY(y - 2);}
            std::cout << "player y position is " << player->getPlayer()->getY() << std::endl;
            std::cout << " y variable is " << y << std::endl;
            //player->setY(y);
        }
        timeCheck = SDL_GetTicks();
    }
}
