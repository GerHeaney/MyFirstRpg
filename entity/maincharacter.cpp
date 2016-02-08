#include "maincharacter.h"

MainCharacter::MainCharacter(SDL_setup * gameSetup, int width, int height, std::string playerName)
{
     isMoving = false;
     name = playerName;
//     std::cout << name <<" width is " << width << std::endl;
//     std::cout << name <<" height is " << height << std::endl;

    setup = gameSetup;

    player = new CSprite(setup->getRenderer(),"resources/belf.png",0,0,width,height);
//    std::cout << name <<" sprite created" << std::endl;
    player->setupAnimation(4,4);

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

}
void MainCharacter::setInitFrame(int startFrame,int row)
{
  player->setInitFrame(startFrame,row);
}
void MainCharacter::setCamera(){
    player->setCamera();

}
void MainCharacter::setOrigin(int X, int Y)
{

   player->setOrigin(X,Y);
}
SDL_Rect MainCharacter::getCamera()
{
    return player->getCamera();
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
