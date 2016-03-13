#include "maceskill.h"


MaceSkill::MaceSkill()
{

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
