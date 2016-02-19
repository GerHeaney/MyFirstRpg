#include "battlesystem.h"

BattleSystem::BattleSystem()
{
    winBattle = false;

}

void BattleSystem::updateBattle(std::vector<Enemy *> enemies, std::vector<MainCharacter *> party)
{


        party.front()->attack(enemies.front());
        enemies.front()->attack(party.front());



//    if(enemies.front()->getCurrentHealth() == 0)
//    {
//        winBattle = true;
//    }
//    if(party.front()->getCurrentHealth() == 0)
//    {
//        lostBattle = true;
//    }
        if(!enemies.empty())
        {
           winBattle = false;

    for(std::vector<Enemy*>::iterator i = enemies.begin();i!=enemies.end();++i)
    {
        std::cout << enemies.front()->getCurrentHealth() << std::endl;
       if((*i)->getCurrentHealth() ==0)
       {
           std::cout << "enemy health is "<<(*i)->getCurrentHealth() << std::endl;
         enemies.erase(*i);
       }
    }
        }
    if(enemies.empty())
    {
       winBattle = true;
    }

}

void BattleSystem::setAttacks()
{

}

void BattleSystem::executeAttacks()
{

}

void BattleSystem::endBattle()
{

}

bool BattleSystem::getWinBattle() const
{
    return winBattle;
}

bool BattleSystem::getLostBattle() const
{
    return lostBattle;
}

