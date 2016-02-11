#include "battlestate.h"


BattleState BattleState::battle;

void BattleState::Init(GameEngine *game)
{
    menu = new CSprite(game->getRenderer(),"resources/Battle/menu.png",0,game->getScreenHeight()-241);
    background = new CSprite(game->getRenderer(),"resources/Battle/battle.png",0,0);
    enemy = new Entity(game->getSetup(),game->getScreenWidth()/4,game->getScreenHeight()-menu->getHeight()*1.5,"Hermit","resources/Battle/Hermit2.png");
    player = game->getPlayer();
    player->getPlayer()->setCameraX(0);
    player->getPlayer()->setCameraY(0);
    camera = player->getCamera();
    menuRect = {0,game->getScreenHeight()-241,menu->getWidth(),menu->getHeight()};

    player->setOrigin(game->getScreenWidth() - game->getScreenWidth()/4,game->getScreenHeight()-menu->getHeight()*1.25);
    enemy->setOrigin(game->getScreenWidth()/4,game->getScreenHeight()-menu->getHeight()*1.25);
    player->setInitFrame(0,1);
    Attack = new FontButton(game->getSetup(),"resources/MainMenu/new.png","Attack");
    Ability = new FontButton(game->getSetup(),"resources/MainMenu/new.png","Ability");
    Item = new FontButton(game->getSetup(),"resources/MainMenu/new.png","Item");
    enemy->getPlayer()->setSpriteSize(100,100);




}
void BattleState::Draw(GameEngine *game)
{
    background->DrawBackground(&camera);
    enemy->DrawBackground(&camera);
    player->Draw();
    menu->DrawBackground(&menuRect);
    Attack->Draw(20,game->getScreenHeight()-220);
    Ability->Draw(20,game->getScreenHeight()-180);
    Item->Draw(20,game->getScreenHeight()-120);

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



