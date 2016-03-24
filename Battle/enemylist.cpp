#include "enemylist.h"

EnemyList::EnemyList()
{
    enemies.push_back("Black Drake");
    enemies.push_back("Black Mage");
    enemies.push_back("Dark Hermit");
    enemies.push_back("Demon");
    enemies.push_back("Green Dragon");
    enemies.push_back("Green Drake");
    enemies.push_back("Hermit");
    enemies.push_back("Masks");
    enemies.push_back("Medusa");
    enemies.push_back("Ogre");
    enemies.push_back("Red Mage");

}

std::vector<std::string> EnemyList::getEnemies() const
{
    return enemies;
}

