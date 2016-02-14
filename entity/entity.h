#ifndef ENTITY_H
#define ENTITY_H

#include <stdio.h>
#include <string>
#include <iostream>

#include "GameSetup/sdl_setup.h"


class Entity
{
public:

    virtual void setOrigin(int X, int Y) = 0;
    virtual bool GetMoving() = 0;
    virtual void setIsMoving(bool value) = 0;


    virtual int getHealth() const = 0;
    virtual void setHealth(int value) = 0;

    virtual int getAbilityPower() const = 0;
    virtual void setAbilityPower(int value) = 0;

    virtual int getAttackDamage() const = 0;
    virtual void setAttackDamage(int value) = 0;

protected:
    bool isMoving;
    std::string name;
    SDL_setup *setup;
    int health;
    int abilityPower;
    int attackDamage;

};

#endif // ENTITY_H
