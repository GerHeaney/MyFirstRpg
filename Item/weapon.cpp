#include "weapon.h"


Weapon::Weapon(Item::TYPE wType, std::string wName, int wCost, int wPower)
{
   type = wType;
   name = wName;
   cost = wCost;
   power = wPower;

}
Weapon::~Weapon()
{

}

int Weapon::getCost()
{
    return cost;
}

void Weapon::setCost(int value)
{
    cost = value;
}

int Weapon::getPower()
{
    return power;
}

void Weapon::setPower(int value)
{
    power = value;
}

std::string Weapon::getName()
{
    return name;
}

void Weapon::setName(const std::string &value)
{
    name = value;
}

MenuSprite *Weapon::getIcon() const
{
    return icon;
}

void Weapon::setIcon(MenuSprite *value)
{
    icon = value;
}


Item::TYPE Weapon::getType()
{
    return type;
}

void Weapon::setType(const Item::TYPE &value)
{
    type = value;
}
