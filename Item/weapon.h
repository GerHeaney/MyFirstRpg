#ifndef WEAPON_H
#define WEAPON_H

#include "Item/item.h"

class Weapon : public Item
{
public:
    Weapon(Item::TYPE wType, std::string wName, int wCost, int wPower);
    ~Weapon();
    virtual Item::TYPE getType() ;
    virtual void setType(const Item::TYPE &value) ;

    virtual int getCost() ;
    virtual void setCost(int value) ;

    virtual int getPower()  ;
    virtual void setPower(int value) ;

    virtual std::string getName()  ;
    virtual void setName(const std::string &value) ;


private:


};

#endif // WEAPON_H