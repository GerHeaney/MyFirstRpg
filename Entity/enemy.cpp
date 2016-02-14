#include "enemy.h"
#include "Entity/maincharacter.h"

Enemy::Enemy(SDL_setup *gameSetup, std::string passedName, std::string path)
{
    isMoving = false;
    name = passedName;


   setup = gameSetup;

   enemySprite = new EnemySprite(setup->getRenderer(),path.c_str());


}


void Enemy::setSprite(EnemySprite *value)
{
    enemySprite = value;
}

EnemySprite *Enemy::getSprite()
{
    return enemySprite;
}



void Enemy::setOrigin(int X, int Y)
{

   enemySprite->setPosition(X,Y);
}

bool Enemy::GetMoving()
{
    if (isMoving == true)
    {
        return true;
    }
    return false;
}
void Enemy::setIsMoving(bool value)
{
    isMoving = value;
}

int Enemy::getHealth() const
{
    return health;
}

void Enemy::setHealth(int value)
{
    health = value;
}

int Enemy::getAbilityPower() const
{
    return abilityPower;
}

void Enemy::setAbilityPower(int value)
{
    abilityPower = value;
}

int Enemy::getAttackDamage() const
{
    return attackDamage;
}

void Enemy::setAttackDamage(int value)
{
    attackDamage = value;
}

