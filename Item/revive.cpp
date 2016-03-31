#include "potion.h"
#include "revive.h"

Revive::Revive()
{
    type = Item::REVIVE;
    name = "Revive";
    cost = 100;
    power = 250;
    quantity = 0;
    icon = NULL;

}

Revive::Revive(SDL_setup *setup)
{
    type = Item::REVIVE;
    name = "Potion";
    cost = 100;
    power = 250;
    quantity = 0;
    icon = new MenuSprite(setup->getRenderer(),"resources/Items/potion.png");


}
Revive::~Revive()
{
    delete icon;
}


MenuSprite *Revive::getIcon() const
{
    return icon;
}

void Revive::setIcon(MenuSprite *value)
{
    icon = value;
}



Item::TYPE Revive::getType()
{
    return type;
}

void Revive::setType(const Item::TYPE &value)
{
    type = value;
}

int Revive::getCost()
{
    return cost;
}

void Revive::setCost(int value)
{
    cost = value;
}

int Revive::getPower()
{
    return power;
}

void Revive::setPower(int value)
{
    power = value;
}

std::string Revive::getName()
{
    return name;
}

void Revive::setName(const std::string &value)
{
    name = value;
}




int Revive::getQuantity() const
{
    return quantity;
}

void Revive::setQuantity(int value)
{
    quantity = value;
}


bool Revive::getEquipped() const
{
}

void Revive::setEquipped(bool value)
{
}

std::string Revive::getPath() const
{
    return path;
}

void Revive::setPath(const std::string &value)
{
    path = value;
}
