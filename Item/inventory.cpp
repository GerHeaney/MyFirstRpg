#include "inventory.h"

Inventory::Inventory()
{

}

std::list<Item *> *Inventory::getInventory()
{
    return &inventory;
}

void Inventory::addItem(Item *item)
{
    inventory.push_back(item);
}

void Inventory::removeItem(Item *item)
{
    std::list<Item*>::iterator i;
    for(i = inventory.begin();i !=inventory.end();)
    {
        if((*i)->getName() == item->getName())
        {
            inventory.remove((*i));
            break;
        }
        i++;
    }
}

