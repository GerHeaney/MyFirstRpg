#include "battlestate.h"


BattleState BattleState::battle;

void BattleState::Init(GameEngine *game)
{


    menu = new MenuSprite(game->getRenderer(),"resources/Battle/menu.png");
    background = new BackgroundSprite(game->getRenderer(),"resources/Battle/battle.png");

    enemy = new Enemy(game->getSetup(),"Old Hermit","resources/Battle/Hermit2.png");
            //new Entity(game->getSetup(),game->getScreenWidth()/4,game->getScreenHeight()-menu->getHeight()*1.5,"Hermit","resources/Battle/Hermit2.png");
    player = game->getPlayer();


    player->getSprite()->setPositionRect(game->getScreenWidth() - game->getScreenWidth()/4,game->getScreenHeight()-300);

    enemy->setOrigin(game->getScreenWidth()/4,game->getScreenHeight()-menu->getRect().h- 100);
    player->getSprite()->setInitFrame(0,1);
    background->setSize(game->getScreenWidth(),game->getScreenHeight());

    menu->setSize(0,game->getScreenHeight()-menu->getRect().h + 50,game->getScreenWidth(),menu->getRect().h - 50);
    Attack = new FontButton(game->getSetup(),"resources/MainMenu/new.png","Attack");
    Ability = new FontButton(game->getSetup(),"resources/MainMenu/new.png","Ability");
    Item = new FontButton(game->getSetup(),"resources/MainMenu/new.png","Item");






}
void BattleState::Draw(GameEngine *game)
{
    DrawVisitor visitor;
    background->accept(&visitor);
    enemy->getSprite()->accept(&visitor);
    player->getSprite()->accept(&visitor);
    menu->accept(&visitor);

    Attack->Draw(20,game->getScreenHeight()-160);
    Ability->Draw(20,game->getScreenHeight()-120);
    Item->Draw(20,game->getScreenHeight()-80);

}
void BattleState::Update(GameEngine *game)
{



}
void BattleState::HandleEvents(GameEngine *game)
{
    Attack->handleEvent();
    Ability->handleEvent();
    Item->handleEvent();
}
void BattleState::Pause()
{

}
void BattleState::Resume()
{

}
void BattleState::Cleanup()
{


}



