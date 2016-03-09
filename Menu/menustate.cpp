#include "menustate.h"

MenuState MenuState::menu;



void MenuState::Init(GameEngine *game)
{
    state = 0;
    back = new MenuSprite(game->getRenderer(),"resources/Menu/menuback.png");
    options = new MenuSprite(game->getRenderer(),"resources/menu/options.png");
    line1 = new DisplayField();
    Item = new FontButton(game->getSetup(),"Item");
    Equip = new FontButton(game->getSetup(),"Equip");
    Skills = new FontButton(game->getSetup(),"Skills");
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
        back->accept(&visitor);
        options->accept(&visitor);


        int scrpos = 35;

        if(Item->getInside())
        {
            std::cout <<"inside";
            selected->setPosition(Item->getPosition().x - selected->getRect().w,Item->getPosition().y + selected->getRect().h/2);
            selected->accept(&visitor);
        }


        int buttonpos = 35;

        for(std::vector<FontButton*>::iterator i = buttons.begin();i<buttons.end();)
        {
            (*i)->Draw(options->getPositionRect().x + offset,options->getPositionRect().y+buttonpos );

            buttonpos+=35;
            if((*i)->getInside())
            {
                std::cout <<"inside";
                selected->setPosition((*i)->getPosition().x - selected->getRect().w,(*i)->getPosition().y + selected->getRect().h/2);
                selected->accept(&visitor);
            }
            if((*i)->getPressed())
            {
                std::cout <<"inside";
               state = 1;
            }
             i++;
        }

        for(std::vector<Entity *>::iterator i = game->getParty()->begin();i<game->getParty()->end();)
        {
            (*i)->getIcon()->setPositionRect(30,scrpos);
            (*i)->getIcon()->accept(&visitor);
            line1->setPosition((*i)->getIcon()->getPositionRect().x+(*i)->getIcon()->getPositionRect().w+ (*i)->getIcon()->getPositionRect().w/3 ,(*i)->getIcon()->getPositionRect().y);
            line1->setText((*i)->getName());
            line1->Display(game->getSetup());
            line1->setText("LV: " + (*i)->toString((*i)->getEntityLevel()->getCurrentLevel()));
            line1->setPosition((*i)->getIcon()->getPositionRect().x+(*i)->getIcon()->getPositionRect().w+ (*i)->getIcon()->getPositionRect().w/3 ,(*i)->getIcon()->getPositionRect().y + 30);
            line1->Display(game->getSetup());
            line1->setText("HP: " + (*i)->toString((*i)->getCurrentHealth()) + "/" +(*i)->toString((*i)->getMaxHealth()));
            line1->setPosition((*i)->getIcon()->getPositionRect().x+(*i)->getIcon()->getPositionRect().w+ (*i)->getIcon()->getPositionRect().w/3 ,(*i)->getIcon()->getPositionRect().y + 60);
            line1->Display(game->getSetup());
            line1->setPosition((*i)->getIcon()->getPositionRect().x+(*i)->getIcon()->getPositionRect().w+ (*i)->getIcon()->getPositionRect().w/3,(*i)->getIcon()->getPositionRect().y + 90);
            line1->setText("AP: " + (*i)->toString((*i)->getAbilityPower()) + "/" +(*i)->toString((*i)->getMaxAP()));
            line1->Display(game->getSetup());
            line1->setPosition((*i)->getIcon()->getPositionRect().x+(*i)->getIcon()->getPositionRect().w*2 ,(*i)->getIcon()->getPositionRect().y);
            line1->setText("Current EXP: " + (*i)->toString((*i)->getEntityLevel()->getCurrentXP()));
            line1->Display(game->getSetup());
            line1->setPosition((*i)->getIcon()->getPositionRect().x+(*i)->getIcon()->getPositionRect().w*4 ,(*i)->getIcon()->getPositionRect().y);
            line1->setText("EXP for next level: " + (*i)->toString((*i)->getEntityLevel()->getRequiredXP()));
            line1->Display(game->getSetup());

            scrpos += back->getRect().h/3;
            i++;
        }
         break;

    }





}

void MenuState::HandleEvents(GameEngine *game)
{
    while(SDL_PollEvent(game->getSetup()->getMainEvent()))
    {
        Item->handleEvent();
        Equip->handleEvent();
        Skills->handleEvent();

    }

}

void MenuState::Cleanup()
{

}

void MenuState::Pause()
{

}

void MenuState::Resume(GameEngine *game)
{

}
