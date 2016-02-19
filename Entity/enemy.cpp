#include "enemy.h"
#include "Entity/maincharacter.h"

Enemy::Enemy(SDL_setup *gameSetup, std::string passedName, std::string path)
{
    isMoving = false;
    name = passedName;


   setup = gameSetup;

   enemySprite = new EnemySprite(setup->getRenderer(),path.c_str());
   currentHealth = 300;
   maxHealth = 300;
   attackDamage = 30;


}

Enemy::~Enemy()
{
    delete setup;
    delete enemySprite;
}


void Enemy::setSprite(EnemySprite *value)
{
    enemySprite = value;
}

EnemySprite *Enemy::getSprite()
{
    return enemySprite;
}

std::string Enemy::getName() const
{
    return name;
}

void Enemy::setName(const std::string &value)
{
    name = value;
}

std::string Enemy::getBattleStats()
{
    std::ostringstream battleStats;
    battleStats <<name << "         " <<"Health    "<< currentHealth <<"/" << maxHealth;
    std::string stats = battleStats.str();
    return stats;

}

int Enemy::getCurrentHealth() const
{
    return currentHealth;
}

void Enemy::setCurrentHealth(int value)
{
    currentHealth = value;
}

void Enemy::attack(Entity *player)
{
    player->setCurrentHealth(player->getCurrentHealth() - attackDamage);
    if(player->getCurrentHealth() <=0)
    {
        player->setCurrentHealth(0);
    }
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

int Enemy::getMaxHealth() const
{
    return maxHealth;
}

void Enemy::setMaxHealth(int value)
{
    maxHealth = value;
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

std::string Enemy::toString(int number)
{

}

