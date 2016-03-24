#include "weapon.h"


Weapon::Weapon(SDL_setup * setup, Item::TYPE wType, std::string wName, int wCost, int wPower,std::string path)
{
   type = wType;
   name = wName;
   cost = wCost;
   power = wPower;
   icon = new MenuSprite(setup->getRenderer(),path.c_str());
   quantity = 0;

}
Weapon::~Weapon()
{
    delete icon;

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


int Weapon::getQuantity() const
{
    return quantity;
}

void Weapon::setQuantity(int value)
{
    quantity = value;
}


bool Weapon::getEquipped() const
{
    return equipped;
}

void Weapon::setEquipped(bool value)
{
    equipped = value;
}
