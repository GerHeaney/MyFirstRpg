#ifndef INVENTORY_H
#define INVENTORY_H
#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
#include "Item/item.h"

class Inventory
{
public:
    Inventory();
    std::list<Item *>* getInventory();
    void addItem(Item * item);
    void removeItem(Item * item);

private:
    std::list<Item*> inventory;



};

#endif // INVENTORY_H
