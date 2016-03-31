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
   maxHealth = 180 + 100* entityLevel->getCurrentLevel() + rand() % 50;
   currentHealth = maxHealth;
   attackDamage = 60 + 8* entityLevel->getCurrentLevel() + rand() % 20;
   experience = 40 + 7*entityLevel->getCurrentLevel();
   setResistance();



}

Enemy::~Enemy()
{

   delete enemySprite;
   delete entityLevel;
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

void Enemy::useAbility(ISkill *skill, Entity *player)
{

}
void Enemy::isSelected(SDL_setup * setup, ISprite *sprite)
{



    //Get mouse position
       int x, y;
       SDL_GetMouseState( &x, &y );

       //Check if mouse is in button
       bool inside = true;

       //Mouse is left of the button
       if( x < sprite->getPositionRect().x )
       {
           inside = false;
       }
       //Mouse is right of the button
       else if( x >sprite->getPositionRect().x + sprite->getPositionRect().w )
       {
           inside = false;
       }
       //Mouse above the button
       else if( y < sprite->getPositionRect().y )
       {
           inside = false;
       }
       //Mouse below the button
       else if( y > sprite->getPositionRect().y + sprite->getPositionRect().h )
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




std::map<std::string, int> *Enemy::getSkillMap()
{
    return &skillMap;
}

void Enemy::setSkillMap(const std::map<std::string, int> &value)
{
    skillMap = value;
}

SkillList *Enemy::getSkillList() const
{

}


void Enemy::useItem(Item *item)
{
}


void Enemy::levelUP()
{
}


void Enemy::setLevel(int aLevel)
{
    entityLevel->setCurrentLevel(aLevel);
    maxHealth = 180 + 100* entityLevel->getCurrentLevel() + rand() % 50;
    currentHealth = maxHealth;
    attackDamage = 60 + 15* entityLevel->getCurrentLevel() + rand() % 20;
    experience = 40 + 7*entityLevel->getCurrentLevel();
}


void Enemy::useItem(Entity *player, Item *item)
{
}


bool Enemy::useItem(Entity *player, std::string item)
{
}



Inventory *Enemy::getInventory() const
{
}

void Enemy::setInventory(Inventory *value)
{
}


Item::TYPE Enemy::getResistance() const
{
    return resistance;
}

void Enemy::setResistance()
{
    int x = rand() % 4;
    switch (x)
    {

    case 0:
        resistance = Item::AXE;
        std::cout << name<< " resistance is  axes"<<std::endl;
        break;
    case 1:
        resistance = Item::SWORD;
        std::cout << name<< " resistance is  swords"<<std::endl;
        break;
    case 2:
        resistance = Item::SPEAR;
        std::cout << name<< " resistance is  spears"<<std::endl;
        break;
    case 3:
        resistance = Item::MACE;
        std::cout << name<< " resistance is  maces"<<std::endl;
        break;
    }



}
