#include "battlestate.h"
#include "State/fieldstate.h"
#include "State/victorystate.h"

#include "Item/item.h"
#include "Item/ether.h"



BattleState BattleState::battle;

void BattleState::Init(GameEngine *game)
{
    attackanim = new MovingSprite(game->getRenderer(),"resources/Battle/Attack.png");
    menu = new MenuSprite(game->getRenderer(),"resources/Battle/menu.png");
    background = new BackgroundSprite(game->getRenderer(),"resources/Battle/forest.png");
    selected = new MenuSprite(game->getRenderer(),"resources/Battle/select.png");
    infoBox = new MenuSprite(game->getRenderer(),"resources/Battle/infobox.png");
    playerField = new DisplayField();
    enemyField = new DisplayField();
    battleInfo = new DisplayField();
    Attack = new FontButton(game->getSetup(),"Attack");
    Ability = new FontButton(game->getSetup(),"Ability");
    Items = new FontButton(game->getSetup(),"Item");
    Skill1 = new FontButton(game->getSetup(),"Skill 1");
    Skill2 = new FontButton(game->getSetup(),"Skill 2");
    Skill3 = new FontButton(game->getSetup(),"Skill 3");
    Potions = new FontButton(game->getSetup(),"Item 1");
    Ethers = new FontButton(game->getSetup(),"Item 2");
    Revives = new FontButton(game->getSetup(),"Item 3");
    battleMenu = new MenuSprite(game->getRenderer(),"resources/Battle/battleoptions.png");
    battleSystem = new BattleSystem();
    visitor = new DrawVisitor();   


    Inventory *inventory = inventory->partyInventory();

    inventory->addItem(new Weapon(game->getSetup(),Item::AXE,"Battle Axe",200,100,"resources/Items/axe.png"));

    for(std::list<Item*>::iterator i = inventory->getInventory()->begin();i!=inventory->getInventory()->end();)
    {
        std::cout  << (*i)->getName() << "  x"<< (*i)->getQuantity() << std::endl;
        i++;

    }




    turnFlag = true;
    rewardXP = 0;
    srand(time(NULL));
    //new Entity(game->getSetup(),game->getScreenWidth()/4,game->getScreenHeight()-menu->getHeight()*1.5,"Hermit","resources/Battle/Hermit2.png");
    // player = game->getParty().front();
    //game->getParty()->back()->getSprite()->setPositionRect(game->getScreenWidth() - game->getScreenWidth()/4,game->getScreenHeight()-game->getScreenHeight()/3);

    int playerpos = 0;
    for(std::vector<Entity*>::iterator i = game->getParty()->begin();i!=game->getParty()->end();)
    {
        (*i)->getSprite()->setPositionRect(game->getScreenWidth() - game->getScreenWidth()/3 + playerpos,game->getScreenHeight()-game->getScreenHeight()/2 + playerpos);

        playerpos +=50;
        i++;

    }

    for(std::vector<Entity*>::iterator i = game->getParty()->begin();i!=game->getParty()->end();)
    {
        std::cout<<(*i)->getName() << " has " <<(*i)->getWeapon()->getName() << " equipped" << std::endl;
        (*i)->getSprite()->setInitFrame(0,1);

        i++;

    }
   // enemies.front()->setOrigin(game->getScreenWidth()/4,game->getScreenHeight() - game->getScreenHeight()*0.4);
   // game->getParty()->front()->getSprite()->setInitFrame(0,1);
    background->setSize(game->getScreenWidth(),game->getScreenHeight());
    menu->setSize(0,game->getScreenHeight()-menu->getRect().h ,game->getScreenWidth(),menu->getRect().h);
    infoBox->setSize(game->getScreenWidth()/3,game->getScreenHeight()-game->getScreenHeight()*0.95,game->getScreenWidth()/3,infoBox->getRect().h*0.8);
    playerField->setPosition(game->getScreenWidth() - game->getScreenWidth()/3 ,game->getScreenHeight()-menu->getRect().h+ 100);
    enemyField->setPosition( 20,game->getScreenHeight()-menu->getRect().h+ 100);

    battleInfo->setPosition(infoBox->getPositionRect().x + infoBox->getRect().w/30,infoBox->getPositionRect().y);

    attackanim->setPositionRect(500,500);
    attackanim->setupAnimation(7,1);
    attackanim->setInitFrame(0,0);
    battleSystem->setAttacks(*game->getParty(),true);
    Skill1->setPosition(battleMenu->getPositionRect().x +20,battleMenu->getPositionRect().y + buttonOffset);
    Skill2->setPosition(battleMenu->getPositionRect().x +20,battleMenu->getPositionRect().y + buttonOffset*2);
    Skill3->setPosition(battleMenu->getPositionRect().x +20,battleMenu->getPositionRect().y + buttonOffset*3);

    Potions->setPosition(battleMenu->getPositionRect().x +20,battleMenu->getPositionRect().y + buttonOffset);
    Ethers->setPosition(battleMenu->getPositionRect().x +20,battleMenu->getPositionRect().y + buttonOffset*2);
    Revives->setPosition(battleMenu->getPositionRect().x +20,battleMenu->getPositionRect().y + buttonOffset*3);





    pos1.x =game->getScreenWidth()*0.05;
    pos1.y =game->getScreenHeight() - game->getScreenHeight()*0.8;
    pos2.x =game->getScreenWidth()*0.25;
    pos2.y =game->getScreenHeight() -game->getScreenHeight()*0.8;
    pos3.x =game->getScreenWidth()*0.05;
    pos3.y =game->getScreenHeight() - game->getScreenHeight()*0.5;
    pos4.x = game->getScreenWidth()*0.25;
    pos4.y = game->getScreenHeight() - game->getScreenHeight()*0.5;

    positions.push_back(pos1);
    positions.push_back(pos2);
    positions.push_back(pos3);
    positions.push_back(pos4);

    setEnemies(game);






}


void BattleState::HandleEvents(GameEngine *game)
{


    while(SDL_PollEvent(game->getSetup()->getMainEvent()))
    {
        Attack->handleEvent();
        Ability->handleEvent();
        Items->handleEvent();

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


            if(Potions->getText() != "Item 1")
            {
                Potions->handleEvent();
            }
            if(Ethers->getText() != "Item 2")
            {
                Ethers->handleEvent();
            }
            if(Revives->getText() != "Item 3")
            {
                Revives->handleEvent();
            }



    }
    if(game->getSetup()->getMainEvent()->key.keysym.sym == SDLK_ESCAPE)
    {
        Attack->setPressed(false);
        Ability->setPressed(false);
        Skill1->setPressed(false);
        Skill2->setPressed(false);
        Skill3->setPressed(false);
        Items->setPressed(false);
        Potions->setPressed(false);
        Ethers->setPressed(false);
        Revives->setPressed(false);
//        for(std::vector<Entity*>::iterator i = enemies.begin();i!=enemies.end();)
//        {
//            (*i)->setSelected(false);
//          (*i)->setMouseOver(false);
//            i++;
//        }
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
        if((*i)->getCurrentHealth() >0)
        {
            enemyField->setPosition( 20,game->getScreenHeight()-menu->getRect().h*0.9 + spot);
            enemyField->setText((*i)->getBattleStats());
            enemyField->Display(game->getSetup());
            spot +=30;
        }
        i++;

    }
    int place = 0;
    for(std::vector<Entity*>::iterator i = game->getParty()->begin();i!=game->getParty()->end();)
    {
        playerField->setPosition(game->getScreenWidth() - game->getScreenWidth()*0.4 ,game->getScreenHeight()-menu->getRect().h*0.9+ place);
        playerField->setText((*i)->getName() + " HP:  "+(*i)->toString((*i)->getCurrentHealth()) + "/" + (*i)->toString((*i)->getMaxHealth())
                             +"  AP: " + (*i)->toString((*i)->getAbilityPower()) + "/" + (*i)->toString((*i)->getMaxAP()));
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
    if(battleSystem->getLostBattle())
    {
        game->PushState(GameOver::Instance());
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
    delete playerField;
    delete enemyField;
    delete battleInfo;
    delete Attack;
    delete Ability;
    delete Items;
    delete battleMenu;
    delete battleSystem;
    delete visitor;
    delete Skill1;
    delete Skill2;
    delete Skill3;
    delete Potions;
    delete Ethers;
    delete Revives;


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
    Attack->Draw(battleMenu->getPositionRect().x +20,battleMenu->getPositionRect().y + buttonOffset);
    Ability->Draw(battleMenu->getPositionRect().x +20,battleMenu->getPositionRect().y + buttonOffset*2);
    Items->Draw(battleMenu->getPositionRect().x +20,battleMenu->getPositionRect().y + buttonOffset*3);
}

bool BattleState::PlayerTurn(GameEngine * game)
{



//     std::cout << "Attack is "<<std::boolalpha << Attack->getPressed() <<std::endl;
//      std::cout << "Ability is "<<std::boolalpha << Ability->getPressed()<<std::endl;
//       std::cout << "Item is "<<std::boolalpha << Items->getPressed()<<std::endl;
//       std::cout << "Potions is "<<std::boolalpha << Potions->getPressed()<<std::endl;
//       std::cout << "Ethers is "<<std::boolalpha << Ethers->getPressed()<<std::endl;
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
                            if(!Attack->getPressed() &&!Ability->getPressed() &&!Items->getPressed() && battleSystem->getPlayerTurn(*game->getParty())==true)
                            {
                                drawBattleMenu(game);
                                battleInfo->setText("Its " +(*itrParty)->getName() + "'s turn select action" );
                                battleInfo->Display(game->getSetup());
                            }
                            // Attack enemy with equipped weapon
                            if(Attack->getPressed() == true)
                            {

                                Ability->setPressed(false);
                                Items->setPressed(false);
                                Skill1->setPressed(false);
                                Skill2->setPressed(false);
                                Skill3->setPressed(false);
                                Potions->setPressed(false);
                                Ethers->setPressed(false);
                                Revives->setPressed(false);

                              //  std::cout << "Attack has been pressed";

                                if((*itrEnemies)->getCurrentHealth() > 0)
                                {
                                (*itrEnemies)->isSelected(game->getSetup(),(*itrEnemies)->getSprite());
                                }
                                if(!(*itrEnemies)->getMouseOver())
                                {


                                }
                                else if((*itrEnemies)->getMouseOver())
                                {

                                    battleInfo->setText("Attack " + (*itrEnemies)->getName());
                                    battleInfo->Display(game->getSetup());
                                    selected->setPosition((*itrEnemies)->getSprite()->getPositionRect().x-(*itrEnemies)->getSprite()->getPositionRect().w/6
                                                            ,(*itrEnemies)->getSprite()->getPositionRect().y + (*itrEnemies)->getSprite()->getRect().h/2);
                                    selected->accept(visitor);
                                }
                            }
                            if(Attack->getPressed() && (*itrEnemies)->getSelected())
                            {
                               // chooseEnemy(game,(*itrParty),(*itrEnemies));
                                  (*itrParty)->attack((*itrEnemies));
                                (*itrEnemies)->setSelected(false);
                                (*itrParty)->setCanAttack(false);
                                Attack->setPressed(false);
                            }

                            // Use player abilities if they have enough skill points to use one
                            if(Ability->getPressed() == true && !Skill1->getPressed() && !Skill2->getPressed() && !Skill3->getPressed())
                            {


                                Potions->setPosition(0,0);
                                Ethers->setPosition(0,0);
                                Revives->setPosition(0,0);

                                checkSkills(game,(*itrParty));
                                Attack->setPressed(false);
                                Items->setPressed(false);
                                Potions->setPressed(false);
                                Ethers->setPressed(false);
                                Revives->setPressed(false);
                         //          std::cout << "Ability has been pressed";

                                battleInfo->setText("Select ability to use");
                                battleInfo->Display(game->getSetup());


                                battleMenu->setSize(game->getScreenWidth()/2- battleMenu->getRect().w/2 + battleMenu->getRect().w,game->getScreenHeight()-battleMenu->getRect().h, battleMenu->getRect().w, battleMenu->getRect().h);
                                battleMenu->accept(visitor);
                                drawSkillsMenu();
                            }

                                if(Skill1->getPressed() == true && (*itrParty)->getAbilityPower() >=(*itrParty)->getSkillList()->getSkill((*itrParty)->getWeapon()->getType(),5)->getCost()
                                        && (*itrParty)->getAbilityPower() - (*itrParty)->getSkillList()->getSkill((*itrParty)->getWeapon()->getType(),5)->getCost() >=0)
                                {
                                    if((*itrEnemies)->getCurrentHealth() > 0)
                                    {
                                    (*itrEnemies)->isSelected(game->getSetup(),(*itrEnemies)->getSprite());
                                        if(!(*itrEnemies)->getMouseOver())
                                        {


                                        }
                                        else if((*itrEnemies)->getMouseOver())
                                        {
                                            battleInfo->setText("Use " +Skill1->getText()+ " on " + (*itrEnemies)->getName());
                                            battleInfo->Display(game->getSetup());
                                            selected->setPosition((*itrEnemies)->getSprite()->getPositionRect().x-(*itrEnemies)->getSprite()->getPositionRect().w/6
                                                                    ,(*itrEnemies)->getSprite()->getPositionRect().y + (*itrEnemies)->getSprite()->getRect().h/2);
                                            selected->accept(visitor);
                                        }
                                    }

                                    if(Skill1->getPressed() &&(*itrEnemies)->getSelected())
                                    {

                                            if((*itrParty)->getSkillList()->getSkill((*itrParty)->getWeapon()->getType(),5)->getName() == Skill1->getText())
                                            {
                                                (*itrParty)->useAbility((*itrParty)->getSkillList()->getSkill((*itrParty)->getWeapon()->getType(),5),(*itrEnemies));
                                                (*itrEnemies)->setSelected(false);
                                                (*itrParty)->setCanAttack(false);
                                                Skill1->setPressed(false);
                                                Ability->setPressed(false);
                                            }


                                    }

                                }else if(Skill1->getPressed() == true && (*itrParty)->getAbilityPower() <(*itrParty)->getSkillList()->getSkill((*itrParty)->getWeapon()->getType(),5)->getCost()
                                         && (*itrParty)->getAbilityPower() - (*itrParty)->getSkillList()->getSkill((*itrParty)->getWeapon()->getType(),5)->getCost() <0)
                                {
                                    battleInfo->setText("Ability Power too low");
                                    battleInfo->Display(game->getSetup());
                                }
                                if(Skill2->getPressed()== true && (*itrParty)->getAbilityPower() >=(*itrParty)->getSkillList()->getSkill((*itrParty)->getWeapon()->getType(),10)->getCost()
                                        && (*itrParty)->getAbilityPower() - (*itrParty)->getSkillList()->getSkill((*itrParty)->getWeapon()->getType(),5)->getCost() >=0)
                                {
                                    if((*itrEnemies)->getCurrentHealth() > 0)
                                    {
                                    (*itrEnemies)->isSelected(game->getSetup(),(*itrEnemies)->getSprite());
                                        if(!(*itrEnemies)->getMouseOver())
                                        {


                                        }
                                        else if((*itrEnemies)->getMouseOver())
                                        {
                                            battleInfo->setText("Use " +Skill2->getText()+ " on " + (*itrEnemies)->getName());
                                            battleInfo->Display(game->getSetup());
                                            selected->setPosition((*itrEnemies)->getSprite()->getPositionRect().x-(*itrEnemies)->getSprite()->getPositionRect().w/6
                                                                    ,(*itrEnemies)->getSprite()->getPositionRect().y + (*itrEnemies)->getSprite()->getRect().h/2);
                                            selected->accept(visitor);
                                        }
                                    }

                                    if(Skill2->getPressed() &&(*itrEnemies)->getSelected())
                                    {
                                        if((*itrParty)->getSkillList()->getSkill((*itrParty)->getWeapon()->getType(),10)->getName() == Skill2->getText())
                                        {
                                            (*itrParty)->useAbility((*itrParty)->getSkillList()->getSkill((*itrParty)->getWeapon()->getType(),10),(*itrEnemies));
                                            (*itrEnemies)->setSelected(false);
                                            (*itrParty)->setCanAttack(false);
                                            Skill2->setPressed(false);
                                            Ability->setPressed(false);
                                        }

                                    }

                                }else if(Skill2->getPressed() == true && (*itrParty)->getAbilityPower() <(*itrParty)->getSkillList()->getSkill((*itrParty)->getWeapon()->getType(),10)->getCost()
                                         && (*itrParty)->getAbilityPower() - (*itrParty)->getSkillList()->getSkill((*itrParty)->getWeapon()->getType(),10)->getCost() <0)
                                {
                                    battleInfo->setText("Ability Power too low");
                                    battleInfo->Display(game->getSetup());
                                }
                                if(Skill3->getPressed() == true&& (*itrParty)->getAbilityPower() >=(*itrParty)->getSkillList()->getSkill((*itrParty)->getWeapon()->getType(),20)->getCost()
                                        && (*itrParty)->getAbilityPower() - (*itrParty)->getSkillList()->getSkill((*itrParty)->getWeapon()->getType(),20)->getCost() >=0)
                                {
                                    if((*itrEnemies)->getCurrentHealth() > 0)
                                    {
                                    (*itrEnemies)->isSelected(game->getSetup(),(*itrEnemies)->getSprite());
                                        if(!(*itrEnemies)->getMouseOver())
                                        {


                                        }
                                        else if((*itrEnemies)->getMouseOver())
                                        {
                                            battleInfo->setText("Use " +Skill3->getText()+ " on " + (*itrEnemies)->getName());
                                            battleInfo->Display(game->getSetup());
                                            selected->setPosition((*itrEnemies)->getSprite()->getPositionRect().x-(*itrEnemies)->getSprite()->getPositionRect().w/6
                                                                    ,(*itrEnemies)->getSprite()->getPositionRect().y + (*itrEnemies)->getSprite()->getRect().h/2);
                                            selected->accept(visitor);
                                        }
                                    }
                                    if(Skill3->getPressed() &&(*itrEnemies)->getSelected())
                                    {
                                        if((*itrParty)->getSkillList()->getSkill((*itrParty)->getWeapon()->getType(),20)->getName() == Skill3->getText())
                                        {
                                            (*itrParty)->useAbility((*itrParty)->getSkillList()->getSkill((*itrParty)->getWeapon()->getType(),20),(*itrEnemies));
                                            (*itrEnemies)->setSelected(false);
                                            (*itrParty)->setCanAttack(false);
                                            Skill3->setPressed(false);
                                            Ability->setPressed(false);
                                        }

                                    }
                                }else if(Skill3->getPressed() == true && (*itrParty)->getAbilityPower() <(*itrParty)->getSkillList()->getSkill((*itrParty)->getWeapon()->getType(),20)->getCost()
                                         && (*itrParty)->getAbilityPower() - (*itrParty)->getSkillList()->getSkill((*itrParty)->getWeapon()->getType(),20)->getCost() <0)
                                {
                                    battleInfo->setText("Ability Power too low");
                                    battleInfo->Display(game->getSetup());
                                }




//                        std::cout << "Enemy is selected is "<<std::boolalpha << (*itrEnemies)->getSelected();
//                        std::cout << (*itrParty)->getName() <<" has attacked "<<(*itrEnemies)->getName();




                            if(Items->getPressed() && !Potions->getPressed() && !Ethers->getPressed() &&!Revives->getPressed())
                            {
                                Skill1->setPosition(0,0);
                                Skill2->setPosition(0,0);
                                Skill3->setPosition(0,0);



                                Attack->setPressed(false);
                                Ability->setPressed(false);
                                Skill1->setPressed(false);
                                Skill2->setPressed(false);
                                Skill3->setPressed(false);


                                battleInfo->setText("Select item to use");
                                battleInfo->Display(game->getSetup());


                                battleMenu->setSize(game->getScreenWidth()/2- battleMenu->getRect().w/2 + battleMenu->getRect().w,game->getScreenHeight()-battleMenu->getRect().h, battleMenu->getRect().w, battleMenu->getRect().h);
                                battleMenu->accept(visitor);
                                drawItemsMenu(game);

                            }

                            if(Potions->getPressed())
                            {
                                for(std::vector<Entity*>::iterator iParty = game->getParty()->begin();iParty < game->getParty()->end();  iParty++)
                                {
                                  (*iParty)->isSelected(game->getSetup(),(*iParty)->getSprite());
                                    if(!(*iParty)->getMouseOver())
                                    {

                                    }
                                    else if((*iParty)->getMouseOver() && (*iParty)->getCurrentHealth() >0)
                                    {
                                        battleInfo->setText("Use Potion on " + (*iParty)->getName());
                                        battleInfo->Display(game->getSetup());
                                        selected->setPosition((*iParty)->getSprite()->getPositionRect().x-(*iParty)->getSprite()->getPositionRect().w
                                                                ,(*iParty)->getSprite()->getPositionRect().y + (*iParty)->getSprite()->getRect().h/2);
                                        selected->accept(visitor);
                                    } else if((*iParty)->getMouseOver() &&(*iParty)->getCurrentHealth() <=0)
                                    {
                                        battleInfo->setText( (*iParty)->getName() + " is KO'd");
                                        battleInfo->Display(game->getSetup());
                                        selected->setPosition((*iParty)->getSprite()->getPositionRect().x-(*iParty)->getSprite()->getPositionRect().w
                                                                ,(*iParty)->getSprite()->getPositionRect().y + (*iParty)->getSprite()->getRect().h/2);
                                        selected->accept(visitor);
                                    }
                                    if(Potions->getPressed() &&(*iParty)->getSelected() &&(*iParty)->getCurrentHealth() >0)
                                    {
                                        (*itrParty)->useItem((*iParty),"Potion");
                                        (*itrParty)->setCanAttack(false);
                                        (*iParty)->setSelected(false);
                                        Items->setPressed(false);
                                        Potions->setPressed(false);
                                        Ethers->setPressed(false);
                                        Revives->setPressed(false);

                                    }
                                }

                            }
                            if(Ethers->getPressed())
                            {
                                for(std::vector<Entity*>::iterator iParty = game->getParty()->begin();iParty < game->getParty()->end();  iParty++)
                                {
                                  (*iParty)->isSelected(game->getSetup(),(*iParty)->getSprite());
                                    if(!(*iParty)->getMouseOver())
                                    {

                                    }
                                    else if((*iParty)->getMouseOver() &&(*iParty)->getCurrentHealth() >0)
                                    {
                                        battleInfo->setText("Use Ether on " + (*iParty)->getName());
                                        battleInfo->Display(game->getSetup());
                                        selected->setPosition((*iParty)->getSprite()->getPositionRect().x-(*iParty)->getSprite()->getPositionRect().w
                                                                ,(*iParty)->getSprite()->getPositionRect().y + (*iParty)->getSprite()->getRect().h/2);
                                        selected->accept(visitor);
                                    }
                                    else if((*iParty)->getMouseOver() &&(*iParty)->getCurrentHealth() <=0)
                                    {
                                        battleInfo->setText( (*iParty)->getName() + " is KO'd");
                                        battleInfo->Display(game->getSetup());
                                        selected->setPosition((*iParty)->getSprite()->getPositionRect().x-(*iParty)->getSprite()->getPositionRect().w
                                                                ,(*iParty)->getSprite()->getPositionRect().y + (*iParty)->getSprite()->getRect().h/2);
                                        selected->accept(visitor);
                                    }
                                    if(Ethers->getPressed() &&(*iParty)->getSelected() &&(*iParty)->getCurrentHealth() >0)
                                    {
                                        (*itrParty)->useItem((*iParty),"Ether");
                                        (*itrParty)->setCanAttack(false);
                                        (*iParty)->setSelected(false);
                                        Ethers->setPressed(false);
                                        Items->setPressed(false);
                                        Potions->setPressed(false);
                                        Revives->setPressed(false);

                                    }
                                }

                            }if(Revives->getPressed())
                            {
                                for(std::vector<Entity*>::iterator iParty = game->getParty()->begin();iParty < game->getParty()->end();  iParty++)
                                {
                                  (*iParty)->isSelected(game->getSetup(),(*iParty)->getSprite());
                                    if(!(*iParty)->getMouseOver())
                                    {

                                    }
                                    else if((*iParty)->getMouseOver() &&(*iParty)->getCurrentHealth() <=0)
                                    {
                                        battleInfo->setText("Use Revive on " + (*iParty)->getName());
                                        battleInfo->Display(game->getSetup());
                                        selected->setPosition((*iParty)->getSprite()->getPositionRect().x-(*iParty)->getSprite()->getPositionRect().w
                                                                ,(*iParty)->getSprite()->getPositionRect().y + (*iParty)->getSprite()->getRect().h/2);
                                        selected->accept(visitor);
                                    }
                                    else if((*iParty)->getMouseOver() &&(*iParty)->getCurrentHealth() >0)
                                    {
                                        battleInfo->setText( (*iParty)->getName() + " is not KO'd");
                                        battleInfo->Display(game->getSetup());
                                        selected->setPosition((*iParty)->getSprite()->getPositionRect().x-(*iParty)->getSprite()->getPositionRect().w
                                                                ,(*iParty)->getSprite()->getPositionRect().y + (*iParty)->getSprite()->getRect().h/2);
                                        selected->accept(visitor);
                                    }
                                    if(Revives->getPressed() &&(*iParty)->getSelected() &&(*iParty)->getCurrentHealth() <=0)
                                    {
                                        (*itrParty)->useItem((*iParty),"Revive");
                                        (*itrParty)->setCanAttack(false);
                                        (*iParty)->setSelected(false);
                                        Ethers->setPressed(false);
                                        Items->setPressed(false);
                                        Potions->setPressed(false);
                                        Revives->setPressed(false);

                                    }
                                }

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
                    int  x = rand() % game->getParty()->size() ;


                    if(game->getParty()->at(x)->getCurrentHealth() > 0)
                    {


                        SDL_Delay(1000);
                        (*i)->attack(game->getParty()->at(x));
                        std::cout << (*i)->getName()<< " attacks " << game->getParty()->at(x)->getName() <<std::endl;



                       (*i)->setCanAttack(false);
                         break;
                    }



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
        Skill1->Draw(battleMenu->getPositionRect().x +20,battleMenu->getPositionRect().y + buttonOffset);
    }
    if( Skill2->getText() != "Skill 2")
    {
        Skill2->Draw(battleMenu->getPositionRect().x +20,battleMenu->getPositionRect().y + buttonOffset*2);
    }
    if(Skill3->getText() != "Skill 3")
    {
        Skill3->Draw(battleMenu->getPositionRect().x +20,battleMenu->getPositionRect().y + buttonOffset*3);
    }
}

void BattleState::drawItemsMenu(GameEngine * game)
{
    bool havePotion = false;
    bool haveEther = false;
    bool haveRevive = false;
    for(std::list<Item*>::iterator i = game->getParty()->front()->getInventory()->getInventory()->begin();i!=game->getParty()->front()->getInventory()->getInventory()->end();)
    {
        std::cout << "here in the draw items menu i have a " << (*i)->getName() <<std::endl;
         if((*i)->getName() == "Potion" && (*i)->getQuantity() > 0)
         {
             havePotion = true;
             Potions->setText("Potion");
         }
         if((*i)->getName() == "Ether" && (*i)->getQuantity() > 0)
         {
             haveEther = true;
             Ethers->setText("Ether");
         }
         if((*i)->getName() == "Revive" && (*i)->getQuantity() > 0)
         {
             haveRevive = true;
             Revives->setText("Revive");
         }

        i++;
        if(!havePotion)
        {
            Potions->setText("Item 1");
        }
        if(!haveEther)
        {
            Ethers->setText("Item 2");
        }
        if(!haveRevive)
        {
            Revives->setText("Item 3");
        }


    }
    if(Potions->getText() != "Item 1")
    {
        Potions->Draw(battleMenu->getPositionRect().x +20,battleMenu->getPositionRect().y + buttonOffset);
    }
    if(Ethers->getText() != "Item 2")
    {
        Ethers->Draw(battleMenu->getPositionRect().x +20,battleMenu->getPositionRect().y + buttonOffset*2);
    }
    if(Revives->getText() != "Item 3")
    {
        Revives->Draw(battleMenu->getPositionRect().x +20,battleMenu->getPositionRect().y + buttonOffset*3);
    }


}
void BattleState::checkSkills(GameEngine * game,Entity * player)
{


         std::cout << "checking skills for "<< player->getName()<< std::endl;
         std::cout <<  player->getName()<< " has "<<player->getWeapon()->getName() <<"equipped"<< std::endl;

        if(player->getWeapon()->getType() == Item::AXE)
        {
             std::cout <<  player->getName()<< " has axe equipped"<< std::endl;


                if(player->getSkillMap()->at("Axe Skill") >= 5)
                {

                    Skill1->setText(player->getSkillList()->getSkill(Item::AXE,5)->getName());
                }else if(player->getSkillMap()->at("Axe Skill") < 5)
                {
                    Skill1->setText("Skill 1");
                }
                if(player->getSkillMap()->at("Axe Skill") >= 10)
                {

                    Skill2->setText(player->getSkillList()->getSkill(Item::AXE,10)->getName());
                }else if(player->getSkillMap()->at("Axe Skill") < 10)
                {
                    Skill2->setText("Skill 2");
                }
                if(player->getSkillMap()->at("Axe Skill") >= 20)
                {

                    Skill3->setText(player->getSkillList()->getSkill(Item::AXE,20)->getName());
                }else if(player->getSkillMap()->at("Axe Skill") < 20)
                {
                    Skill3->setText("Skill 3");
                }



        }
        if(player->getWeapon()->getType() == Item::MACE)
        {
            std::cout <<  player->getName()<< " has mace equipped"<< std::endl;

                if(player->getSkillMap()->at("Mace Skill") >= 5)
                {

                    Skill1->setText(player->getSkillList()->getSkill(Item::MACE,5)->getName());
                }else if(player->getSkillMap()->at("Mace Skill") < 5)
                {
                    Skill1->setText("Skill 1");
                }
                if(player->getSkillMap()->at("Mace Skill") >= 10)
                {

                    Skill2->setText(player->getSkillList()->getSkill(Item::MACE,10)->getName());
                }else if(player->getSkillMap()->at("Mace Skill") < 10)
                {
                    Skill2->setText("Skill 2");
                }
                if(player->getSkillMap()->at("Mace Skill") >= 20)
                {

                    Skill3->setText(player->getSkillList()->getSkill(Item::MACE,20)->getName());
                }else if(player->getSkillMap()->at("Mace Skill") < 20)
                {
                    Skill3->setText("Skill 3");
                }



        }
        if(player->getWeapon()->getType() == Item::SWORD)
        {
            std::cout <<  player->getName()<< " has sword equipped"<< std::endl;

                if(player->getSkillMap()->at("Sword Skill") >= 5)
                {

                    Skill1->setText(player->getSkillList()->getSkill(Item::SWORD,5)->getName());
                }else if(player->getSkillMap()->at("Sword Skill") < 5)
                {
                    Skill1->setText("Skill 1");
                }
                if(player->getSkillMap()->at("Sword Skill") >= 10)
                {

                    Skill2->setText(player->getSkillList()->getSkill(Item::SWORD,10)->getName());
                }else if(player->getSkillMap()->at("Sword Skill") < 10)
                {
                    Skill2->setText("Skill 2");
                }
                if(player->getSkillMap()->at("Sword Skill") >= 20)
                {

                    Skill3->setText(player->getSkillList()->getSkill(Item::SWORD,20)->getName());
                }else if(player->getSkillMap()->at("Sword Skill") < 20)
                {
                    Skill3->setText("Skill 3");
                }



        }
        if(player->getWeapon()->getType() == Item::SPEAR)
        {
            std::cout <<  player->getName()<< " has spear equipped"<< std::endl;

                if(player->getSkillMap()->at("Spear Skill") >= 5)
                {

                    Skill1->setText(player->getSkillList()->getSkill(Item::SPEAR,5)->getName());
                }else if(player->getSkillMap()->at("Spear Skill") < 5)
                {
                    Skill1->setText("Skill 1");
                }
                if(player->getSkillMap()->at("Spear Skill") >= 10)
                {

                    Skill2->setText(player->getSkillList()->getSkill(Item::SPEAR,10)->getName());
                }else if(player->getSkillMap()->at("Spear Skill") < 10)
                {
                    Skill2->setText("Skill 2");
                }
                if(player->getSkillMap()->at("Spear Skill") >= 20)
                {

                    Skill3->setText(player->getSkillList()->getSkill(Item::SPEAR,20)->getName());
                }else if(player->getSkillMap()->at("Spear Skill") < 20)
                {
                    Skill3->setText("Skill 3");
                }



        }


}

void BattleState::setEnemies(GameEngine * game)
{
    EnemyList list;

    int amount = rand()% 4 +1;

    while(amount > 0)
    {
        int x = rand() % 11 ;
         std::cout << "enemy in list is" << list.getEnemies().at(x)<<std::endl;
         Enemy * enemy1 = new Enemy(game->getSetup(),list.getEnemies().at(x),"resources/Battle/Enemies/"+ list.getEnemies().at(x)+".png");
         enemy1->setLevel(game->getParty()->front()->getEntityLevel()->getCurrentLevel());
         enemies.push_back(enemy1);
         amount--;
    }

    int spot = 0;
    for(std::vector<Entity*>::iterator i = enemies.begin();i!=enemies.end();)
    {




      (*i)->setOrigin(positions.at(spot).x,positions.at(spot).y);
        rewardXP += (*i)->getExperience();
        std::cout << "reward xp is " << rewardXP << std::endl;
         spot++;
        i++;



    }


}
