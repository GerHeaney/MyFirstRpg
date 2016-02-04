#include "battlestate.h"


BattleState BattleState::battle;

void BattleState::Init(MainClass *game)
{
     menu = new CSprite(game->getRenderer(),"resources/Battle/menu.png",0,game->getScreenHeight()-241,game->getScreenWidth(),241);
    background = new CSprite(game->getRenderer(),"resources/Battle/battle.png",0,0,game->getScreenWidth(),game->getScreenHeight()-menu->getHeight());
    enemy = new CSprite(game->getRenderer(),"resources/Battle/Hermit2.png",game->getScreenWidth()/4,game->getScreenHeight()-menu->getHeight()*1.5f,102,118);

    player = game->getPlayer();
    camera = player->getCamera();
    menuRect = {0,game->getScreenHeight()-241,menu->getWidth(),menu->getHeight()};

    player->setOrigin(game->getScreenWidth() - game->getScreenWidth()/4,game->getScreenHeight()-menu->getHeight()*1.25);
    player->setInitFrame(0,1);



}
void BattleState::Draw(MainClass *game)
{
    background->DrawBackground(&camera);
    enemy->DrawBackground(&camera);
    player->Draw();
    menu->DrawBackground(&camera);

}
void BattleState::Update(MainClass *game)
{



}
void BattleState::HandleEvents(MainClass *game)
{


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



