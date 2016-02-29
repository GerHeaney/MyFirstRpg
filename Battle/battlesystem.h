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
    void updateBattle(std::vector<Enemy *> enemies, std::vector<MainCharacter *> party);
    void setAttacks(std::vector<Enemy *> enemies, std::vector<MainCharacter *> party);
    void executeAttacks();
    void endBattle();

    bool getWinBattle() const;

    bool getLostBattle() const;

    bool getPlayerTurn(std::vector<MainCharacter *> party);
    void setPlayerTurn(bool value);
    bool getEnemyTurn(std::vector<Enemy *> enemies);

private:
    bool playerTurn;
    bool winBattle;
    bool lostBattle;
    std::vector<Enemy *> enemies;
    std::vector<MainCharacter *> party;
    int turnCount;





};

#endif // BATTLESYSTEM_H
