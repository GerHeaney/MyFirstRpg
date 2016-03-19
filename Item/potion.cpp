#include "potion.h"

Potion::Potion(SDL_setup *setup)
{
    type = Item::POTION;
    name = "Potion";
    cost = 100;
    power = 250;
    quantity = 0;
    icon = new MenuSprite(setup->getRenderer(),"resources/Items/potion.png");


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




int Potion::getQuantity() const
{
    return quantity;
}

void Potion::setQuantity(int value)
{
    quantity = value;
}
