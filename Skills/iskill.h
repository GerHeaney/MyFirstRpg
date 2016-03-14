#ifndef ISKILL_H
#define ISKILL_H
#include <iostream>
#include "Item/item.h"

class ISkill
{
public:
   virtual ~ISkill(){}
    virtual int getCost() const=0;
    virtual void setCost(int value)=0;

    virtual int getPower() const=0;
    virtual void setPower(int value)=0;

    virtual int getRequiredSkill() const=0;
    virtual void setRequiredSkill(int value)=0;

    virtual std::string getName() const=0;
    virtual void setName(const std::string &value)=0;

    virtual bool getActive() const  = 0;
    virtual void setActive(bool value) = 0;

    virtual Item::TYPE getType() const = 0;
    virtual void setType(const Item::TYPE &value) = 0;

protected:
    bool active = false;
    int cost;
    int power;
    int requiredSkill;
    std::string name;
    Item::TYPE type;

};

#endif // ISKILL_H

