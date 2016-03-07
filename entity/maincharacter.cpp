#include "maincharacter.h"


MainCharacter::MainCharacter(SDL_setup * gameSetup, std::string playerName,std::string path)
{
     isMoving = false;
     canAttack = false;
     name = playerName;

    playerSprite = new MovingSprite(gameSetup->getRenderer(),path.c_str());
    icon = new MenuSprite(gameSetup->getRenderer(),("resources/Characters/" + playerName + ".png"));
    playerSprite->setupAnimation(4,4);
    entityLevel = new Level();
    currentHealth = 300;
    maxHealth = 300;
    attackDamage = 300;

}
MainCharacter::~MainCharacter()
{


}

MovingSprite *MainCharacter::getSprite()
{
    return playerSprite;
}

MenuSprite *MainCharacter::getIcon()
{
    return icon;
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

int MainCharacter::getMaxHealth() const
{
    return maxHealth;
}

void MainCharacter::setMaxHealth(int value)
{
    maxHealth = value;
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

std::string MainCharacter::getBattleStats()
{
    std::ostringstream battleStats;
    battleStats <<name << "         " <<"Health    "<< currentHealth <<"/" << maxHealth;
    std::string stats = battleStats.str();
    return stats;
}

std::string MainCharacter::toString(int number)
{
    std::ostringstream infoString;
    infoString << number;
    std::string numberString = infoString.str();
    return numberString;

}

std::string MainCharacter::getName() const
{
    return name;
}

void MainCharacter::setName(const std::string &value)
{
    name = value;
}

int MainCharacter::getCurrentHealth() const
{
    return currentHealth;
}

void MainCharacter::setCurrentHealth(int value)
{
    currentHealth = value;
}

void MainCharacter::attack(Entity *enemy)
{
    enemy->setCurrentHealth(enemy->getCurrentHealth() - attackDamage);

    if(enemy->getCurrentHealth() <=0)
    {
        enemy->setCurrentHealth(0);
    }
}

bool MainCharacter::getCanAttack() const
{
    return canAttack;
}

void MainCharacter::setCanAttack(bool value)
{
    canAttack = value;
}

void MainCharacter::isSelected(SDL_setup *setup)
{

}

bool MainCharacter::getSelected() const
{

}

void MainCharacter::setSelected(bool value)
{

}

bool MainCharacter::getMouseOver() const
{
    return mouseOver;
}

void MainCharacter::setMouseOver(bool value)
{
    mouseOver = value;
}

Level *MainCharacter::getEntityLevel()
{
    return entityLevel;
}

int MainCharacter::getExperience()
{
    return experience;
}

void MainCharacter::setExperience(int value)
{
    experience = value;
}

