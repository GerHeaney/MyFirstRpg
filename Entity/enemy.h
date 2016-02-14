#ifndef ENEMY_H
#define ENEMY_H
#include "Entity/entity.h"
#include "Sprite/enemysprite.h"

class Enemy: public Entity
{
public:    
    Enemy(SDL_setup *gameSetup, std::string passedName, std::string path);

    virtual void setOrigin(int X, int Y);
    virtual bool GetMoving();
    virtual void setIsMoving(bool value);


    virtual int getHealth() const;
    virtual void setHealth(int value);

    virtual int getAbilityPower() const;
    virtual void setAbilityPower(int value);

    virtual int getAttackDamage() const;
    virtual void setAttackDamage(int value);
    void setSprite(EnemySprite * value);
    EnemySprite * getSprite();
private:
    EnemySprite * enemySprite;


};

#endif // ENEMY_H
