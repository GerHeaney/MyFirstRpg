#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>
#include <iostream>
#include <string>

#include <Sprite/menusprite.h>

class Item
{
public:
    enum TYPE {
        AXE,SWORD,SPEAR,MACE,POTION,ETHER
    };
    virtual ~Item() {}
    virtual TYPE getType() = 0;
    virtual void setType(const TYPE &value) = 0;

    virtual int getCost() = 0;
    virtual void setCost(int value) = 0;

    virtual int getPower()  = 0;
    virtual void setPower(int value) = 0;

    virtual std::string getName()  = 0;
    virtual void setName(const std::string &value) = 0;

    virtual MenuSprite *getIcon() const = 0;
    virtual void setIcon(MenuSprite *value) = 0;

protected:

    int cost;
    int power;
    std::string name;
    TYPE type;
    MenuSprite * icon;



};

#endif // ITEM_H
