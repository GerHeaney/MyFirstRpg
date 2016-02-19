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
    void setAttacks();
    void executeAttacks();
    void endBattle();

    bool getWinBattle() const;

    bool getLostBattle() const;

private:
    bool turn;
    bool winBattle;
    bool lostBattle;




};

#endif // BATTLESYSTEM_H
