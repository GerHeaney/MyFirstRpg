#ifndef REVIVE_H
#define REVIVE_H

#include "item.h"



class Revive : public Item
{

    // Item interface
public:
    Revive();
    Revive(SDL_setup * setup);
    ~Revive();
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
    virtual bool getEquipped() const;
    virtual void setEquipped(bool value);
    virtual std::string getPath() const;
    virtual void setPath(const std::string &value);
};

#endif // REVIVE_H
