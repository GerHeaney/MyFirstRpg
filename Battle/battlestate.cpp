#include "battlestate.h"
#include "State/fieldstate.h"


BattleState BattleState::battle;

void BattleState::Init(GameEngine *game)
{
    attackanim = new MovingSprite(game->getRenderer(),"resources/Battle/Attack.png");


    menu = new MenuSprite(game->getRenderer(),"resources/Battle/menu.png");
    background = new BackgroundSprite(game->getRenderer(),"resources/Battle/battle.png");
    selected = new MenuSprite(game->getRenderer(),"resources/Battle/select.png");
    infoBox = new MenuSprite(game->getRenderer(),"resources/Battle/infobox.png");
    enemy = new Enemy(game->getSetup(),"Old Hermit","resources/Battle/Hermit2.png");
    enemy2 = new Enemy(game->getSetup(),"Old Hermit 2","resources/Battle/Hermit4.png");
    playerField = new DisplayField();
    enemyField = new DisplayField();
    battleInfo = new DisplayField();
    Attack = new FontButton(game->getSetup(),"resources/MainMenu/new.png","Attack");
    Ability = new FontButton(game->getSetup(),"resources/MainMenu/new.png","Ability");
    Item = new FontButton(game->getSetup(),"resources/MainMenu/new.png","Item");
    battleMenu = new MenuSprite(game->getRenderer(),"resources/Battle/battleoptions.png");
    enemies.push_back(enemy);
    enemies.push_back(enemy2);
            //new Entity(game->getSetup(),game->getScreenWidth()/4,game->getScreenHeight()-menu->getHeight()*1.5,"Hermit","resources/Battle/Hermit2.png");
   // player = game->getParty().front();

    visitor = new DrawVisitor();

    game->getParty()->back()->getSprite()->setPositionRect(game->getScreenWidth() - game->getScreenWidth()/4,game->getScreenHeight()-game->getScreenHeight()/3);

    int spot = 0;
    for(std::vector<Enemy*>::iterator i = enemies.begin();i!=enemies.end();)
    {

      (*i)->setOrigin(game->getScreenWidth()/4 + spot,game->getScreenHeight() - game->getScreenHeight()*0.4 - spot);
        i++;
        spot+=50;

    }
   // enemies.front()->setOrigin(game->getScreenWidth()/4,game->getScreenHeight() - game->getScreenHeight()*0.4);
    game->getParty()->front()->getSprite()->setInitFrame(0,1);
    background->setSize(game->getScreenWidth(),game->getScreenHeight());

    menu->setSize(0,game->getScreenHeight()-menu->getRect().h ,game->getScreenWidth(),menu->getRect().h);
    infoBox->setSize(game->getScreenWidth()/3,game->getScreenHeight()-game->getScreenHeight()*0.9,game->getScreenWidth()/3,infoBox->getRect().h*0.8);

    playerField->setPosition(game->getScreenWidth() - game->getScreenWidth()/3 ,game->getScreenHeight()-menu->getRect().h+ 100);
    enemyField->setPosition( 20,game->getScreenHeight()-menu->getRect().h+ 100);
    playerField->setText(game->getParty()->front()->getBattleStats());
    enemyField->setText(enemy->getBattleStats());
    battleInfo->setPosition(infoBox->getPosRect().x + infoBox->getRect().w/10,infoBox->getPosRect().y);
    battleMenu->setSize(game->getScreenWidth()/2- battleMenu->getRect().w/2,game->getScreenHeight()-battleMenu->getRect().h, battleMenu->getRect().w, battleMenu->getRect().h);
    attackanim->setPositionRect(500,500);
    attackanim->setupAnimation(7,1);
    attackanim->setInitFrame(0,0);
    battleSystem = new BattleSystem();
    battleSystem->setAttacks(enemies,*game->getParty());






}


void BattleState::HandleEvents(GameEngine *game)
{



    Attack->handleEvent();
    Ability->handleEvent();
    Item->handleEvent();
    PlayerTurn(game);
    EnemyTurn(game);




    std::cout <<std::boolalpha <<  Attack->getPressed();




//       game->getParty().front()->attack(enemies.front());
//      battleSystem->executeAttacks();




}
void BattleState::Update(GameEngine *game)
{

    int spot = 0;

    playerField->setText(game->getParty()->front()->getBattleStats());
    for(std::vector<Enemy*>::iterator i = enemies.begin();i!=enemies.end();)
    {

        enemyField->setPosition( 20,game->getScreenHeight()-menu->getRect().h*0.9 + spot);
        enemyField->setText((*i)->getBattleStats());
           enemyField->Display(game->getSetup());
           spot +=30;

        i++;


    }


    battleSystem->updateBattle(enemies,*game->getParty());
    if(battleSystem->getWinBattle())
    {
        std::cout <<" You won the battle";
        game->PopState();
    }






}
void BattleState::Draw(GameEngine *game)
{


    background->accept(visitor);
    infoBox->accept(visitor);
    for(std::vector<Enemy*>::iterator i = enemies.begin();i!=enemies.end();)
    {

      (*i)->getSprite()->accept(visitor);
        i++;


    }

    game->getParty()->front()->getSprite()->accept(visitor);
    menu->accept(visitor);



   playerField->Display(game->getSetup());


        attackanim->accept(visitor);







}
void BattleState::Pause()
{

}
void BattleState::Resume()
{

}
void BattleState::Cleanup()
{
    delete menu;
    delete enemy;
    delete Attack;
    delete Ability;
    delete Item;
    delete battleSystem;
    delete background;
    delete playerField;
    delete enemyField;
    delete battleMenu;
    enemies.clear();

}

void BattleState::chooseEnemy(GameEngine * game, Enemy * enemy)
{



    std::cout << game->getParty()<<std::endl;



    std::vector<MainCharacter*>::iterator i =game->getParty()->begin();
   while(i <game->getParty()->end())
    {

       std::cout <<game->getParty()->size()<<std::endl;
        std::cout << "i name is " <<(*i)->getName() << std::endl;
         std::cout << "in the choose enemy loop before the if statement" << std::endl;
         std::cout <<std::boolalpha <<  (*i)->getCanAttack()<< std::endl;


         if((*i)->getCanAttack() == true && Attack->getPressed())
        {


             SDL_Delay(1000);
             (*i)->attack(enemy);



            (*i)->setCanAttack(false);

             }else{std::cout << "can't attack" << std::endl;}

        i++;

    }
//    selected->setPosition(enemies.back()->getSprite()->getPosRect().x - enemies.back()->getSprite()->getPosRect().w/2,enemies.back()->getSprite()->getPosRect().y + enemies.back()->getSprite()->getPosRect().h/2);
//    selected->accept(visitor);


}

void BattleState::drawBattleMenu()
{
    battleMenu->accept(visitor);
    Attack->Draw(battleMenu->getPosRect().x +20,battleMenu->getPosRect().y + 20);
    Ability->Draw(battleMenu->getPosRect().x +20,battleMenu->getPosRect().y + 50);
    Item->Draw(battleMenu->getPosRect().x +20,battleMenu->getPosRect().y + 80);
}

void BattleState::PlayerTurn(GameEngine * game)
{
    if(battleSystem->getPlayerTurn(*game->getParty()))
    {
        if(Attack->getPressed())
        {
            battleInfo->setText("");
            battleInfo->setText("Select enemy to attack");
            battleInfo->Display(game->getSetup());

            for(std::vector<Enemy*>::iterator i = enemies.begin();i!=enemies.end();)
            {

              (*i)->isSelected();


                if((*i)->getSelected())
                {

                    chooseEnemy(game,(*i));


                }
                  i++;
            }


        }

        if(!Attack->getPressed())
        {
        battleInfo->setText("player turn select action");
        battleInfo->Display(game->getSetup());
        }

        std::cout<< "player turn is " <<std::boolalpha <<  battleSystem->getPlayerTurn(*game->getParty())<< std::endl;

        drawBattleMenu();

    }


}

void BattleState::EnemyTurn(GameEngine *game)
{
    if(battleSystem->getEnemyTurn(enemies))
    {

            battleInfo->setText("Enemy Turn");
            battleInfo->Display(game->getSetup());
            SDL_Delay(1000);

            for(std::vector<Enemy*>::iterator i = enemies.begin();i!=enemies.end();)
            {

                if((*i)->getCanAttack() == true)
               {


                    SDL_Delay(1000);
                    (*i)->attack(game->getParty()->front());



                   (*i)->setCanAttack(false);

                    }else{std::cout << "can't attack" << std::endl;}

               i++;


            }



    }


}
