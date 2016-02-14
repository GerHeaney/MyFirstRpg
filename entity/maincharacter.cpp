#include "maincharacter.h"

MainCharacter::MainCharacter(SDL_setup * gameSetup, int width, int height, std::string playerName,std::string path)
    :Entity(gameSetup,width,height,playerName,path)
{
     isMoving = false;
     name = playerName;
     std::cout << name <<" width is " << width << std::endl;
     std::cout << name <<" height is " << height << std::endl;

    setup = gameSetup;

    playerSprite = new MovingSprite(setup->getRenderer(),path.c_str());
//    std::cout << name <<" sprite created" << std::endl;
    playerSprite->setupAnimation(4,4);

}
MainCharacter::~MainCharacter()
{


}

MovingSprite *MainCharacter::getSprite()
{
    return playerSprite;
}

void MainCharacter::setSprite(MovingSprite *value)
{
    playerSprite = value;
}
void MainCharacter::Draw()
{
    player->Draw();

}
void MainCharacter::setInitFrame(int startFrame,int row)
{
  player->setInitFrame(startFrame,row);
}

void MainCharacter::setOrigin(int X, int Y)
{

   playerSprite->setOrigin(X,Y);
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

