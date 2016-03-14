
#include "axeskill.h"

AxeSkill::AxeSkill(int cost, int power, int requiredSkill, std::string name)
{
    this->cost = cost;
    this->power = power;
    this->requiredSkill = requiredSkill;
    this->name = name;

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


bool AxeSkill::getActive() const
{
    return active;
}

void AxeSkill::setActive(bool value)
{
    active = value;
}
