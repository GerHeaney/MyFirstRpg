#include "menustate.h"

#include <Item/weapon.h>

MenuState MenuState::menu;



void MenuState::Init(GameEngine *game)
{   
    exit = false;
    state = STATE_INTRO;
    back = new MenuSprite(game->getRenderer(),"resources/Menu/menuback.png");
    options = new MenuSprite(game->getRenderer(),"resources/menu/options.png");
    line1 = new DisplayField();
    Items = new FontButton(game->getSetup(),"Item");
    Equip = new FontButton(game->getSetup(),"Equip");
    Skills = new FontButton(game->getSetup(),"Skills");   
    Weapons = new FontButton(game->getSetup(),"Weapon");
    Axe = new FontButton(game->getSetup(),">");
    Mace  = new FontButton(game->getSetup(),">");
    Spear = new FontButton(game->getSetup(),">");
    Sword = new FontButton(game->getSetup(),">");
    selected = new MenuSprite(game->getRenderer(),"resources/Battle/select.png");
    inventory = Inventory::partyInventory();
    for(std::list<Item*>::iterator i = inventory->getInventory()->begin();i!=inventory->getInventory()->end();)
    {
        std::cout << " item amount is " << (*i)->getQuantity() << std::endl;
       if((*i)->getType() == Item::POTION || (*i)->getType() == Item::ETHER)
       {
           items.push_back(new FontButton(game->getSetup(),(*i)->getName()));
       }
       if((*i)->getType() == Item::AXE || (*i)->getType() == Item::MACE|| (*i)->getType() == Item::SWORD|| (*i)->getType() == Item::SPEAR)
       {
           weapons.push_back(new FontButton(game->getSetup(),(*i)->getName()));
       }

        i++;

    }
    for(std::vector<FontButton*>::iterator i = items.begin();i!=items.end();)
    {
        std::cout << " item button is " << (*i)->getText();
        i++;
    }

    //Item->setPosition(options->getPositionRect().x,options->getPositionRect().y);

    buttons.push_back(Items);
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

        if(Items->getInside())
        {

            selected->setPosition(Items->getPosition().x - selected->getRect().w,Items->getPosition().y + selected->getRect().h/2);
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
            if(Items->getPressed())
            {
                Items->setPressed(false);

                switchState(STATE_ITEM);



            }
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
                    Weapons->setText(selectedPlayer->getWeapon()->getName());
                    Weapons->setInside(false);
                    selectedPlayer->setSelected(false);
                    Equip->setPressed(false);
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
                    Skills->setPressed(false);

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

        selectedPlayer->getWeapon()->getIcon()->setPosition(Weapons->getPosition().x -
                                                            selectedPlayer->getWeapon()->getIcon()->getPositionRect().w,Weapons->getPosition().y);
        selectedPlayer->getWeapon()->getIcon()->accept(&visitor);



        Weapons->Draw(selectedPlayer->getIcon()->getPositionRect().x + selectedPlayer->getWeapon()->getIcon()->getPositionRect().w
                      + selectedPlayer->getIcon()->getPositionRect().w * 5,
                      selectedPlayer->getIcon()->getPositionRect().y + 90);

        std::cout <<std::boolalpha <<  Weapons->getInside();
        if(Weapons->getInside())
        {
            std::cout <<"inside weapon" << std::endl;
            selected->setPosition(selectedPlayer->getWeapon()->getIcon()->getPositionRect().x - selectedPlayer->getWeapon()->getIcon()->getRect().w*1.5,
                                  selectedPlayer->getWeapon()->getIcon()->getPositionRect().y + selectedPlayer->getWeapon()->getIcon()->getPositionRect().h/2);
            selected->accept(&visitor);
        }
        for(std::vector<FontButton*>::iterator iBtn = weapons.begin();iBtn!=weapons.end();)
        {
            (*iBtn)->setPosition(back->getPositionRect().x + offset *3,back->getPositionRect().y+scrpos );
            (*iBtn)->Draw(back->getPositionRect().x + offset*3,back->getPositionRect().y+scrpos );


            for(std::list<Item*>::iterator iItm = inventory->getInventory()->begin();iItm!=inventory->getInventory()->end();)
            {

                if((*iBtn)->getText() == (*iItm)->getName())
                {
                    (*iItm)->getIcon()->setPosition(back->getPositionRect().x + offset,back->getPositionRect().y+scrpos );
                    (*iItm)->getIcon()->accept(&visitor);
                    line1->setPosition(back->getPositionRect().x + offset*11,back->getPositionRect().y+scrpos );
                    line1->setText(game->getParty()->front()->toString((*iItm)->getQuantity()));
                    line1->Display(game->getSetup());
                    if((*iBtn)->getPressed() && Weapons->getPressed() && !(*iItm)->getEquipped())
                    {
                        std::cout << selectedPlayer->getName()<< " just equipped " << (*iItm)->getName() << std::endl;
                        selectedPlayer->setWeapon((*iItm));
                        Weapons->setText((*iItm)->getName());
                        (*iBtn)->setPressed(false);
                        Weapons->setPressed(false);

                    }
                }


                iItm++;
            }


            scrpos+=35;
            if((*iBtn)->getInside())
            {
                std::cout <<"inside buttons loop of " << (*iBtn)->getText() << std::endl;
                selected->setPosition((*iBtn)->getPosition().x - selected->getRect().w,(*iBtn)->getPosition().y + selected->getRect().h/2);
                selected->accept(&visitor);
            }




            iBtn++;
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
    case(STATE_ITEM):
    {
        int scrpos = 35;

        int buttonpos = 35;

        back->setSize(0,0,game->getScreenWidth()- options->getRect().w ,game->getScreenHeight());
        options->setPosition(game->getScreenWidth() - options->getRect().w,100);
        back->accept(&visitor);
        options->accept(&visitor);
        for(std::vector<FontButton*>::iterator iBtn = items.begin();iBtn!=items.end();)
        {
            (*iBtn)->setPosition(options->getPositionRect().x + offset,options->getPositionRect().y+buttonpos );
            (*iBtn)->Draw(options->getPositionRect().x + offset,options->getPositionRect().y+buttonpos );


            for(std::list<Item*>::iterator iItm = inventory->getInventory()->begin();iItm!=inventory->getInventory()->end();)
            {

                if((*iBtn)->getText() == (*iItm)->getName())
                {
                    line1->setPosition(options->getPositionRect().x + offset*8,options->getPositionRect().y+buttonpos );
                    line1->setText(game->getParty()->front()->toString((*iItm)->getQuantity()));
                    line1->Display(game->getSetup());
                }

                iItm++;
            }


            buttonpos+=35;
            if((*iBtn)->getInside())
            {
                std::cout <<"inside buttons loop of " << (*iBtn)->getText() << std::endl;
                selected->setPosition((*iBtn)->getPosition().x - selected->getRect().w,(*iBtn)->getPosition().y + selected->getRect().h/2);
                selected->accept(&visitor);
            }
            //            if((*i)->getPressed())
            //            {
            //                std::cout <<"inside";
            //               state = 1;
            //            }


            iBtn++;
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


                scrpos += back->getRect().h/3;


                for(std::vector<FontButton*>::iterator iBtn = items.begin();iBtn!=items.end();)
                {
                    if((*iBtn)->getPressed())
                    {
                        (*i)->isSelected(game->getSetup(),(*i)->getIcon());

                        if((*i)->getMouseOver())
                        {
                            selected->setPosition((*i)->getIcon()->getPositionRect().x - selected->getRect().w,
                                                  (*i)->getIcon()->getPositionRect().y + selected->getRect().h/2);
                            selected->accept(&visitor);
                            std::cout << "over";

                        }
                    }

                    if( (*i)->getSelected() && (*iBtn)->getText() == "Potion" && (*iBtn)->getPressed())
                    {
                        (*i)->useItem((*i),"Potion");
                        (*i)->setSelected(false);
                        (*iBtn)->setPressed(false);
                        break;

                    }
                    if( (*i)->getSelected() && (*iBtn)->getText() == "Ether" && (*iBtn)->getPressed())
                    {
                        (*i)->useItem((*i),"Ether");
                        (*i)->setSelected(false);
                        (*iBtn)->setPressed(false);
                        break;

                    }
                    iBtn++;

                }




                i++;
            }

    }
        break;
    }





}

void MenuState::HandleEvents(GameEngine *game)
{

    while(SDL_PollEvent(game->getSetup()->getMainEvent()))
    {
        Items->handleEvent();
        Equip->handleEvent();
        Skills->handleEvent();
        Weapons->handleEvent();
        Axe->handleEvent();
        Mace->handleEvent();
        Spear->handleEvent();
        Sword->handleEvent();
        for(std::vector<FontButton*>::iterator i = items.begin();i!=items.end();)
        {
            (*i)->handleEvent();
            i++;
        }
        for(std::vector<FontButton*>::iterator i = weapons.begin();i!=weapons.end();)
        {
            (*i)->handleEvent();
            i++;
        }

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
    delete Items;
    delete Skills;
    delete Equip;
    delete Weapons;
    delete selected;
    delete Axe;
    delete Mace;
    delete Spear;
    delete Sword;
    selectedPlayer = NULL;
    delete selectedPlayer;

    for(std::vector<FontButton*>::iterator i = items.begin();i!=items.end();)
    {
        delete (*i);
        i++;
    }
    for(std::vector<FontButton*>::iterator i = weapons.begin();i!=weapons.end();)
    {
        delete (*i);
        i++;
    }
    buttons.clear();
    items.clear();
    weapons.clear();
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
