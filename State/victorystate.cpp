#include "victorystate.h"

VictoryState VictoryState::victory;

void VictoryState::Init(GameEngine *game)
{
    clicked = false;
    counter = 0;
   // rewardXP = 100;
    textRow = new MenuSprite(game->getRenderer(),"resources/Battle/infobox.png");
    expRow = new MenuSprite(game->getRenderer(),"resources/Battle/infobox.png");
    goldRow = new MenuSprite(game->getRenderer(),"resources/Battle/infobox.png");
    player1Row = new MenuSprite(game->getRenderer(),"resources/Battle/victoryrow.png");
    player2Row = new MenuSprite(game->getRenderer(),"resources/Battle/victoryrow.png");
    player3Row = new MenuSprite(game->getRenderer(),"resources/Battle/victoryrow.png");
    line1 = new DisplayField();
    textRow->setSize(0,0,game->getScreenWidth(),textRow->getSurface()->h);
    expRow->setSize(0,textRow->getSurface()->h,game->getScreenWidth()/2,expRow->getSurface()->h);
    goldRow->setSize(game->getScreenWidth()/2,textRow->getSurface()->h,game->getScreenWidth()/2,goldRow->getSurface()->h);
    player1Row->setSize(0,expRow->getPositionRect().y + expRow->getPositionRect().h,game->getScreenWidth(),player1Row->getRect().h);
    player2Row->setSize(0,player1Row->getPositionRect().y + player1Row->getPositionRect().h,game->getScreenWidth(),player2Row->getRect().h);
    player3Row->setSize(0,player2Row->getPositionRect().y + player2Row->getPositionRect().h,game->getScreenWidth(),player3Row->getRect().h);
    rows.push_back(player1Row);
    rows.push_back(player2Row);
    rows.push_back(player3Row);
    levelcheck = game->getParty()->front()->getEntityLevel()->getCurrentLevel();
  //  game->getParty()->front()->getEntityLevel()->setuplevels(300,350000,30);
    std::cout << "got to the victory state" << std::endl;


}

void VictoryState::Update(GameEngine *game)
{
if(counter == 2)
{
    game->PopState();
}
}

void VictoryState::Draw(GameEngine *game)
{

    DrawVisitor visitor;
    player1Row->accept(&visitor);
    player2Row->accept(&visitor);
    player3Row->accept(&visitor);
    textRow->accept(&visitor);
    expRow->accept(&visitor);
    goldRow->accept(&visitor);
    std::vector<Entity *>::iterator i = game->getParty()->begin();
    std::vector<MenuSprite*>::iterator j = rows.begin();
    for( ;i<game->getParty()->end() && j<rows.end();)
    {
        (*i)->getIcon()->setPositionRect(scrPos,(*j)->getPositionRect().y + scrPos);
        (*i)->getIcon()->accept(&visitor);
        line1->setPosition((*i)->getIcon()->getPositionRect().x+(*i)->getIcon()->getPositionRect().w ,(*i)->getIcon()->getPositionRect().y);
        line1->setText((*i)->getName());
        line1->Display(game->getSetup());
        line1->setText("Level: " + (*i)->toString((*i)->getEntityLevel()->getCurrentLevel()));
        line1->setPosition((*i)->getIcon()->getPositionRect().x+(*i)->getIcon()->getPositionRect().w ,(*i)->getIcon()->getPositionRect().y + scrPos);
        line1->Display(game->getSetup());
        line1->setPosition((*i)->getIcon()->getPositionRect().x+(*i)->getIcon()->getPositionRect().w*2 ,(*i)->getIcon()->getPositionRect().y);
        line1->setText("Current EXP: " + (*i)->toString((*i)->getEntityLevel()->getCurrentXP()));
        line1->Display(game->getSetup());
        line1->setPosition((*i)->getIcon()->getPositionRect().x+(*i)->getIcon()->getPositionRect().w*4 ,(*i)->getIcon()->getPositionRect().y);
        line1->setText("EXP for next level: " + (*i)->toString((*i)->getEntityLevel()->getRequiredXP()));
        line1->Display(game->getSetup());
        if((*i)->getEntityLevel()->getCurrentLevel() > levelcheck)
        {
            line1->setPosition((*i)->getIcon()->getPositionRect().x+(*i)->getIcon()->getPositionRect().w*2 ,(*i)->getIcon()->getPositionRect().y+ scrPos);
            line1->setText("Level UP");
            line1->Display(game->getSetup());
        }
        i++;
        j++;



    }
    //first line it the window
    line1->setPosition(textRow->getPositionRect().x + scrPos,textRow->getPositionRect().y + textRow->getPositionRect().h/3);
    line1->setText("EXP and gold gained.");
    line1->Display(game->getSetup());

    //row for experience earned from the battle
    line1->setPosition(expRow->getPositionRect().x + scrPos,expRow->getPositionRect().y + expRow->getPositionRect().h/3);
    line1->setText("EXP   " + line1->toString(rewardXP));
    line1->Display(game->getSetup());

    //row for the gold earned from the battle
    line1->setPosition(goldRow->getPositionRect().x + scrPos,goldRow->getPositionRect().y + goldRow->getPositionRect().h/3);
    line1->setText("Gold   " + line1->toString(rewardXP));
    line1->Display(game->getSetup());

}

void VictoryState::HandleEvents(GameEngine *game)
{
    while(SDL_PollEvent(game->getSetup()->getMainEvent()))
    {
    screenClick(game);
    }

}

void VictoryState::Cleanup()
{
    delete textRow;
    delete expRow;
    delete goldRow;
    delete player1Row;
    delete player2Row;
    delete player3Row;
    delete line1;
    rows.clear();

}

void VictoryState::Pause()
{

}

void VictoryState::Resume(GameEngine *game)
{

}
void VictoryState::screenClick(GameEngine * game)
{


    //Get mouse position
    int x, y;
    SDL_GetMouseState( &x, &y );

    //Check if mouse is in button
    bool inside = true;
    if( x >game->getScreenWidth())
    {
        inside = false;
    }
    else if( y > game->getScreenHeight())
    {
        inside = false;
    }

    //Mouse is outside button
    if( !inside )
    {

    }
    //Mouse is inside button
    else
    {
        // while(SDL_PollEvent(setup->getMainEvent()) != 0)

        //Set mouse over sprite
        switch( game->getSetup()->getMainEvent()->type )
        {
        case SDL_MOUSEBUTTONDOWN:

            std::cout <<"pressed" << std::endl;

            clicked = false;
            SDL_Delay(500);



            break;

        case SDL_MOUSEBUTTONUP:
            clicked = true;
            if(clicked)
            {
                for(std::vector<Entity*>::iterator i = game->getParty()->begin();i!=game->getParty()->end();)
                {
                    std::cout << " before add current xp is " << (*i)->getEntityLevel()->getCurrentXP() << std::endl;
                    (*i)->getEntityLevel()->setCurrentXP((*i)->getEntityLevel()->getCurrentXP() + rewardXP);
                    std::cout << "after add current xp is " << (*i)->getEntityLevel()->getCurrentXP() << std::endl;
                    (*i)->getEntityLevel()->setRequiredXP((*i)->getEntityLevel()->getRequiredXP() - rewardXP);
                    if((*i)->getEntityLevel()->getRequiredXP() <= 0)
                    {

                        (*i)->levelUP();

                    }

                    i++;


                    std::cout << "counter is" << counter << std::endl;

                }
                rewardXP = 0;
                counter++;
            }


            clicked = false;
            SDL_Delay(300);




            break;
        }


    }




}



int VictoryState::getRewardXP() const
{
    return rewardXP;
}

void VictoryState::setRewardXP(int value)
{
    rewardXP = value;
}

bool VictoryState::getClicked() const
{
    return clicked;
}

void VictoryState::setClicked(bool value)
{
    clicked = value;
}
