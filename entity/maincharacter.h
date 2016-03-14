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
    virtual void useAbility(Entity* enemy);

    virtual bool getCanAttack() const;
    virtual void setCanAttack(bool value);
    virtual void isSelected(SDL_setup * setup);
    virtual bool getSelected() const ;
    virtual void setSelected(bool value);

    bool getMouseOver() const;
    void setMouseOver(bool value);
    virtual Level *getEntityLevel();

    virtual int getExperience() ;
    virtual void setExperience(int value);

    virtual Item *getWeapon() const;
    virtual void setWeapon(Item *value);
    virtual std::list<ISkill *> getList();

    virtual std::map<std::string, int>* getSkillMap();
    virtual void setSkillMap(const std::map<std::string, int> &value);

     virtual std::list<ISkill *> getSkillList() const ;

private:

    bool isMoving;




    MovingSprite * playerSprite;
    MenuSprite * icon;


//    CSprite* player;
//    SDL_setup *setup;








};

#endif // MAINCHARACTER_H
