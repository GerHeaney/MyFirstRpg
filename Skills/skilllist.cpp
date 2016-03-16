#include "skilllist.h"

SkillList::SkillList()
{
    skillList.push_back(new AxeSkill(Item::AXE,10,60,5,"Hack"));
    skillList.push_back(new AxeSkill(Item::AXE,20,120,10,"Cleave"));
    skillList.push_back(new AxeSkill(Item::AXE,30,240,20,"SkullSplitter"));
    skillList.push_back(new MaceSkill(Item::MACE,10,60,5,"Smash"));
    skillList.push_back(new MaceSkill(Item::MACE,20,120,10,"BoneBreaker"));
    skillList.push_back(new MaceSkill(Item::MACE,30,240,20,"EarthShatter"));
    skillList.push_back(new SpearSkill(Item::SPEAR,10,60,5,"stab"));
    skillList.push_back(new SpearSkill(Item::SPEAR,20,120,10,"Thrust"));
    skillList.push_back(new SpearSkill(Item::SPEAR,30,240,20,"Impale"));
    skillList.push_back(new SwordSkill(Item::SWORD,10,60,5,"Slash"));
    skillList.push_back(new SwordSkill(Item::SWORD,20,120,10,"GutSlice"));
    skillList.push_back(new SwordSkill(Item::SWORD,30,240,20,"BladeStorm"));

}

std::list<ISkill *> *SkillList::getSkillList()
{
    return &skillList;
}

ISkill *SkillList::getSkill(Item::TYPE type, int skill)
{
    std::list<ISkill*>::iterator iList ;
    for(iList = skillList.begin();iList !=skillList.end();)
    {
        if((*iList)->getType() == type && (*iList)->getRequiredSkill() == skill)
        {
            return (*iList);
        }
        iList++;
    }
}

