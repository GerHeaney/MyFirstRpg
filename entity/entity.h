#ifndef ENTITY_H
#define ENTITY_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <list>
#include <map>

#include "GameSetup/sdl_setup.h"
#include "Sprite/isprite.h"
#include "Sprite/menusprite.h"
#include "Entity/level.h"
#include "Item/item.h"
#include "Item/ether.h"
#include "Item/revive.h"
#include "Skills/skilllist.h"
#include "Item/inventory.h"


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

    virtual int getMaxAP()= 0;
    virtual void setMaxAP(int value ) = 0;

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
    virtual void useAbility(ISkill*,Entity*) = 0;
    virtual void isSelected(SDL_setup *, ISprite *) = 0;
    virtual bool useItem(Entity * player,std::string item)= 0;


    virtual bool getCanAttack() const = 0 ;
    virtual void setCanAttack(bool value) = 0;

    virtual bool getSelected() const = 0;
    virtual void setSelected(bool value) = 0;
    virtual MenuSprite * getIcon() = 0;


    virtual bool getMouseOver() const = 0;
    virtual void setMouseOver(bool value) = 0;

    virtual Level *getEntityLevel() = 0;

    virtual int getExperience() = 0;
    virtual void setExperience(int value) = 0;
    virtual void levelUP()= 0;
    virtual void setLevel(int aLevel)= 0;



    virtual Item *getWeapon() const = 0;
    virtual void setWeapon(Item *value)  = 0;   

    virtual std::map<std::string, int> *getSkillMap()  = 0;
    virtual void setSkillMap(const std::map<std::string, int> &value) = 0;

    virtual SkillList *getSkillList() const = 0;

    virtual Inventory *getInventory() const= 0;
    virtual void setInventory(Inventory *value) = 0;

    virtual Item::TYPE getResistance() const= 0;
    virtual void setResistance() = 0;


protected:
    Level * entityLevel;
    Item * weapon;
    Item::TYPE resistance;
    bool isMoving;
    bool canAttack;
    bool selected;
    bool mouseOver;
    std::string name;
    SDL_setup *setup;
    int currentHealth;
    int maxHealth;
    int abilityPower;
    int maxAP;
    int attackDamage;
    int experience;
    int level;
    SkillList * skillList;
    std::map<std::string,int> skillMap;
    Inventory * inventory;


};

#endif // ENTITY_H


