#include "battlesystem.h"

BattleSystem::BattleSystem()
{

    winBattle = false;
    turnCount = 0;

}

void BattleSystem::updateBattle(std::vector<Entity *> enemies, std::vector<Entity *> party)
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


    for(std::vector<Entity*>::iterator i = enemies.begin();i!=enemies.end();)
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

void BattleSystem::setAttacks(std::vector<Entity *> list,bool value)
{

    for(std::vector<Entity*>::iterator i = list.begin();i!=list.end();)
    {
//        std::cout << "attack is set" << std::endl;
        (*i)->setCanAttack(value);
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

bool BattleSystem::getPlayerTurn(std::vector<Entity *> party)
{
    int turnCount = 0;
    for(std::vector<Entity*>::iterator i = party.begin();i!=party.end();)
    {

        if((*i)->getCanAttack())
        {
            turnCount++;
        }
        i++;

    }
    if(turnCount == 0)
    {
        std::cout << "party turns are empty" << std::endl;
        setAttacks(enemies,true);
        return false;

    }else
    {
//        std::cout << "turn count is " << turnCount << std::endl;
        turnCount = 0;
        return true;
    }


}
bool BattleSystem::getEnemyTurn(std::vector<Entity *> enemies)
{
    for(std::vector<Entity*>::iterator i = enemies.begin();i!=enemies.end();)
    {

        if((*i)->getCanAttack())
        {
            turnCount++;
        }
        i++;

    }
    if(turnCount == 0)
    {
        std::cout << "enemy turns are empty" << std::endl;
        return false;
    }else
    {
//        std::cout << "turn count is " << turnCount << std::endl;
        turnCount = 0;
        return true;
    }


}

void BattleSystem::setPlayerTurn(bool value)
{
    playerTurn = value;
}

