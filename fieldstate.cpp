#include "fieldstate.h"


FieldState FieldState::field;

void FieldState::Init(MainClass *game)
{
    stage1 = new Environment(game->getSetup(),game->getScreenWidth(),game->getScreenHeight());
     //grass = new CSprite(setup->getRenderer(),"resources/map.png",0,0,screenWidth,screenHeight,&cameraX,&cameraY);

    player = new MainCharacter(game->getSetup(),game->getScreenWidth(),game->getScreenHeight(),stage1->getLevelWidth(),stage1->getLevelHeight());
   // camera = player->getCamera();
    srand(time(NULL));
    x = 10;
    std::cout << x;


}
void FieldState::Draw(MainClass *game)
{
    camera = player->getCamera();
    stage1->DrawBack(&camera);
    player->Draw();





}
void FieldState::Update(MainClass *game)
{
    player->setCamera();


    if(x ==10)
    {
        game->ChangeState(BattleState::Instance());
    }



}
void FieldState::HandleEvents(MainClass *game)
{


    if(player->GetMoving() == true)
    {
         std::cout << x << std::endl;
         x = rand() % 1000 + 1;

    }
    player->Move();

}
void FieldState::Pause()
{

}
void FieldState::Resume()
{

}
void FieldState::Cleanup()
{
    player = NULL;


}

