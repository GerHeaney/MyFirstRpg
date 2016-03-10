#ifndef POTION_H
#define POTION_H
#include "Item/item.h"

class Potion : public Item
{
public:
    Potion();


    virtual MenuSprite *getIcon() const;
    virtual void setIcon(MenuSprite *value);

private:

};

#endif // POTION_H
