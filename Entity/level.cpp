#include "level.h"

Level::Level()
{
    maxLevel = 30;
    minXP = 300;
    maxXP = 350000;



    B = log((double)maxXP / minXP) / (maxLevel - 1);
    A = (double)minXP / (exp(B) - 1.0);
   // setuplevels(200,100000,20);
    currentLevel = 1;
    skillPoints = 0;
    currentXP = 0;
    nextLevelXP = 0;
    lastLevelXP = 0;
    requiredXP = getNextLevelXP();
       // nextLevelXP = round(A * exp(B * currentLevel));
}


int Level::getCurrentXP() const
{
    return currentXP;
}

void Level::setCurrentXP(int value)
{
    currentXP = value;
}

int Level::getMaxXP() const
{
    return maxXP;
}

void Level::setMaxXP(int value)
{
    maxXP = value;
}

int Level::getSkillPoints() const
{
    return skillPoints;
}

void Level::setSkillPoints(int value)
{
    skillPoints = value;
}

int Level::getMinXP() const
{
    return minXP;
}

void Level::setMinXP(int value)
{
    minXP = value;
}

int Level::getNextLevelXP()
{   
    int lastXP = round(A * exp(B * (currentLevel - 1)));
    nextLevelXP = round(A * exp(B * currentLevel));
    return nextLevelXP - lastXP;
}

void Level::setNextLevelXP(int value)
{
    nextLevelXP = value;
}

int Level::getLastLevelXP()
{
    if(currentLevel >1)
    {
    int lastXP = round(A * exp(B * (currentLevel - 2)));
    lastLevelXP = round(A * exp(B * (currentLevel-1)));
    return lastLevelXP - lastXP;
    }
    else{return 0;}
}

void Level::setLastLevelXP(int value)
{
    lastLevelXP = value;
}

void Level::setuplevels(int firstLevelXP, int lastLevelXP, int levels)
{
    maxLevel = levels;
    minXP = firstLevelXP;
    maxXP = lastLevelXP;

    B = log((double)maxXP / minXP) / (maxLevel - 1);
    A = (double)minXP / (exp(B) - 1.0);
    double C = exp(B) - 1;
//    std:: cout <<" A is " << A <<std::endl;
//    std:: cout <<" B is " << B <<std::endl;
//    std:: cout <<" C is " << C <<std::endl;

   for (int i = 1; i <= levels; i++)
    {
      currentLevel = i;
      // std::cout << i << " " << (nextLevelXP - currentXP) << std::endl;
        std::cout << "current level is " << i << std::endl;
        std::cout << "last level xp is" << getLastLevelXP() << std::endl;
        std::cout << "added xp is " << getNextLevelXP() + getLastLevelXP()<< std::endl;
       std::cout <<" next level xp is" << getNextLevelXP()<< std::endl << std::endl;


   }
}

int Level::getMinLevel() const
{
    return minLevel;
}

void Level::setMinLevel(int value)
{
    minLevel = value;
}

int Level::getMaxLevel() const
{
    return maxLevel;
}

void Level::setMaxLevel(int value)
{
    maxLevel = value;
}

int Level::getCurrentLevel() const
{
    return currentLevel;
}

void Level::setCurrentLevel(int value)
{
    currentLevel = value;
}
void Level::levelUP()
{



        std::cout << "last level xp is" << getLastLevelXP() << std::endl;
        std::cout << "added xp is " << getNextLevelXP() + getLastLevelXP()<< std::endl;


        if(requiredXP <=0)
        {
             currentLevel++;
             skillPoints++;
        requiredXP += getNextLevelXP();
        }
        std::cout << "You have reached level " << currentLevel << std::endl;
        std::cout << "next level xp is " << getNextLevelXP() << std::endl;



}

int Level::getRequiredXP() const
{
    return requiredXP;
}

void Level::setRequiredXP(int value)
{
    requiredXP = value;
}

