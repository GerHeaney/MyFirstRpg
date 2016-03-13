#ifndef MACESKILL_H
#define MACESKILL_H
#include "Skills/iskill.h"


class MaceSkill : public ISkill
{
public:
    MaceSkill();
    ~MaceSkill();

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
};

#endif // MACESKILL_H
