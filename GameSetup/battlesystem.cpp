#include "battlesystem.h"

BattleSystem::BattleSystem()
{

    winBattle = false;

}

void BattleSystem::updateBattle(std::vector<Enemy *> enemies, std::vector<MainCharacter *> party)
{


      //  party.front()->attack(enemies.front());
      //  enemies.front()->attack(party.front());



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


    for(std::vector<Enemy*>::iterator i = enemies.begin();i!=enemies.end();)
    {
      //  std::cout << "the enemy health before check is " <<enemies.front()->getCurrentHealth() << std::endl;
       if((*i)->getCurrentHealth() ==0)
       {
     //      std::cout << "enemy health is "<<(*i)->getCurrentHealth() << std::endl;
         enemies.erase(i);
       }else{++i;}
    }
        }
    if(enemies.empty())
    {
        enemies.clear();
       std::cout << "Enemies is empty" << std::endl;
       winBattle = true;

    }

}

void BattleSystem::setAttacks(std::vector<Enemy *> enemies, std::vector<MainCharacter *> party)
{
    playerTurn = true;
    for(std::vector<MainCharacter*>::iterator i = party.begin();i!=party.end();)
    {
        std::cout << "attack is set" << std::endl;
        (*i)->setCanAttack(true);
        i++;

    }

}

void BattleSystem::executeAttacks()
{
    std::cout << "player  turn is over" << std::endl;
    playerTurn = false;

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

bool BattleSystem::getPlayerTurn() const
{
    return playerTurn;
}

void BattleSystem::setPlayerTurn(bool value)
{
    playerTurn = value;
}

