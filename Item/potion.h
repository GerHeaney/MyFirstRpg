#ifndef POTION_H
#define POTION_H
#include "Item/item.h"

class Potion : public Item
{
public:
    Potion();
    Potion(SDL_setup *setup);
    ~Potion();


    virtual MenuSprite *getIcon() const;
    virtual void setIcon(MenuSprite *value);
    virtual Item::TYPE getType();
    virtual void setType(const Item::TYPE &value);
    virtual int getCost();
    virtual void setCost(int value);
    virtual int getPower();
    virtual void setPower(int value);
    virtual std::string getName();
    virtual void setName(const std::string &value);
    virtual int getQuantity() const;
    virtual void setQuantity(int value);
};

#endif // POTION_H
