#include "battlestate.h"


BattleState BattleState::battle;

void BattleState::Init(GameEngine *game)
{

    camera = game->getGameCamera()->getCamera();
    //menu = new CSprite(game->getRenderer(),"resources/Battle/menu.png",0,game->getScreenHeight()-241);
    background = new BackgroundSprite(game->getRenderer(),"resources/Battle/battle.png");
     game->getGameCamera()->setCamera(0,0,background);
    background->setRect(camera);
    enemy = new Entity(game->getSetup(),game->getScreenWidth()/4,game->getScreenHeight()-menu->getHeight()*1.5,"Hermit","resources/Battle/Hermit2.png");
//    player = game->getPlayer();
//    player->getSprite()->setCameraX(0);
//    player->getSprite()->setCameraY(0);
//    camera = player->getCamera();
//    menuRect = {0,game->getScreenHeight()-241,menu->getWidth(),menu->getHeight()};

//    player->setOrigin(game->getScreenWidth() - game->getScreenWidth()/4,game->getScreenHeight()-menu->getHeight()*1.25);
//    enemy->setOrigin(game->getScreenWidth()/4,game->getScreenHeight()-menu->getHeight()*1.25);
//    player->setInitFrame(0,1);
//    Attack = new FontButton(game->getSetup(),"resources/MainMenu/new.png","Attack");
//    Ability = new FontButton(game->getSetup(),"resources/MainMenu/new.png","Ability");
//    Item = new FontButton(game->getSetup(),"resources/MainMenu/new.png","Item");
//    enemy->getSprite()->setSpriteSize(100,100);





}
void BattleState::Draw(GameEngine *game)
{
    DrawVisitor visitor;
    background->accept(&visitor);
//    enemy->DrawBackground(&camera);
//    player->Draw();
//    menu->DrawBackground(&menuRect);
//    Attack->Draw(20,game->getScreenHeight()-220);
//    Ability->Draw(20,game->getScreenHeight()-180);
//    Item->Draw(20,game->getScreenHeight()-120);

}
void BattleState::Update(GameEngine *game)
{



}
void BattleState::HandleEvents(GameEngine *game)
{
//    Attack->handleEvent();
//    Ability->handleEvent();
//    Item->handleEvent();
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



