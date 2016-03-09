#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>
#include <iostream>
#include <string>

class Item
{
public:
    enum TYPE {
        AXE,SWORD,SPEAR,BOW,USABLE
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

protected:

    int cost;
    int power;
    std::string name;
    TYPE type;



};

#endif // ITEM_H