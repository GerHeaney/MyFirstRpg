#include "maincharacter.h"

MainCharacter::MainCharacter(SDL_setup * gameSetup, std::string playerName,std::string path)
{
     isMoving = false;
     name = playerName;

    setup = gameSetup;

    playerSprite = new MovingSprite(setup->getRenderer(),path.c_str());
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

void MainCharacter::setInitFrame(int startFrame,int row)
{
  playerSprite->setInitFrame(startFrame,row);
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

int MainCharacter::getHealth() const
{
    return health;
}

void MainCharacter::setHealth(int value)
{
    health = value;
}

int MainCharacter::getAbilityPower() const
{
    return abilityPower;
}

void MainCharacter::setAbilityPower(int value)
{
    abilityPower = value;
}

int MainCharacter::getAttackDamage() const
{
    return attackDamage;
}

void MainCharacter::setAttackDamage(int value)
{
    attackDamage = value;
}

