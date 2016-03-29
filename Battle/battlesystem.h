#ifndef BATTLESYSTEM_H
#define BATTLESYSTEM_H
#include "iostream"
#include "Entity/enemy.h"
#include "Entity/maincharacter.h"
#include <vector>


class BattleSystem
{
public:
    BattleSystem();
    ~BattleSystem();
    void updateBattle(std::vector<Entity *> enemies, std::vector<Entity *> party);
    void setAttacks(std::vector<Entity *> list, bool value);
    void executeAttacks();
    void endBattle();

    bool getWinBattle() const;

    bool getLostBattle() const;

    bool getPlayerTurn(std::vector<Entity *> party);
    void setPlayerTurn(bool value);
    bool getEnemyTurn(std::vector<Entity *> enemies);

private:
    bool playerTurn;
    bool winBattle;
    bool lostBattle;   
    int turnCount;





};

#endif // BATTLESYSTEM_H
