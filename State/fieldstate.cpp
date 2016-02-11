#include "fieldstate.h"


FieldState FieldState::field;

void FieldState::Init(GameEngine *game)
{
    stage1 = new BackgroundSprite(game->getSetup()->getRenderer(),"resources/map.png");
            //new Environment(game->getSetup(),game->getScreenWidth(),game->getScreenHeight());
    player = game->getPlayer();
    player->setOrigin(0,0);
    srand(time(NULL));
    x =1;
    std::cout << x;
    move = new KeyboardMovement(game->getSetup(),player,stage1->getSurface()->w,stage1->getSurface()->h);
    player->getPlayer()->setWidth(stage1->getSurface()->w);
    player->getPlayer()->setHeight(stage1->getSurface()->h);
    player->getPlayer()->setX(0);
    player->getPlayer()->setY(0);



}
void FieldState::Draw(GameEngine *game)
{
    DrawVisitor visitor;
    player->setCamera();
    camera = player->getCamera();
    stage1->setRect(camera);
    stage1->accept(&visitor);
    player->Draw();

}
void FieldState::Update(GameEngine *game)
{
    if(x ==10)
    {
        game->ChangeState(BattleState::Instance());
    }
}
void FieldState::HandleEvents(GameEngine *game)
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

