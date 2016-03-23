#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include <stdio.h>
#include <string>
#include <map>
#include <iostream>
#include "Sprite/movingsprite.h"
#include "Sprite/backgroundsprite.h"
#include "Entity/entity.h"
#include "Item/weapon.h"
#include <time.h>





class MainCharacter: public Entity
{
public:
    MainCharacter(SDL_setup *gameSetup, std::string playerName, std::string path);
    ~MainCharacter();




    void setOrigin(int X, int Y);
    MovingSprite *getSprite();
    virtual MenuSprite * getIcon();
    void setSprite(MovingSprite *value);
    void setInitFrame(int startFrame,int row);
    bool GetMoving();
    void setIsMoving(bool value);
    virtual int getMaxHealth() const;
    virtual void setMaxHealth(int value);

    virtual int getAbilityPower() const;
    virtual void setAbilityPower(int value);

    virtual int getMaxAP();
    virtual void setMaxAP(int value );

    virtual int getAttackDamage() const;
    virtual void setAttackDamage(int value);
    virtual std::string getBattleStats();
    virtual std::string toString(int number);

    virtual std::string getName() const;
    virtual void setName(const std::string &value);

    virtual int getCurrentHealth() const;
    virtual void setCurrentHealth(int value);
    virtual void attack(Entity * enemy);
    virtual void useAbility(ISkill * skill,Entity* enemy);

    virtual bool getCanAttack() const;
    virtual void setCanAttack(bool value);
    virtual void isSelected(SDL_setup * setup, ISprite *sprite);
    virtual bool getSelected() const ;
    virtual void setSelected(bool value);

    bool getMouseOver() const;
    void setMouseOver(bool value);
    virtual Level *getEntityLevel();

    virtual int getExperience() ;
    virtual void setExperience(int value);

    virtual Item *getWeapon() const;
    virtual void setWeapon(Item *value);


    virtual std::map<std::string, int>* getSkillMap();
    virtual void setSkillMap(const std::map<std::string, int> &value);

     virtual SkillList * getSkillList() const ;

private:

    bool isMoving;





    MovingSprite * playerSprite;
    MenuSprite * icon;


//    CSprite* player;
//    SDL_setup *setup;









    // Entity interface

    // Entity interface
public:
    virtual void levelUP();

    // Entity interface
public:
    virtual void setLevel(int level);

    // Entity interface
public:
    virtual bool useItem(Entity *player, std::string item);

    // Entity interface
public:

    virtual Inventory *getInventory() const;
    virtual void setInventory(Inventory *value);

    // Entity interface
public:
    virtual Item::TYPE getResistance() const;
    virtual void setResistance();
};

#endif // MAINCHARACTER_H
