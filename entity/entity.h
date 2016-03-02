#ifndef ENTITY_H
#define ENTITY_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>

#include "GameSetup/sdl_setup.h"
#include "Sprite/isprite.h"


class Entity
{
public:
    virtual ~Entity() {}

    virtual void setOrigin(int X, int Y) = 0;
    virtual bool GetMoving() = 0;
    virtual void setIsMoving(bool value) = 0;


    virtual int getMaxHealth() const = 0;
    virtual void setMaxHealth(int value) = 0;

    virtual int getAbilityPower() const = 0;
    virtual void setAbilityPower(int value) = 0;

    virtual int getAttackDamage() const = 0;
    virtual void setAttackDamage(int value) = 0;
    virtual std::string getBattleStats() = 0;
    virtual std::string toString(int number) = 0;

    virtual std::string getName() const = 0;
    virtual void setName(const std::string &value) = 0;

    virtual int getCurrentHealth() const = 0;
    virtual void setCurrentHealth(int value) = 0;
    virtual ISprite * getSprite()=0;
    virtual void attack(Entity *) = 0;
    virtual void isSelected() = 0;


    virtual bool getCanAttack() const = 0 ;
    virtual void setCanAttack(bool value) = 0;

    virtual bool getSelected() const = 0;
    virtual void setSelected(bool value) = 0;


    virtual bool getMouseOver() const = 0;
    virtual void setMouseOver(bool value) = 0;

protected:
    bool isMoving;
    bool canAttack;
    bool selected;
    bool mouseOver;
    std::string name;
    SDL_setup *setup;
    int currentHealth;
    int maxHealth;
    int abilityPower;
    int attackDamage;

};

#endif // ENTITY_H

