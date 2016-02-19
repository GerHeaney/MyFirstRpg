#include "battlestate.h"
#include "State/fieldstate.h"


BattleState BattleState::battle;

void BattleState::Init(GameEngine *game)
{
    battleSystem = new BattleSystem();



    menu = new MenuSprite(game->getRenderer(),"resources/Battle/menu.png");
    background = new BackgroundSprite(game->getRenderer(),"resources/Battle/battle.png");

    enemy = new Enemy(game->getSetup(),"Old Hermit","resources/Battle/Hermit2.png");
    enemies.push_back(enemy);
            //new Entity(game->getSetup(),game->getScreenWidth()/4,game->getScreenHeight()-menu->getHeight()*1.5,"Hermit","resources/Battle/Hermit2.png");
   // player = game->getParty().front();


    game->getParty().front()->getSprite()->setPositionRect(game->getScreenWidth() - game->getScreenWidth()/4,game->getScreenHeight()-game->getScreenHeight()/3);

    enemies.front()->setOrigin(game->getScreenWidth()/4,game->getScreenHeight() - game->getScreenHeight()*0.4);
    game->getParty().front()->getSprite()->setInitFrame(0,1);
    background->setSize(game->getScreenWidth(),game->getScreenHeight());

    menu->setSize(0,game->getScreenHeight()-menu->getRect().h ,game->getScreenWidth(),menu->getRect().h);
    Attack = new FontButton(game->getSetup(),"resources/MainMenu/new.png","Attack");
    Ability = new FontButton(game->getSetup(),"resources/MainMenu/new.png","Ability");
    Item = new FontButton(game->getSetup(),"resources/MainMenu/new.png","Item");
    playerField.Init();
    enemyField.Init();
    playerField.setPosition(game->getScreenWidth()/2 + 20,game->getScreenHeight()-menu->getRect().h+ 100);
    enemyField.setPosition(game->getScreenWidth()/8 + 20,game->getScreenHeight()-menu->getRect().h+ 100);
    playerField.setText(game->getParty().front()->getBattleStats());
    enemyField.setText(enemy->getBattleStats());






}
void BattleState::Draw(GameEngine *game)
{
    DrawVisitor visitor;
    background->accept(&visitor);
    enemies.front()->getSprite()->accept(&visitor);
    game->getParty().front()->getSprite()->accept(&visitor);
    menu->accept(&visitor);

    Attack->Draw(20,game->getScreenHeight()-160);
    Ability->Draw(20,game->getScreenHeight()-120);
    Item->Draw(20,game->getScreenHeight()-80);
    playerField.Display(game->getSetup());
    enemyField.Display(game->getSetup());

}
void BattleState::Update(GameEngine *game)
{


    playerField.setText(game->getParty().front()->getBattleStats());
    enemyField.setText(enemies.front()->getBattleStats());
    Attack->setPressed(false);
    battleSystem->updateBattle(enemies,game->getParty());
    if(battleSystem->getWinBattle() == true)
    {
        std::cout <<" You won the battle";
        game->PopState();
    }






}
void BattleState::HandleEvents(GameEngine *game)
{

    Attack->handleEvent();
    Ability->handleEvent();
    Item->handleEvent();
    if(Attack->getPressed() == true)
    {
       game->getParty().front()->attack(enemies.front());

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
//    delete menu;
//    delete enemy;
//    delete Attack;
//    delete Ability;
//    delete Item;


}



