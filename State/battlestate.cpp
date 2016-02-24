#include "battlestate.h"
#include "State/fieldstate.h"


BattleState BattleState::battle;

void BattleState::Init(GameEngine *game)
{
    attackanim = new MovingSprite(game->getRenderer(),"resources/Battle/Attack.png");


    menu = new MenuSprite(game->getRenderer(),"resources/Battle/menu.png");
    background = new BackgroundSprite(game->getRenderer(),"resources/Battle/battle.png");
    selected = new MenuSprite(game->getRenderer(),"resources/Battle/select.png");
    enemy = new Enemy(game->getSetup(),"Old Hermit","resources/Battle/Hermit2.png");
    playerField = new DisplayField();
    enemyField = new DisplayField();
    Attack = new FontButton(game->getSetup(),"resources/MainMenu/new.png","Attack");
    Ability = new FontButton(game->getSetup(),"resources/MainMenu/new.png","Ability");
    Item = new FontButton(game->getSetup(),"resources/MainMenu/new.png","Item");
    battleMenu = new MenuSprite(game->getRenderer(),"resources/Battle/battleoptions.png");
    enemies.push_back(enemy);
            //new Entity(game->getSetup(),game->getScreenWidth()/4,game->getScreenHeight()-menu->getHeight()*1.5,"Hermit","resources/Battle/Hermit2.png");
   // player = game->getParty().front();

    visitor = new DrawVisitor();

    game->getParty()->back()->getSprite()->setPositionRect(game->getScreenWidth() - game->getScreenWidth()/4,game->getScreenHeight()-game->getScreenHeight()/3);

    enemies.front()->setOrigin(game->getScreenWidth()/4,game->getScreenHeight() - game->getScreenHeight()*0.4);
    game->getParty()->front()->getSprite()->setInitFrame(0,1);
    background->setSize(game->getScreenWidth(),game->getScreenHeight());

    menu->setSize(0,game->getScreenHeight()-menu->getRect().h ,game->getScreenWidth(),menu->getRect().h);

    playerField->setPosition(game->getScreenWidth() - game->getScreenWidth()/3 ,game->getScreenHeight()-menu->getRect().h+ 100);
    enemyField->setPosition( 20,game->getScreenHeight()-menu->getRect().h+ 100);
    playerField->setText(game->getParty()->front()->getBattleStats());
    enemyField->setText(enemy->getBattleStats());
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


        if(Attack->getPressed())
        {
            if(battleSystem->getPlayerTurn())
            {
            chooseEnemy(game);
            }




        }


//       game->getParty().front()->attack(enemies.front());
//      battleSystem->executeAttacks();




}
void BattleState::Update(GameEngine *game)
{


    playerField->setText(game->getParty()->front()->getBattleStats());
    enemyField->setText(enemies.front()->getBattleStats());
    Attack->setPressed(false);
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
    enemies.front()->getSprite()->accept(visitor);
    game->getParty()->front()->getSprite()->accept(visitor);
    menu->accept(visitor);



   playerField->Display(game->getSetup());
    enemyField->Display(game->getSetup());

        attackanim->accept(visitor);
        if(battleSystem->getPlayerTurn() == true)
        {
            battleMenu->accept(visitor);
            Attack->Draw(battleMenu->getPosRect().x +20,battleMenu->getPosRect().y + 20);
            Ability->Draw(battleMenu->getPosRect().x +20,battleMenu->getPosRect().y + 50);
            Item->Draw(battleMenu->getPosRect().x +20,battleMenu->getPosRect().y + 80);

        }







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

void BattleState::chooseEnemy(GameEngine * game)
{
    battleSystem->executeAttacks();


    std::cout << game->getParty()<<std::endl;



    std::vector<MainCharacter*>::iterator i =game->getParty()->begin();
   while(i <game->getParty()->end())
    {
       std::cout <<game->getParty()->size()<<std::endl;
        std::cout << "i name is " <<(*i)->getName() << std::endl;
         std::cout << "in the choose enemy loop before the if statement" << std::endl;
         std::cout <<std::boolalpha <<  (*i)->getCanAttack()<< std::endl;


         if((*i)->getCanAttack() == true)
        {
            std::cout << "in the choose if statement" << std::endl;
            std::cout << "i name is " <<(*i)->getName() << std::endl;
            (*i)->attack(enemy);
            (*i)->setCanAttack(false);


        }else{std::cout << "can't attack" << std::endl;}

        i++;

    }
//    selected->setPosition(enemies.back()->getSprite()->getPosRect().x - enemies.back()->getSprite()->getPosRect().w/2,enemies.back()->getSprite()->getPosRect().y + enemies.back()->getSprite()->getPosRect().h/2);
//    selected->accept(visitor);


}



