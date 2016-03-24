#ifndef ETHER_H
#define ETHER_H
#include "Item/item.h"

class Ether : public Item
{
public:
    Ether();
    Ether(SDL_setup *setup);
    ~Ether();


    // Item interface
public:
    virtual TYPE getType();
    virtual void setType(const TYPE &value);
    virtual int getCost();
    virtual void setCost(int value);
    virtual int getPower();
    virtual void setPower(int value);
    virtual std::string getName();
    virtual void setName(const std::string &value);
    virtual MenuSprite *getIcon() const;
    virtual void setIcon(MenuSprite *value);
    virtual int getQuantity() const;
    virtual void setQuantity(int value);

    // Item interface
public:
    virtual bool getEquipped() const;
    virtual void setEquipped(bool value);
};

#endif // ETHER_H
