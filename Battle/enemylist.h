#ifndef ENEMYLIST_H
#define ENEMYLIST_H
#include <vector>
#include <stdio.h>
#include <iostream>

class EnemyList
{
public:
    EnemyList();
    ~EnemyList();

    std::vector<std::string> getEnemies() const;

private:
    std::vector<std::string> enemies;
};

#endif // ENEMYLIST_H
