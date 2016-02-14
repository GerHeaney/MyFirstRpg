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
    virtual int getHealth() const;
    virtual void setHealth(int value);

    virtual int getAbilityPower() const;
    virtual void setAbilityPower(int value);

    virtual int getAttackDamage() const;
    virtual void setAttackDamage(int value);

private:

    bool isMoving;

   MovingSprite * playerSprite;
//    std::string name;
//    CSprite* player;
//    SDL_setup *setup;




};

#endif // MAINCHARACTER_H
