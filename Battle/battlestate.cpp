#include "battlestate.h"
#include "State/fieldstate.h"
#include "State/victorystate.h"


BattleState BattleState::battle;

void BattleState::Init(GameEngine *game)
{
    attackanim = new MovingSprite(game->getRenderer(),"resources/Battle/Attack.png");
    menu = new MenuSprite(game->getRenderer(),"resources/Battle/menu.png");
    background = new BackgroundSprite(game->getRenderer(),"resources/Battle/forest.png");
    selected = new MenuSprite(game->getRenderer(),"resources/Battle/select.png");
    infoBox = new MenuSprite(game->getRenderer(),"resources/Battle/infobox.png");
    enemy = new Enemy(game->getSetup(),"Old Hermit","resources/Battle/Hermit2.png");
    enemy2 = new Enemy(game->getSetup(),"Old Hermit 2","resources/Battle/Hermit4.png");
    playerField = new DisplayField();
    enemyField = new DisplayField();
    battleInfo = new DisplayField();
    Attack = new FontButton(game->getSetup(),"Attack");
    Ability = new FontButton(game->getSetup(),"Ability");
    Item = new FontButton(game->getSetup(),"Item");
    Skill1 = new FontButton(game->getSetup(),"Skill 1");
    Skill2 = new FontButton(game->getSetup(),"Skill 2");
    Skill3 = new FontButton(game->getSetup(),"Skill 3");
    battleMenu = new MenuSprite(game->getRenderer(),"resources/Battle/battleoptions.png");
    battleSystem = new BattleSystem();
    visitor = new DrawVisitor();


    enemies.push_back(enemy);
    enemies.push_back(enemy2);
    turnFlag = true;
    rewardXP = 0;
    srand(time(NULL));
    //new Entity(game->getSetup(),game->getScreenWidth()/4,game->getScreenHeight()-menu->getHeight()*1.5,"Hermit","resources/Battle/Hermit2.png");
    // player = game->getParty().front();
    //game->getParty()->back()->getSprite()->setPositionRect(game->getScreenWidth() - game->getScreenWidth()/4,game->getScreenHeight()-game->getScreenHeight()/3);

    int playerpos = 0;
    for(std::vector<Entity*>::iterator i = game->getParty()->begin();i!=game->getParty()->end();)
    {
        (*i)->getSprite()->setPositionRect(game->getScreenWidth() - game->getScreenWidth()/4 - playerpos,game->getScreenHeight()-game->getScreenHeight()/3 - playerpos);

        playerpos +=50;
        i++;

    }
    int spot = 0;
    for(std::vector<Entity*>::iterator i = enemies.begin();i!=enemies.end();)
    {



      (*i)->setOrigin(game->getScreenWidth()/4 + spot,game->getScreenHeight() - game->getScreenHeight()*0.4 - spot);
        rewardXP += (*i)->getExperience();
        std::cout << "reward xp is " << rewardXP << std::endl;
        i++;
        spot+=(100);


    }
    for(std::vector<Entity*>::iterator i = game->getParty()->begin();i!=game->getParty()->end();)
    {
        (*i)->getSprite()->setInitFrame(0,1);

        i++;

    }
   // enemies.front()->setOrigin(game->getScreenWidth()/4,game->getScreenHeight() - game->getScreenHeight()*0.4);
   // game->getParty()->front()->getSprite()->setInitFrame(0,1);
    background->setSize(game->getScreenWidth(),game->getScreenHeight());
    menu->setSize(0,game->getScreenHeight()-menu->getRect().h ,game->getScreenWidth(),menu->getRect().h);
    infoBox->setSize(game->getScreenWidth()/3,game->getScreenHeight()-game->getScreenHeight()*0.9,game->getScreenWidth()/3,infoBox->getRect().h*0.8);
    playerField->setPosition(game->getScreenWidth() - game->getScreenWidth()/3 ,game->getScreenHeight()-menu->getRect().h+ 100);
    enemyField->setPosition( 20,game->getScreenHeight()-menu->getRect().h+ 100);
    playerField->setText(game->getParty()->front()->getBattleStats());
    enemyField->setText(enemy->getBattleStats());
    battleInfo->setPosition(infoBox->getPositionRect().x + infoBox->getRect().w/10,infoBox->getPositionRect().y);

    attackanim->setPositionRect(500,500);
    attackanim->setupAnimation(7,1);
    attackanim->setInitFrame(0,0);
    battleSystem->setAttacks(*game->getParty(),true);
    Skill1->setPosition(battleMenu->getPositionRect().x +20,battleMenu->getPositionRect().y + 20);
    Skill2->setPosition(battleMenu->getPositionRect().x +20,battleMenu->getPositionRect().y + 50);
    Skill3->setPosition(battleMenu->getPositionRect().x +20,battleMenu->getPositionRect().y + 80);


    checkSkills(game);






}


void BattleState::HandleEvents(GameEngine *game)
{
    while(SDL_PollEvent(game->getSetup()->getMainEvent()))
    {
        Attack->handleEvent();
        Ability->handleEvent();
        Item->handleEvent();
        if( Skill1->getText() != "Skill 1")
        {
            Skill1->handleEvent();
        }
        if( Skill2->getText() != "Skill 2")
        {
            Skill2->handleEvent();
        }
        if(Skill3->getText() != "Skill 3")
        {
            Skill3->handleEvent();
        }

    }
    if(game->getSetup()->getMainEvent()->key.keysym.sym == SDLK_ESCAPE)
    {
        Attack->setPressed(false);
        Ability->setPressed(false);
        Skill1->setPressed(false);
        Skill2->setPressed(false);
        Skill3->setPressed(false);
        Item->setPressed(false);
        for(std::vector<Entity*>::iterator i = enemies.begin();i!=enemies.end();)
        {
          (*i)->setMouseOver(false);
            i++;
        }
    }
    //    std::cout <<std::boolalpha <<  Attack->getPressed();
    //       game->getParty().front()->attack(enemies.front());
    //      battleSystem->executeAttacks();
}
void BattleState::Update(GameEngine *game)
{
    int spot = 0;

    playerField->setText(game->getParty()->front()->getBattleStats());
    for(std::vector<Entity*>::iterator i = enemies.begin();i!=enemies.end();)
    {
        enemyField->setPosition( 20,game->getScreenHeight()-menu->getRect().h*0.9 + spot);
        enemyField->setText((*i)->getBattleStats());
        enemyField->Display(game->getSetup());
        spot +=30;
        i++;

    }
    int place = 0;
    for(std::vector<Entity*>::iterator i = game->getParty()->begin();i!=game->getParty()->end();)
    {
        playerField->setPosition(game->getScreenWidth() - game->getScreenWidth()/3 ,game->getScreenHeight()-menu->getRect().h*0.9+ place);
        playerField->setText((*i)->getBattleStats());
        playerField->Display(game->getSetup());
        place +=30;
        i++;
    }

    battleSystem->updateBattle(enemies,*game->getParty());
    if(battleSystem->getWinBattle())
    {

        std::cout <<" You won the battle";
        VictoryState::Instance()->setRewardXP(rewardXP);
        game->PushState(VictoryState::Instance());
        //game->PopState();
    }
  if(turnFlag)
    {
       PlayerTurn(game);
    }
    if(!turnFlag)
    {
        EnemyTurn(game);
    }
}
void BattleState::Draw(GameEngine *game)
{
    background->accept(visitor);
    infoBox->accept(visitor);
    for(std::vector<Entity*>::iterator i = enemies.begin();i!=enemies.end();)
    {
        if((*i)->getCurrentHealth() > 0)
        {

      (*i)->getSprite()->accept(visitor);
        }
        i++;
    }
    for(std::vector<Entity*>::iterator i = game->getParty()->begin();i!=game->getParty()->end();)
    {
        (*i)->getSprite()->accept(visitor);
        i++;
    }
   // game->getParty()->front()->getSprite()->accept(visitor);
   menu->accept(visitor);
   playerField->Display(game->getSetup());
   attackanim->accept(visitor);
}
void BattleState::Pause()
{

}
void BattleState::Resume(GameEngine *game)
{
    game->PopState();
    std::cout << "got to the battle resume" << std::endl;

}
void BattleState::Cleanup()
{
    delete attackanim;
    delete menu;
    delete background;
    delete selected;
    delete infoBox;
    delete enemy;
    delete enemy2;
    delete playerField;
    delete enemyField;
    delete battleInfo;
    delete Attack;
    delete Ability;
    delete Item;
    delete battleMenu;
  //  delete battleSystem;
    delete visitor;
    delete Skill1;
    delete Skill2;
    delete Skill3;


    enemies.clear();

}

void BattleState::chooseEnemy(GameEngine * game ,Entity * player, Entity * enemy)
{
    if(player->getCanAttack() == true && enemy->getSelected())
    {
        player->attack(enemy);
        enemy->setSelected(false);
        std::cout <<player->getName() << " attacks " << enemy->getName() <<std::endl;
        player->setCanAttack(false);
        Attack->setPressed(false);
        SDL_Delay(1000);

    }else{std::cout << player->getName() << " can't attack" << std::endl;}


}

void BattleState::drawBattleMenu(GameEngine * game)
{
    battleMenu->setSize(game->getScreenWidth()/2- battleMenu->getRect().w/2,game->getScreenHeight()-battleMenu->getRect().h, battleMenu->getRect().w, battleMenu->getRect().h);
    battleMenu->accept(visitor);
    Attack->Draw(battleMenu->getPositionRect().x +20,battleMenu->getPositionRect().y + 20);
    Ability->Draw(battleMenu->getPositionRect().x +20,battleMenu->getPositionRect().y + 55);
    Item->Draw(battleMenu->getPositionRect().x +20,battleMenu->getPositionRect().y + 90);
}

bool BattleState::PlayerTurn(GameEngine * game)
{


//     std::cout << "Attack is "<<std::boolalpha << Attack->getPressed() <<std::endl;
//      std::cout << "Ability is "<<std::boolalpha << Ability->getPressed()<<std::endl;
//       std::cout << "Item is "<<std::boolalpha << Item->getPressed()<<std::endl;
//        std::cout << "Skill1 is "<<std::boolalpha << Skill1->getPressed()<<std::endl;
//          std::cout << "Skill2 is "<<std::boolalpha << Skill2->getPressed()<<std::endl;
//           std::cout << "Skill3 is "<<std::boolalpha << Skill3->getPressed()<<std::endl;

        if( battleSystem->getPlayerTurn(*game->getParty())==true)
        {
            for(std::vector<Entity*>::iterator itrParty = game->getParty()->begin();itrParty < game->getParty()->end();  itrParty++)
            {
                    if((*itrParty)->getCanAttack())
                    {
                        for(std::vector<Entity*>::iterator itrEnemies = enemies.begin(); itrEnemies!= enemies.end(); itrEnemies++)
                        {
                            if(!Attack->getPressed() &&!Ability->getPressed() && battleSystem->getPlayerTurn(*game->getParty())==true)
                            {
                                drawBattleMenu(game);
                                battleInfo->setText("Its " +(*itrParty)->getName() + "'s turn select action" );
                                battleInfo->Display(game->getSetup());
                            }
                            // Attack enemy with equipped weapon
                            if(Attack->getPressed() == true)
                            {
                                Ability->setPressed(false);
                                std::cout << "Attack has been pressed";
                                battleInfo->setText("Select enemy to attack");
                                battleInfo->Display(game->getSetup());
                                if((*itrEnemies)->getCurrentHealth() > 0)
                                {
                                (*itrEnemies)->isSelected(game->getSetup());
                                }
                            }

                            // Use player abilities if they have enough skill points to use one
                            if(Ability->getPressed() == true && !Skill1->getPressed() && !Skill2->getPressed() && !Skill3->getPressed())
                            {
                                Attack->setPressed(false);
                                   std::cout << "Ability has been pressed";

                                battleInfo->setText("Select ability to use");
                                battleInfo->Display(game->getSetup());


                                battleMenu->setSize(game->getScreenWidth()/2- battleMenu->getRect().w/2 + battleMenu->getRect().w,game->getScreenHeight()-battleMenu->getRect().h, battleMenu->getRect().w, battleMenu->getRect().h);
                                battleMenu->accept(visitor);
                                drawSkillsMenu();
                            }

                                if(Skill1->getPressed() == true)
                                {

                                    std::cout << "skill is pressed";
                                    battleInfo->setText("Select enemy to attack");
                                    battleInfo->Display(game->getSetup());
                                    if((*itrEnemies)->getCurrentHealth() > 0)
                                    {
                                    (*itrEnemies)->isSelected(game->getSetup());
                                    }
                                    if(Skill1->getPressed() &&(*itrEnemies)->getSelected())
                                    {
                                        std::list<ISkill*>::iterator iList ;
                                        for(iList = (*itrParty)->getSkillList()->getSkillList()->begin();iList!=(*itrParty)->getSkillList()->getSkillList()->end();)
                                        {
                                            if((*iList)->getName() == Skill1->getText())
                                            {
                                                (*itrParty)->useAbility((*iList),(*itrEnemies));
                                                (*itrEnemies)->setSelected(false);
                                                (*itrParty)->setCanAttack(false);
                                                Skill1->setPressed(false);
                                                Ability->setPressed(false);
                                            }
                                            iList++;
                                        }

                                    }

                                }
                                if(Skill2->getPressed()== true)
                                {
                                    battleInfo->setText("Select enemy to attack");
                                    battleInfo->Display(game->getSetup());
                                    if((*itrEnemies)->getCurrentHealth() > 0)
                                    {
                                    (*itrEnemies)->isSelected(game->getSetup());
                                    }
                                    if(Skill2->getPressed() &&(*itrEnemies)->getSelected())
                                    {
                                        std::list<ISkill*>::iterator iList ;
                                        for(iList = (*itrParty)->getSkillList()->getSkillList()->begin();iList!=(*itrParty)->getSkillList()->getSkillList()->end();)
                                        {
                                            if((*iList)->getName() == Skill2->getText())
                                            {
                                                (*itrParty)->useAbility((*iList),(*itrEnemies));
                                                (*itrEnemies)->setSelected(false);
                                                (*itrParty)->setCanAttack(false);
                                                Skill2->setPressed(false);
                                                Ability->setPressed(false);
                                            }
                                            iList++;
                                        }

                                    }

                                }
                                if(Skill3->getPressed() == true)
                                {
                                    battleInfo->setText("Select enemy to attack");
                                    battleInfo->Display(game->getSetup());
                                    if((*itrEnemies)->getCurrentHealth() > 0)
                                    {
                                    (*itrEnemies)->isSelected(game->getSetup());
                                    }
                                    if(Skill3->getPressed() &&(*itrEnemies)->getSelected())
                                    {
                                        std::list<ISkill*>::iterator iList ;
                                        for(iList = (*itrParty)->getSkillList()->getSkillList()->begin();iList!=(*itrParty)->getSkillList()->getSkillList()->end();)
                                        {
                                            if((*iList)->getName() == Skill3->getText())
                                            {
                                                (*itrParty)->useAbility((*iList),(*itrEnemies));
                                                (*itrEnemies)->setSelected(false);
                                                (*itrParty)->setCanAttack(false);
                                                Skill3->setPressed(false);
                                                Ability->setPressed(false);
                                            }
                                            iList++;
                                        }

                                    }
                                }



                            if(!(*itrEnemies)->getMouseOver())
                            {

                            }
                            else if((*itrEnemies)->getMouseOver())
                            {
                                selected->setPosition((*itrEnemies)->getSprite()->getPositionRect().x-(*itrEnemies)->getSprite()->getPositionRect().w/2
                                                        ,(*itrEnemies)->getSprite()->getPositionRect().y + (*itrEnemies)->getSprite()->getRect().h/2);
                                selected->accept(visitor);
                            }
//                        std::cout << "Enemy is selected is "<<std::boolalpha << (*itrEnemies)->getSelected();
//                        std::cout << (*itrParty)->getName() <<" has attacked "<<(*itrEnemies)->getName();
                            if(Attack->getPressed() && (*itrEnemies)->getSelected())
                            {
                               // chooseEnemy(game,(*itrParty),(*itrEnemies));
                                  (*itrParty)->attack((*itrEnemies));
                                (*itrEnemies)->setSelected(false);
                                (*itrParty)->setCanAttack(false);
                                Attack->setPressed(false);
                            }



                            if(Item->getPressed())
                            {

                            }

                    }
                        break;
                }
            }

        return true;

    }else{turnFlag = false;

        battleSystem->setAttacks(enemies,true);
     //   std::cout << "got to the else in player turn and should consider putting the turnflag and attacks here" << std::endl;
        return false;}

}

bool BattleState::EnemyTurn(GameEngine *game)
{


    if(battleSystem->getEnemyTurn(enemies))
    {
        battleInfo->setText("Enemy Turn");
        std::cout << "enemyturn" << std::endl;
        battleInfo->Display(game->getSetup());
             SDL_Delay(1000);

            for(std::vector<Entity*>::iterator i = enemies.begin();i!=enemies.end();)
            {

                if((*i)->getCanAttack() == true && (*i)->getCurrentHealth() > 0)
               {
                    int  x = rand() % game->getParty()->size();

                    SDL_Delay(1000);
                    (*i)->attack(game->getParty()->at(x));



                   (*i)->setCanAttack(false);

                    break;
                    }else{std::cout << (*i)->getName() << " can't attack" << std::endl;}

               i++;



            }
            return true;
    }else{
        turnFlag = true;
        battleSystem->setAttacks(*game->getParty(),true);
        return false;
    }





//    if(!battleSystem->getEnemyTurn(enemies))
//    {
//        PlayerTurn(game);
//    }


}
void BattleState::drawSkillsMenu()
{
    if( Skill1->getText() != "Skill 1")
    {
        Skill1->Draw(battleMenu->getPositionRect().x +20,battleMenu->getPositionRect().y + 20);
    }
    if( Skill2->getText() != "Skill 2")
    {
        Skill2->Draw(battleMenu->getPositionRect().x +20,battleMenu->getPositionRect().y + 55);
    }
    if(Skill3->getText() != "Skill 3")
    {
        Skill3->Draw(battleMenu->getPositionRect().x +20,battleMenu->getPositionRect().y + 90);
    }
}
void BattleState::checkSkills(GameEngine * game)
{

    std::list<ISkill*>::iterator iList ;
    for(std::vector<Entity*>::iterator itrParty = game->getParty()->begin();itrParty < game->getParty()->end();  itrParty++)
    {
        for(iList = (*itrParty)->getSkillList()->getSkillList()->begin();iList!=(*itrParty)->getSkillList()->getSkillList()->end();)
        {
            if((*itrParty)->getSkillMap()->at("Axe Skill") >= (*iList)->getRequiredSkill() && (*iList)->getType() == Item::AXE)
            {
                if((*itrParty)->getWeapon()->getType() == Item::AXE)
                {
                    if((*iList)->getRequiredSkill() == 5)
                    {
                        std::cout <<" got to the assignment of the axe skill ";
                        Skill1->setText((*iList)->getName());
                    }
                    if((*iList)->getRequiredSkill() == 10)
                    {
                        Skill2->setText((*iList)->getName());
                    }
                    if((*iList)->getRequiredSkill() == 20)
                    {
                        Skill3->setText((*iList)->getName());
                    }

                    (*iList)->setActive(true);
                }
            }
            if((*itrParty)->getSkillMap()->at("Mace Skill") >= (*iList)->getRequiredSkill() && (*iList)->getType() == Item::MACE)
            {
                if((*itrParty)->getWeapon()->getType() == Item::MACE)
                {
                    if((*iList)->getRequiredSkill() == 5)
                    {
                        Skill1->setText((*iList)->getName());
                    }
                    if((*iList)->getRequiredSkill() == 10)
                    {
                        Skill2->setText((*iList)->getName());
                    }
                    if((*iList)->getRequiredSkill() == 20)
                    {
                        Skill3->setText((*iList)->getName());
                    }

                    (*iList)->setActive(true);
                }
            }
            if((*itrParty)->getSkillMap()->at("Spear Skill") >= (*iList)->getRequiredSkill() && (*iList)->getType() == Item::SPEAR)
            {
                if((*itrParty)->getWeapon()->getType() == Item::SPEAR)
                {
                    if((*iList)->getRequiredSkill() == 5)
                    {
                        Skill1->setText((*iList)->getName());
                    }
                    if((*iList)->getRequiredSkill() == 10)
                    {
                        Skill2->setText((*iList)->getName());
                    }
                    if((*iList)->getRequiredSkill() == 20)
                    {
                        Skill3->setText((*iList)->getName());
                    }

                    (*iList)->setActive(true);
                }
            }
            if((*itrParty)->getSkillMap()->at("Sword Skill") >= (*iList)->getRequiredSkill() && (*iList)->getType() == Item::SWORD)
            {
                if((*itrParty)->getWeapon()->getType() == Item::SWORD)
                {
                    if((*iList)->getRequiredSkill() == 5)
                    {
                        std::cout <<" got to the assignment of the sword skill ";
                        Skill1->setText((*iList)->getName());
                    }
                    if((*iList)->getRequiredSkill() == 10)
                    {
                        Skill2->setText((*iList)->getName());
                    }
                    if((*iList)->getRequiredSkill() == 20)
                    {
                        Skill3->setText((*iList)->getName());
                    }

                    (*iList)->setActive(true);
                }
            }
            std::cout << "Weapon type is " <<(*iList)->getType() <<std::endl;
            std::cout << std::boolalpha << (*iList)->getActive() << std::endl;
            iList++;
        }
    }
}
