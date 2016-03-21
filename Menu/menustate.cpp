#include "menustate.h"

MenuState MenuState::menu;



void MenuState::Init(GameEngine *game)
{   
    exit = false;
    state = STATE_INTRO;
    back = new MenuSprite(game->getRenderer(),"resources/Menu/menuback.png");
    options = new MenuSprite(game->getRenderer(),"resources/menu/options.png");
    line1 = new DisplayField();
    Item = new FontButton(game->getSetup(),"Item");
    Equip = new FontButton(game->getSetup(),"Equip");
    Skills = new FontButton(game->getSetup(),"Skills");   
    Weapon = new FontButton(game->getSetup(),"Weapon");
    Axe = new FontButton(game->getSetup(),">");
    Mace  = new FontButton(game->getSetup(),">");
    Spear = new FontButton(game->getSetup(),">");
    Sword = new FontButton(game->getSetup(),">");
    selected = new MenuSprite(game->getRenderer(),"resources/Battle/select.png");

    //Item->setPosition(options->getPositionRect().x,options->getPositionRect().y);

    buttons.push_back(Item);
    buttons.push_back(Equip);
    buttons.push_back(Skills);
}

void MenuState::Update(GameEngine *game)
{

}

void MenuState::Draw(GameEngine *game)
{
    DrawVisitor visitor;
    switch(state)
    {
    case STATE_INTRO:
    {

        back->setSize(0,0,game->getScreenWidth()- options->getRect().w ,game->getScreenHeight());
        options->setPosition(game->getScreenWidth() - options->getRect().w,0);
        back->accept(&visitor);
        options->accept(&visitor);


        int scrpos = 35;

        if(Item->getInside())
        {

            selected->setPosition(Item->getPosition().x - selected->getRect().w,Item->getPosition().y + selected->getRect().h/2);
            selected->accept(&visitor);
        }


        int buttonpos = 35;

        for(std::vector<FontButton*>::iterator i = buttons.begin();i!=buttons.end();)
        {
            (*i)->Draw(options->getPositionRect().x + offset,options->getPositionRect().y+buttonpos );

            buttonpos+=35;
            if((*i)->getInside())
            {
                std::cout <<"inside buttons loop of " << (*i)->getText() << std::endl;
                selected->setPosition((*i)->getPosition().x - selected->getRect().w,(*i)->getPosition().y + selected->getRect().h/2);
                selected->accept(&visitor);
            }
//            if((*i)->getPressed())
//            {
//                std::cout <<"inside";
//               state = 1;
//            }
             i++;
        }

        for(std::vector<Entity *>::iterator i = game->getParty()->begin();i<game->getParty()->end();)
        {
            (*i)->getIcon()->setPositionRect(50,scrpos);
            (*i)->getIcon()->accept(&visitor);
            line1->setPosition((*i)->getIcon()->getPositionRect().x+(*i)->getIcon()->getPositionRect().w
                               + (*i)->getIcon()->getPositionRect().w/3 ,(*i)->getIcon()->getPositionRect().y);
            line1->setText((*i)->getName());
            line1->Display(game->getSetup());
            line1->setText("LV: " + (*i)->toString((*i)->getEntityLevel()->getCurrentLevel()));
            line1->setPosition((*i)->getIcon()->getPositionRect().x+(*i)->getIcon()->getPositionRect().w+
                               (*i)->getIcon()->getPositionRect().w/3 ,(*i)->getIcon()->getPositionRect().y + 30);
            line1->Display(game->getSetup());
            line1->setText("HP: " + (*i)->toString((*i)->getCurrentHealth()) + "/" +(*i)->toString((*i)->getMaxHealth()));
            line1->setPosition((*i)->getIcon()->getPositionRect().x+(*i)->getIcon()->getPositionRect().w+
                               (*i)->getIcon()->getPositionRect().w/3 ,(*i)->getIcon()->getPositionRect().y + 60);
            line1->Display(game->getSetup());
            line1->setPosition((*i)->getIcon()->getPositionRect().x+(*i)->getIcon()->getPositionRect().w+
                               (*i)->getIcon()->getPositionRect().w/3,(*i)->getIcon()->getPositionRect().y + 90);
            line1->setText("AP: " + (*i)->toString((*i)->getAbilityPower()) + "/" +(*i)->toString((*i)->getMaxAP()));
            line1->Display(game->getSetup());
            line1->setPosition((*i)->getIcon()->getPositionRect().x+(*i)->getIcon()->getPositionRect().w*2 ,
                               (*i)->getIcon()->getPositionRect().y);
            line1->setText("Current EXP: " + (*i)->toString((*i)->getEntityLevel()->getCurrentXP()));
            line1->Display(game->getSetup());
            line1->setPosition((*i)->getIcon()->getPositionRect().x+(*i)->getIcon()->getPositionRect().w*4 ,
                               (*i)->getIcon()->getPositionRect().y);
            line1->setText("EXP for next level: " + (*i)->toString((*i)->getEntityLevel()->getRequiredXP()));
            line1->Display(game->getSetup());
            if(Equip->getPressed())
            {

                    (*i)->isSelected(game->getSetup(),(*i)->getIcon());

                    if((*i)->getMouseOver())
                    {
                        selected->setPosition((*i)->getIcon()->getPositionRect().x - selected->getRect().w,
                                              (*i)->getIcon()->getPositionRect().y + selected->getRect().h/2);
                        selected->accept(&visitor);
                        std::cout << "over";

                    }
                    if( (*i)->getSelected())
                    {
                        selectedPlayer = (*i);
                        Weapon->setText(selectedPlayer->getWeapon()->getName());
                        Weapon->setInside(false);
                        selectedPlayer->setSelected(false);
                        switchState(STATE_EQUIP);


                    }
            }
            if(Skills->getPressed())
            {

                    (*i)->isSelected(game->getSetup(),(*i)->getIcon());

                    if((*i)->getMouseOver())
                    {
                        selected->setPosition((*i)->getIcon()->getPositionRect().x - selected->getRect().w,
                                              (*i)->getIcon()->getPositionRect().y + selected->getRect().h/2);
                        selected->accept(&visitor);
                        std::cout << "over";

                    }
                    if( (*i)->getSelected())
                    {
                        selectedPlayer = (*i);
                        Axe->setPressed(false);
                        Mace->setPressed(false);
                        Sword->setPressed(false);
                        Spear->setPressed(false);
                        Axe->setInside(false);
                        selectedPlayer->setSelected(false);

                        switchState(STATE_SKILLS);


                    }
            }



            scrpos += back->getRect().h/3;
            i++;
        }
         break;
    }

    case STATE_EQUIP:
    {
        int scrpos = 40;
        back->setSize(0,0,game->getScreenWidth(),game->getScreenHeight()/3);
         back->accept(&visitor);
         back->setSize(0,game->getScreenHeight()/3,game->getScreenWidth(),game->getScreenHeight()/3 *2);
         back->accept(&visitor);
         back->setSize(game->getScreenWidth()/3*2,game->getScreenHeight()/3,game->getScreenWidth()/3,game->getScreenHeight()/3 *2);
         back->accept(&visitor);

         selectedPlayer->getIcon()->setPositionRect(scrpos,scrpos);
         selectedPlayer->getIcon()->accept(&visitor);
         line1->setPosition(selectedPlayer->getIcon()->getPositionRect().x+selectedPlayer->getIcon()->getPositionRect().w
                            + selectedPlayer->getIcon()->getPositionRect().w/3 ,selectedPlayer->getIcon()->getPositionRect().y);
         line1->setText(selectedPlayer->getName());
         line1->Display(game->getSetup());
         line1->setText("LV: " + selectedPlayer->toString(selectedPlayer->getEntityLevel()->getCurrentLevel()));
         line1->setPosition(selectedPlayer->getIcon()->getPositionRect().x+selectedPlayer->getIcon()->getPositionRect().w
                            + selectedPlayer->getIcon()->getPositionRect().w/3 ,selectedPlayer->getIcon()->getPositionRect().y + 30);
         line1->Display(game->getSetup());
         line1->setText("HP: " + selectedPlayer->toString(selectedPlayer->getCurrentHealth()) + "/" +selectedPlayer->toString(selectedPlayer->getMaxHealth()));
         line1->setPosition(selectedPlayer->getIcon()->getPositionRect().x+selectedPlayer->getIcon()->getPositionRect().w+
                            selectedPlayer->getIcon()->getPositionRect().w/3 ,selectedPlayer->getIcon()->getPositionRect().y + 60);
         line1->Display(game->getSetup());
         line1->setPosition(selectedPlayer->getIcon()->getPositionRect().x+selectedPlayer->getIcon()->getPositionRect().w+
                            selectedPlayer->getIcon()->getPositionRect().w/3,selectedPlayer->getIcon()->getPositionRect().y + 90);
         line1->setText("AP: " + selectedPlayer->toString(selectedPlayer->getAbilityPower()) + "/" +selectedPlayer->toString(selectedPlayer->getMaxAP()));
         line1->Display(game->getSetup());
         line1->setPosition(selectedPlayer->getIcon()->getPositionRect().x + selectedPlayer->getIcon()->getPositionRect().w * 3,
                            selectedPlayer->getIcon()->getPositionRect().y + 90);
         line1->setText(" Equipped Weapon :");
         line1->Display(game->getSetup(),50);

         selectedPlayer->getWeapon()->getIcon()->setPosition(Weapon->getPosition().x -
                                                             selectedPlayer->getWeapon()->getIcon()->getPositionRect().w,Weapon->getPosition().y);
         selectedPlayer->getWeapon()->getIcon()->accept(&visitor);



         Weapon->Draw(selectedPlayer->getIcon()->getPositionRect().x + selectedPlayer->getWeapon()->getIcon()->getPositionRect().w
                      + selectedPlayer->getIcon()->getPositionRect().w * 5,
                      selectedPlayer->getIcon()->getPositionRect().y + 90);

          std::cout <<std::boolalpha <<  Weapon->getInside();
         if(Weapon->getInside())
         {
             std::cout <<"inside weapon" << std::endl;
             selected->setPosition(selectedPlayer->getWeapon()->getIcon()->getPositionRect().x - selectedPlayer->getWeapon()->getIcon()->getRect().w*1.5,
                                   selectedPlayer->getWeapon()->getIcon()->getPositionRect().y + selectedPlayer->getWeapon()->getIcon()->getPositionRect().h/2);
             selected->accept(&visitor);
         }


        break;
}
    case(STATE_SKILLS):
    {
        int scrpos = 40;
        back->setSize(0,0,game->getScreenWidth(),game->getScreenHeight()/3);
        back->accept(&visitor);
        back->setSize(game->getScreenWidth()/3*2,game->getScreenHeight()/3,game->getScreenWidth()/3,game->getScreenHeight()/3 *2);
        back->accept(&visitor);
        back->setSize(0,game->getScreenHeight()/3,game->getScreenWidth() - game->getScreenWidth()/3,game->getScreenHeight()/3 *2);
        back->accept(&visitor);

        selectedPlayer->getIcon()->setPositionRect(scrpos,scrpos);
        selectedPlayer->getIcon()->accept(&visitor);

        line1->setPosition(selectedPlayer->getIcon()->getPositionRect().x+selectedPlayer->getIcon()->getPositionRect().w
                           + selectedPlayer->getIcon()->getPositionRect().w/3 ,selectedPlayer->getIcon()->getPositionRect().y);
        line1->setText(selectedPlayer->getName());
        line1->Display(game->getSetup());

        line1->setText("LV: " + selectedPlayer->toString(selectedPlayer->getEntityLevel()->getCurrentLevel()));
        line1->setPosition(selectedPlayer->getIcon()->getPositionRect().x+selectedPlayer->getIcon()->getPositionRect().w
                           + selectedPlayer->getIcon()->getPositionRect().w/3 ,selectedPlayer->getIcon()->getPositionRect().y + 30);
        line1->Display(game->getSetup());

        line1->setText("HP: " + selectedPlayer->toString(selectedPlayer->getCurrentHealth()) + "/" +selectedPlayer->toString(selectedPlayer->getMaxHealth()));
        line1->setPosition(selectedPlayer->getIcon()->getPositionRect().x+selectedPlayer->getIcon()->getPositionRect().w+
                           selectedPlayer->getIcon()->getPositionRect().w/3 ,selectedPlayer->getIcon()->getPositionRect().y + 60);
        line1->Display(game->getSetup());

        line1->setPosition(selectedPlayer->getIcon()->getPositionRect().x+selectedPlayer->getIcon()->getPositionRect().w+
                           selectedPlayer->getIcon()->getPositionRect().w/3,selectedPlayer->getIcon()->getPositionRect().y + 90);
        line1->setText("AP: " + selectedPlayer->toString(selectedPlayer->getAbilityPower()) + "/" +selectedPlayer->toString(selectedPlayer->getMaxAP()));
        line1->Display(game->getSetup());

        line1->setPosition(selectedPlayer->getIcon()->getPositionRect().x + selectedPlayer->getIcon()->getPositionRect().w * 3,
                           selectedPlayer->getIcon()->getPositionRect().y + 90);
        line1->setText(" Available skill points :" + selectedPlayer->toString(selectedPlayer->getEntityLevel()->getSkillPoints()));
        line1->Display(game->getSetup());

        std::map<std::string,int>::iterator it = selectedPlayer->getSkillMap()->begin();
        std::list<ISkill*>::iterator iList ;
        for(iList = selectedPlayer->getSkillList()->getSkillList()->begin();iList!=selectedPlayer->getSkillList()->getSkillList()->end();)
        {
            if(selectedPlayer->getSkillMap()->at("Axe Skill") >= (*iList)->getRequiredSkill() && (*iList)->getType() == Item::AXE)
            {
                (*iList)->setActive(true);
            }
            if(selectedPlayer->getSkillMap()->at("Mace Skill") >= (*iList)->getRequiredSkill() && (*iList)->getType() == Item::MACE)
            {
                (*iList)->setActive(true);
            }
            if(selectedPlayer->getSkillMap()->at("Spear Skill") >= (*iList)->getRequiredSkill() && (*iList)->getType() == Item::SPEAR)
            {
                (*iList)->setActive(true);
            }
            if(selectedPlayer->getSkillMap()->at("Sword Skill") >= (*iList)->getRequiredSkill() && (*iList)->getType() == Item::SWORD)
            {
                (*iList)->setActive(true);
            }
            std::cout << "Weapon type is " <<(*iList)->getType() <<std::endl;
            std::cout << std::boolalpha << (*iList)->getActive() << std::endl;
            iList++;
        }

        int x = 30;
        Axe->Draw(back->getPositionRect().x + scrpos + 200 ,back->getPositionRect().y + x);
        Mace->Draw(back->getPositionRect().x + scrpos + 200 ,back->getPositionRect().y + x*2);
        Spear->Draw(back->getPositionRect().x + scrpos + 200 ,back->getPositionRect().y + x*3);
        Sword->Draw(back->getPositionRect().x + scrpos + 200 ,back->getPositionRect().y + x*4);
        for (it=selectedPlayer->getSkillMap()->begin(); it!=selectedPlayer->getSkillMap()->end(); ++it)
        {
           std::cout << it->first << " => " << it->second << '\n';
        line1->setPosition(back->getPositionRect().x + scrpos ,back->getPositionRect().y + x);
        line1->setText(  it->first );
        line1->Display(game->getSetup());

        line1->setPosition(back->getPositionRect().x + scrpos*5 ,back->getPositionRect().y + x);
        line1->setText(  selectedPlayer->toString(it->second ));
        line1->Display(game->getSetup());
        x += 30;
        }
        std::cout <<"Available skills "<<selectedPlayer->getEntityLevel()->getSkillPoints() << std::endl;
        if(Axe->getPressed() && selectedPlayer->getEntityLevel()->getSkillPoints() > 0)
        {
            selectedPlayer->getSkillMap()->at("Axe Skill")++;

            selectedPlayer->getEntityLevel()->setSkillPoints(selectedPlayer->getEntityLevel()->getSkillPoints() -1);
            Axe->setPressed(false);
        }
        if(Mace->getPressed() && selectedPlayer->getEntityLevel()->getSkillPoints() > 0)
        {
            selectedPlayer->getSkillMap()->at("Mace Skill")++;

            selectedPlayer->getEntityLevel()->setSkillPoints(selectedPlayer->getEntityLevel()->getSkillPoints() -1);
            Mace->setPressed(false);
        }
        if(Spear->getPressed() && selectedPlayer->getEntityLevel()->getSkillPoints() > 0)
        {
            selectedPlayer->getSkillMap()->at("Spear Skill")++;

            selectedPlayer->getEntityLevel()->setSkillPoints(selectedPlayer->getEntityLevel()->getSkillPoints() -1);
            Spear->setPressed(false);
        }
        if(Sword->getPressed() && selectedPlayer->getEntityLevel()->getSkillPoints() > 0)
        {
            selectedPlayer->getSkillMap()->at("Sword Skill")++;

            selectedPlayer->getEntityLevel()->setSkillPoints(selectedPlayer->getEntityLevel()->getSkillPoints() -1);
            Sword->setPressed(false);
        }

        break;
    }
    }





}

void MenuState::HandleEvents(GameEngine *game)
{

    while(SDL_PollEvent(game->getSetup()->getMainEvent()))
    {
        Item->handleEvent();
        Equip->handleEvent();
        Skills->handleEvent();
        Weapon->handleEvent();
        Axe->handleEvent();
        Mace->handleEvent();
        Spear->handleEvent();
        Sword->handleEvent();

    }
    if(game->getSetup()->getMainEvent()->type == SDL_KEYDOWN)
    {

        if(game->getSetup()->getMainEvent()->key.keysym.sym == SDLK_ESCAPE)
        {
            if(state == STATE_INTRO)
            {
                exit = true;


            }

            if(state != STATE_INTRO)
            {

                exit = false;
            }


        }


    }
    if(game->getSetup()->getMainEvent()->type == SDL_KEYUP)
    {

        if(game->getSetup()->getMainEvent()->key.keysym.sym == SDLK_ESCAPE)
        {
            if(state != STATE_INTRO)
            {
                switchState(STATE_INTRO);


            }
            if(state == STATE_INTRO )
            {
                if(exit)
                {
                game->PopState();
                }
            }

        }
    }
}

void MenuState::Cleanup()
{
    delete back;
    delete options;
    delete line1;
    delete Item;
    delete Skills;
    delete Equip;
    delete Weapon;
    delete selected;
    selectedPlayer = NULL;
    delete selectedPlayer;
    buttons.clear();
}

void MenuState::Pause()
{

}

void MenuState::Resume(GameEngine *game)
{

}


MenuState::States MenuState::switchState(MenuState::States state)
{
    this->state = state;

}

bool MenuState::getExit() const
{
    return exit;
}

void MenuState::setExit(bool value)
{
    exit = value;
}
