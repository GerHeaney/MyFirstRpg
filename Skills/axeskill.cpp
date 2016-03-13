
#include "axeskill.h"

AxeSkill::AxeSkill()
{

}

AxeSkill::~AxeSkill()
{

}



int AxeSkill::getCost() const
{
    return cost;
}

void AxeSkill::setCost(int value)
{
    cost = value;
}

int AxeSkill::getPower() const
{
    return power;
}

void AxeSkill::setPower(int value)
{
    power = value;
}

int AxeSkill::getRequiredSkill() const
{
    return requiredSkill;
}

void AxeSkill::setRequiredSkill(int value)
{
    requiredSkill = value;
}

std::string AxeSkill::getName() const
{
    return name;
}

void AxeSkill::setName(const std::string &value)
{
    name = value;
}
