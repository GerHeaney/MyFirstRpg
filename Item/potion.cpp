#include "potion.h"

Potion::Potion()
{

}


MenuSprite *Potion::getIcon() const
{
    return icon;
}

void Potion::setIcon(MenuSprite *value)
{
    icon = value;
}



Item::TYPE Potion::getType()
{
    return type;
}

void Potion::setType(const Item::TYPE &value)
{
    type = value;
}

int Potion::getCost()
{
    return cost;
}

void Potion::setCost(int value)
{
    cost = value;
}

int Potion::getPower()
{
    return power;
}

void Potion::setPower(int value)
{
    power = value;
}

std::string Potion::getName()
{
    return name;
}

void Potion::setName(const std::string &value)
{
    name = value;
}


