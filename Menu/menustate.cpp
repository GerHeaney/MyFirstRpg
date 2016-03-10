#include "menustate.h"

MenuState MenuState::menu;



void MenuState::Init(GameEngine *game)
{   
    state = STATE_INTRO;
    back = new MenuSprite(game->getRenderer(),"resources/Menu/menuback.png");
    options = new MenuSprite(game->getRenderer(),"resources/menu/options.png");
    line1 = new DisplayField();
    Item = new FontButton(game->getSetup(),"Item");
    Equip = new FontButton(game->getSetup(),"Equip");
    Skills = new FontButton(game->getSetup(),"Skills");   
    Weapon = new FontButton(game->getSetup(),"Weapon");
    selected = new MenuSprite(game->getRenderer(),"resources/Battle/select.png");
    back->setSize(0,0,game->getScreenWidth()- options->getRect().w ,game->getScreenHeight());
    options->setPosition(game->getScreenWidth() - options->getRect().w,0);
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

                    (*i)->isSelected(game->getSetup());

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
                        switchState(STATE_EQUIP);
                        Weapon->setText(selectedPlayer->getWeapon()->getName());
                        Weapon->setInside(false);

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



         Weapon->Draw(selectedPlayer->getIcon()->getPositionRect().x + selectedPlayer->getIcon()->getPositionRect().w * 5,
                      selectedPlayer->getIcon()->getPositionRect().y + 90);

          std::cout <<std::boolalpha <<  Weapon->getInside();
         if(Weapon->getInside())
         {
             std::cout <<"inside weapon" << std::endl;
             selected->setPosition(Weapon->getPosition().x - selected->getRect().w,Weapon->getPosition().y + selected->getRect().h/2);
             selected->accept(&visitor);
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

    }
    if(game->getSetup()->getMainEvent()->key.keysym.sym == SDLK_ESCAPE)
    {
        game->PopState();
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
