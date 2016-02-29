#ifndef ENEMY_H
#define ENEMY_H
#include "Entity/entity.h"
#include "Sprite/enemysprite.h"

class Enemy: public Entity
{
public:    
    Enemy(SDL_setup *gameSetup, std::string passedName, std::string path);
    ~Enemy();

    virtual void setOrigin(int X, int Y);
    virtual bool GetMoving();
    virtual void setIsMoving(bool value);


    virtual int getMaxHealth() const;
    virtual void setMaxHealth(int value);

    virtual int getAbilityPower() const;
    virtual void setAbilityPower(int value);

    virtual int getAttackDamage() const;
    virtual void setAttackDamage(int value);
    virtual std::string toString(int number);
    void setSprite(EnemySprite * value);
    EnemySprite * getSprite();
    virtual std::string getName() const;
    virtual void setName(const std::string &value);
    virtual std::string getBattleStats();

    virtual int getCurrentHealth() const;
    virtual void setCurrentHealth(int value);
    virtual void attack(Entity * player);
    void isSelected();

    bool getCanAttack() const;
    void setCanAttack(bool value);

    bool getSelected() const;
    void setSelected(bool value);

private:
    EnemySprite * enemySprite;
    bool canAttack;
    bool selected;



};

#endif // ENEMY_H
