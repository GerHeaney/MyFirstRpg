 #ifndef SPEARSKILL_H
#define SPEARSKILL_H

#include "Skills/iskill.h"
class SpearSkill : public ISkill
{
public:
    SpearSkill(Item::TYPE type,int cost, int power, int requiredSkill, std::string name);
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
    virtual bool getActive() const;
    virtual void setActive(bool value);
    virtual Item::TYPE getType() const;
    virtual void setType(const Item::TYPE &value);
};

#endif // SPEARSKILL_H
