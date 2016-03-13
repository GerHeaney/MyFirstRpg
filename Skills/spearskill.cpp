#include "spearskill.h"


SpearSkill::SpearSkill()
{

}

SpearSkill::~SpearSkill()
{

}



int SpearSkill::getCost() const
{
    return cost;
}

void SpearSkill::setCost(int value)
{
    cost = value;
}

int SpearSkill::getPower() const
{
    return power;
}

void SpearSkill::setPower(int value)
{
    power = value;
}

int SpearSkill::getRequiredSkill() const
{
    return requiredSkill;
}

void SpearSkill::setRequiredSkill(int value)
{
    requiredSkill = value;
}

std::string SpearSkill::getName() const
{
    return name;
}

void SpearSkill::setName(const std::string &value)
{
    name = value;
}
