#include "maceskill.h"


MaceSkill::MaceSkill(int cost, int power, int requiredSkill, std::string name)
{
    this->cost = cost;
    this->power = power;
    this->requiredSkill = requiredSkill;
    this->name = name;

}

MaceSkill::~MaceSkill()
{

}



int MaceSkill::getCost() const
{
    return cost;
}

void MaceSkill::setCost(int value)
{
    cost = value;
}

int MaceSkill::getPower() const
{
    return power;
}

void MaceSkill::setPower(int value)
{
    power = value;
}

int MaceSkill::getRequiredSkill() const
{
    return requiredSkill;
}

void MaceSkill::setRequiredSkill(int value)
{
    requiredSkill = value;
}

std::string MaceSkill::getName() const
{
    return name;
}

void MaceSkill::setName(const std::string &value)
{
    name = value;
}


bool MaceSkill::getActive() const
{
    return active;
}

void MaceSkill::setActive(bool value)
{
    active = value;
}
