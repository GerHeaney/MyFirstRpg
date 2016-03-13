#include "swordskill.h"

SwordSkill::SwordSkill()
{

}

SwordSkill::~SwordSkill()
{

}



int SwordSkill::getCost() const
{
    return cost;
}

void SwordSkill::setCost(int value)
{
    cost = value;
}

int SwordSkill::getPower() const
{
    return power;
}

void SwordSkill::setPower(int value)
{
    power = value;
}

int SwordSkill::getRequiredSkill() const
{
    return requiredSkill;
}

void SwordSkill::setRequiredSkill(int value)
{
    requiredSkill = value;
}

std::string SwordSkill::getName() const
{
    return name;
}

void SwordSkill::setName(const std::string &value)
{
    name = value;
}
