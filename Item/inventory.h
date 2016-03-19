#ifndef INVENTORY_H
#define INVENTORY_H
#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include "Item/item.h"
#include "Item/potion.h"

class Inventory
{
public:
    static Inventory * partyInventory();

    std::list<Item *>* getInventory();
    void addItem(Item * item);
    void removeItem(Item * item);
    int getAmount(Item *item);

private:
    int count = 0;
    int quantity = 0;
    static Inventory inventory;
    std::list<Item*> inventoryList;
protected:

    Inventory(){}



};

#endif // INVENTORY_H
