#include "fieldstate.h"


FieldState FieldState::field;

void FieldState::Init(GameEngine *game)
{
    stage1 = new BackgroundSprite(game->getSetup()->getRenderer(),"resources/map.png");
            //new Environment(game->getSetup(),game->getScreenWidth(),game->getScreenHeight());
    player = game->getPlayer();
    player->setOrigin(0,0);
    srand(time(NULL));
    x =10;
    std::cout << x;
    move = new KeyboardMovement(game->getSetup(),player,stage1->getSurface()->w,stage1->getSurface()->h);
    player->getSprite()->setX(0);
    player->getSprite()->setY(0);



}
void FieldState::Draw(GameEngine *game)
{
    DrawVisitor visitor;

    stage1->accept(&visitor);
    player->getSprite()->accept(&visitor);

}
void FieldState::Update(GameEngine *game)
{
    game->getGameCamera()->setCamera(player->getSprite()->getX(),player->getSprite()->getY(),stage1);
    camera = game->getGameCamera()->getCamera();
    stage1->setRect(camera);
    player->getSprite()->setPositionRect(player->getSprite()->getX() - camera.x,player->getSprite()->getY() - camera.y);
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

