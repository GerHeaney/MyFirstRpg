#ifndef ISKILL_H
#define ISKILL_H
#include <iostream>

class ISkill
{
public:
   virtual ~ISkill(){}
    virtual int getCost() const=0;
    virtual void setCost(int value)=0;

    virtual int getPower() const=0;
    virtual void setPower(int value)=0;

    virtual int getRequiredSkill() const=0;
    virtual void setRequiredSkill(int value)=0;

    virtual std::string getName() const=0;
    virtual void setName(const std::string &value)=0;

protected:
    int cost;
    int power;
    int requiredSkill;
    std::string name;

};

#endif // ISKILL_H
