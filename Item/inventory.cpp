#include "inventory.h"

Inventory Inventory::inventory;

Inventory *Inventory::partyInventory()
{
    return &inventory;
}

std::list<Item *> *Inventory::getInventory()
{
    return &inventoryList;
}

void Inventory::addItem(Item *item)
{
    bool contains = false;
     std::list<Item*>::iterator i;
     if(inventoryList.size() < 1)
     {
          std::cout << "inventory is empty adding" <<item->getName()<< std::endl;
          inventoryList.push_back(item);
     }
    for(i = inventoryList.begin();i !=inventoryList.end();)
    {

        if((*i)->getName() == item->getName())
        {            std::cout << "list contains " <<item->getName() << std::endl;
            (*i)->setQuantity((*i)->getQuantity() +1);
            contains = true;
            //delete item;
            break;
        }

        i++;
    }
    if(!contains)
    {
        item->setQuantity(item->getQuantity() +1);
         std::cout << "inventory doesn't contain" <<item->getName()<< " so now one is added" <<std::endl;
        inventoryList.push_back(item);
    }
}

void Inventory::removeItem(Item *item)
{
    std::list<Item*>::iterator i;
    for(i = inventoryList.begin();i !=inventoryList.end();)
    {
        if((*i)->getType() == item->getType())
        {
            inventoryList.remove((*i));
            break;
        }
        i++;
    }
}

int Inventory::getAmount(Item* item)
{
int count = 0;
    std::list<Item*>::iterator i;
    for(i = inventoryList.begin();i !=inventoryList.end();)
    {
        if((*i)->getName() == item->getName())
        {

             count++;



        }

        i++;


    }
    return count;
}

