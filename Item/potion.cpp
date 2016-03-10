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

