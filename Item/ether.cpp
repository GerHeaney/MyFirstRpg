#include "ether.h"

Ether::Ether()
{
    type = Item::ETHER;
    name = "Ether";
    cost = 250;
    power = 50;
    quantity = 0;
    icon = NULL;

}

Ether::Ether(SDL_setup *setup)
{
    type = Item::ETHER;
    name = "Ether";
    cost = 250;
    power = 50;
    icon = new MenuSprite(setup->getRenderer(),"resources/Items/ether.png");
    quantity = 0;

}

Ether::~Ether()
{
    delete icon;
}

Item::TYPE Ether::getType()
{
    return type;
}

void Ether::setType(const Item::TYPE &value)
{
    type = value;
}

int Ether::getCost()
{
    return cost;
}

void Ether::setCost(int value)
{
    cost = value;
}

int Ether::getPower()
{
    return power;
}

void Ether::setPower(int value)
{
    power = value;
}

std::string Ether::getName()
{
    return name;
}

void Ether::setName(const std::string &value)
{
    name = value;
}

MenuSprite *Ether::getIcon() const
{
    return icon;
}

void Ether::setIcon(MenuSprite *value)
{
    icon = value;
}


int Ether::getQuantity() const
{
   return quantity;
}

void Ether::setQuantity(int value)
{
    quantity = value;
}


bool Ether::getEquipped() const
{
}

void Ether::setEquipped(bool value)
{
}