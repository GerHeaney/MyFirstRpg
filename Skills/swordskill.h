#ifndef SWORDSKILL_H
#define SWORDSKILL_H
#include "Skills/iskill.h"

class SwordSkill : public ISkill
{
public:
    SwordSkill(int cost, int power, int requiredSkill, std::string name);
    ~SwordSkill();


    // ISkill interface
public:
    virtual int getCost() const;
    virtual void setCost(int value);
    virtual int getPower() const;
    virtual void setPower(int value);
    virtual int getRequiredSkill() const;
    virtual void setRequiredSkill(int value);
    virtual std::string getName() const;
    virtual void setName(const std::string &value);
    virtual bool getActive() const;
    virtual void setActive(bool value);
};

#endif // SWORDSKILL_H
