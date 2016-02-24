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

    bool getPlayerTurn() const;
    void setPlayerTurn(bool value);

private:
    bool playerTurn;
    bool winBattle;
    bool lostBattle;
    std::vector<Enemy *> enemies;
    std::vector<MainCharacter *> party;





};

#endif // BATTLESYSTEM_H
