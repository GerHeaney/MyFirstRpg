#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include <stdio.h>
#include <string>
#include <iostream>
#include "Sprite/movingsprite.h"
#include "Entity/entity.h"




class MainCharacter: public Entity
{
public:
    MainCharacter(SDL_setup *gameSetup, std::string playerName, std::string path);
    ~MainCharacter();




    void setOrigin(int X, int Y);
    MovingSprite *getSprite();
    void setSprite(MovingSprite *value);
    void setInitFrame(int startFrame,int row);
    bool GetMoving();
    void setIsMoving(bool value);
    virtual int getMaxHealth() const;
    virtual void setMaxHealth(int value);

    virtual int getAbilityPower() const;
    virtual void setAbilityPower(int value);

    virtual int getAttackDamage() const;
    virtual void setAttackDamage(int value);
    virtual std::string getBattleStats();
    virtual std::string toString(int number);

    virtual std::string getName() const;
    virtual void setName(const std::string &value);

    virtual int getCurrentHealth() const;
    virtual void setCurrentHealth(int value);
    virtual void attack(Entity * enemy);

    bool getCanAttack() const;
    void setCanAttack(bool value);

private:

    bool isMoving;
    bool canAttack;

    MovingSprite * playerSprite;

//    CSprite* player;
//    SDL_setup *setup;




};

#endif // MAINCHARACTER_H
