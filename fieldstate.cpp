#include "fieldstate.h"


FieldState FieldState::field;

void FieldState::Init(MainClass *game)
{
    stage1 = new Environment(game->getSetup(),game->getScreenWidth(),game->getScreenHeight());


    player = game->getPlayer();

    srand(time(NULL));
    x =1;
    std::cout << x;
    move = new KeyboardMovement(game->getSetup(),player,stage1->getLevelWidth(),stage1->getLevelHeight());
    player->getPlayer()->setWidth(stage1->getLevelWidth());
    player->getPlayer()->setHeight(stage1->getLevelHeight());



}
void FieldState::Draw(MainClass *game)
{
    player->setCamera();
    camera = player->getCamera();
    stage1->DrawBack(&camera);
    player->Draw();
}
void FieldState::Update(MainClass *game)
{
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
        x = rand() % 500 + 1;

    }
    move->Move();
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

