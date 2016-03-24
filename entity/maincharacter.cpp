#include "maincharacter.h"


MainCharacter::MainCharacter(SDL_setup * gameSetup, std::string playerName,std::string path)
{
     isMoving = false;
     canAttack = false;
     mouseOver = false;
     selected = false;
     name = playerName;


    playerSprite = new MovingSprite(gameSetup->getRenderer(),path.c_str());
    icon = new MenuSprite(gameSetup->getRenderer(),("resources/Characters/" + playerName + ".png"));
    playerSprite->setupAnimation(4,4);
    entityLevel = new Level();
    weapon = NULL;
    //weapon->setEquipped(true);

    maxHealth = 150 + 100* entityLevel->getCurrentLevel() + rand() % 50;
    currentHealth = maxHealth;
    attackDamage = 90 + 8* entityLevel->getCurrentLevel() + rand() % 20;
    abilityPower = 50;
    maxAP = 50;
    skillMap["Axe Skill"] = 0;
    skillMap["Sword Skill"] = 20;
    skillMap["Mace Skill"] = 0;
    skillMap["Spear Skill"] = 0;
    skillList = new SkillList();
    Potion *potion = new Potion(gameSetup);

    inventory = inventory->partyInventory();
    inventory->addItem(potion);




    //skillList.push_back(new AxeSkill(gameSetup,Item::AXE,"hack",10,60,));


    std::map<std::string,int>::iterator it = skillMap.begin();

    for (it=skillMap.begin(); it!=skillMap.end(); ++it)
       std::cout << it->first << " => " << it->second << '\n';


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

int MainCharacter::getMaxAP()
{
    return maxAP;
}

void MainCharacter::setMaxAP(int value)
{
    maxAP = value;
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
    int damage = attackDamage + weapon->getPower() ;


    if(weapon->getType() == enemy->getResistance())
    {
        damage = damage/3;
        std::cout <<enemy->getName() << " is resitant to " << name <<"'s weapon type"<<std::endl;
    }

    enemy->setCurrentHealth(enemy->getCurrentHealth() - damage);

    if(enemy->getCurrentHealth() <=0)
    {
        enemy->setCurrentHealth(0);
    }
}

void MainCharacter::useAbility(ISkill *skill, Entity *enemy)
{
    int damage = attackDamage + weapon->getPower()+ (skill->getPower() *2);

    enemy->setCurrentHealth(enemy->getCurrentHealth() - damage);

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

void MainCharacter::isSelected(SDL_setup *setup, ISprite * sprite)
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
           mouseOver = true;
          // while(SDL_PollEvent(setup->getMainEvent()) != 0)

           //Set mouse over sprite
           switch( setup->getMainEvent()->type )
           {
               case SDL_MOUSEMOTION:
             std::cout <<" Over " <<name << std::endl;



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

bool MainCharacter::getSelected() const
{
    return selected;
}

void MainCharacter::setSelected(bool value)
{
    selected = value;
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

Item *MainCharacter::getWeapon() const
{
    return weapon;
}

void MainCharacter::setWeapon(Item *value)
{

    weapon = value;
    weapon->setEquipped(true);
}




std::map<std::string, int> *MainCharacter::getSkillMap()
{
    return &skillMap;
}

void MainCharacter::setSkillMap(const std::map<std::string, int> &value)
{
    skillMap = value;
}

SkillList *MainCharacter::getSkillList() const
{
    return skillList;
}

void MainCharacter::levelUP()
{
    entityLevel->levelUP();
    attackDamage = 60 + 8*entityLevel->getCurrentLevel() + rand()% 20;
    maxHealth = 150 + 100* entityLevel->getCurrentLevel() + rand() % 50;
    maxAP += 10;
}


void MainCharacter::setLevel(int level)
{
}


bool MainCharacter::useItem(Entity *player, std::string item)
{
    for(std::list<Item*>::iterator i = inventory->getInventory()->begin();i!=inventory->getInventory()->end();)
    {



        if(item == "Potion")
        {

            Potion pot;
            if(pot.getName() == (*i)->getName())
            {
                if( (*i)->getQuantity() >1)
                {
                    (*i)->setQuantity((*i)->getQuantity() -1);
                    player->setCurrentHealth(player->getCurrentHealth()+ pot.getPower());
                    if(player->getCurrentHealth() >= player->getMaxHealth())
                    {
                        player->setCurrentHealth(player->getMaxHealth());
                    }
                    return true;

                }else if((*i)->getQuantity() ==1)
                {
                    inventory->removeItem((*i));
                    player->setCurrentHealth(player->getCurrentHealth()+ pot.getPower());
                    if(player->getCurrentHealth() >= player->getMaxHealth())
                    {
                        player->setCurrentHealth(player->getMaxHealth());
                    }
                    return true;
                }


            }

        }
        if(item == "Ether")
        {
            Ether ether;
            if(ether.getName() == (*i)->getName())
            {
                if( (*i)->getQuantity() >1)
                {
                    (*i)->setQuantity((*i)->getQuantity() -1);
                    player->setAbilityPower(player->getAbilityPower() + ether.getPower());
                    if(player->getAbilityPower() >= player->getMaxAP())
                    {
                        player->setAbilityPower(player->getMaxAP());
                    }
                    return true;
                }else if((*i)->getQuantity() ==1)
                {
                    inventory->removeItem((*i));
                    player->setAbilityPower(player->getAbilityPower() + ether.getPower());
                    if(player->getAbilityPower() >= player->getMaxAP())
                    {
                        player->setAbilityPower(player->getMaxAP());
                    }
                    return true;
                }
            }

        }
        std::cout  << (*i)->getName() << "  x"<< (*i)->getQuantity() << std::endl;

        i++;
    }
}


Inventory *MainCharacter::getInventory() const
{
    return inventory;
}

void MainCharacter::setInventory(Inventory *value)
{
    inventory = value;
}


Item::TYPE MainCharacter::getResistance() const
{
}

void MainCharacter::setResistance()
{
}
