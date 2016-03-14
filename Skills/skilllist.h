#ifndef SKILLLIST_H
#define SKILLLIST_H

#include "Skills/iskill.h"
#include "Skills/axeskill.h"
#include "Skills/maceskill.h"
#include "Skills/spearskill.h"
#include "Skills/swordskill.h"
#include <list>



class SkillList
{
public:
    SkillList();
    std::list<ISkill *>* getSkillList();

  void  Init();
private:
    std::list<ISkill*> skillList;

};

#endif // SKILLLIST_H
