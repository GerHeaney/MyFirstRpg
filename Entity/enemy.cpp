#include "enemy.h"
#include "Entity/maincharacter.h"

Enemy::Enemy(SDL_setup *gameSetup, std::string passedName, std::string path)
{
    isMoving = false;
    selected = false;
    canAttack = false;
    mouseOver = false;
    name = passedName;

   enemySprite = new EnemySprite(gameSetup->getRenderer(),path.c_str());
   entityLevel = new Level();
   currentHealth = 300;
   maxHealth = 300;
   attackDamage = 30;
   experience = 200;



}

Enemy::~Enemy()
{

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

MenuSprite *Enemy::getIcon()
{

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
void Enemy::isSelected(SDL_setup * setup)
{



    //Get mouse position
       int x, y;
       SDL_GetMouseState( &x, &y );

       //Check if mouse is in button
       bool inside = true;

       //Mouse is left of the button
       if( x < enemySprite->getPositionRect().x )
       {
           inside = false;
       }
       //Mouse is right of the button
       else if( x >enemySprite->getPositionRect().x + enemySprite->getPositionRect().w )
       {
           inside = false;
       }
       //Mouse above the button
       else if( y < enemySprite->getPositionRect().y )
       {
           inside = false;
       }
       //Mouse below the button
       else if( y > enemySprite->getPositionRect().y + enemySprite->getPositionRect().h )
       {
           inside = false;
       }

       //Mouse is outside button
       if( !inside )
       {
           mouseOver = false;
       }
       //Mouse is inside button
       else
       {
          // while(SDL_PollEvent(setup->getMainEvent()) != 0)

           //Set mouse over sprite
           switch( setup->getMainEvent()->type )
           {
               case SDL_MOUSEMOTION:
             //std::cout <<" Over enemy " << std::endl;
               mouseOver = true;


               break;

               case SDL_MOUSEBUTTONDOWN:
               // button pressed
               //std::cout <<"pressed" << std::endl;
               mouseOver = false;
                selected = true;
                SDL_Delay(300);



               break;

               case SDL_MOUSEBUTTONUP:
               std::cout <<"released" << std::endl;
               mouseOver = false;
                selected = false;
                SDL_Delay(300);




               break;
           }


   }

}

bool Enemy::getCanAttack() const
{
    return canAttack;
}

void Enemy::setCanAttack(bool value)
{
    canAttack = value;
}

bool Enemy::getSelected() const
{
    return selected;
}

void Enemy::setSelected(bool value)
{
    selected = value;
}

bool Enemy::getMouseOver() const
{
    return mouseOver;
}

void Enemy::setMouseOver(bool value)
{
    mouseOver = value;
}

Level *Enemy::getEntityLevel()
{
    return entityLevel;
}

int Enemy::getExperience()
{
    return experience;
}

void Enemy::setExperience(int value)
{
    experience = value;
}

Item *Enemy::getWeapon() const
{
    return weapon;
}

void Enemy::setWeapon(Item *value)
{
    weapon = value;
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

int Enemy::getMaxAP()
{
    return maxAP;
}

void Enemy::setMaxAP(int value)
{
    maxAP = value;
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

