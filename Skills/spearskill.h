#ifndef SPEARSKILL_H
#define SPEARSKILL_H

#include "Skills/iskill.h"
class SpearSkill : public ISkill
{
public:
    SpearSkill();
    ~SpearSkill();

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

#endif // SPEARSKILL_H
