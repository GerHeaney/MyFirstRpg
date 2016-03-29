#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <math.h>

class Level
{
public:
    Level();
    ~Level();


    void setuplevels(int firstLevelXP, int lastLevelXP, int levels);




    int getMinLevel() const;
    void setMinLevel(int value);

    int getMaxLevel() const;
    void setMaxLevel(int value);

    int getCurrentLevel() const;
    void setCurrentLevel(int value);

    int getCurrentXP() const;
    void setCurrentXP(int value);

    int getMaxXP() const;
    void setMaxXP(int value);


    int getSkillPoints() ;
    void setSkillPoints(int value);
    int getMinXP() const;
    void setMinXP(int value);

    int getNextLevelXP();
    void setNextLevelXP(int value);


    int getLastLevelXP();
    void setLastLevelXP(int value);

    void levelUP();
    int getRequiredXP();
    void setRequiredXP(int value);

private:

    int minLevel;
    int maxLevel;
    int currentLevel;
    int currentXP;
    int lastLevelXP;
    int requiredXP;
    int nextLevelXP;
    int minXP;
    int maxXP;
    int skillPoints;
    double A;
    double B;

};

#endif // LEVEL_H
