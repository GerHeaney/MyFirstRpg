#include "fieldstate.h"



FieldState FieldState::field;

void FieldState::Init(GameEngine *game)
{

    std::cout <<" got to  field init" << std::endl;
    stage1 = new BackgroundSprite(game->getSetup()->getRenderer(),"resources/map.png");
            //new Environment(game->getSetup(),game->getScreenWidth(),game->getScreenHeight());
    player = game->getPlayer();
    player->setOrigin(0,0);
    x =1;
 //   std::cout << x;
    move = new KeyboardMovement(game->getSetup(),player,stage1->getSurface()->w,stage1->getSurface()->h);
    player->getSprite()->setX(0);
    player->getSprite()->setY(0);
    std::cout <<" skillpoints are " << player->getEntityLevel()->getSkillPoints()<< std::endl;
    Level * level = new Level();
 //   std::cout <<" got to end of field init" << std::endl;


   std::cout<<player->getName() <<" is level "  << player->getEntityLevel()->getCurrentLevel()<< std::endl;
   std::cout<<player->getName() <<" has "  << player->getEntityLevel()->getCurrentXP()<< " xp "<< std::endl;
   std::cout<<player->getName() <<" needs "  << player->getEntityLevel()->getNextLevelXP()<<" xp for the next level" << std::endl;




   level->setuplevels(300,350000,30);



}
void FieldState::Draw(GameEngine *game)
{
    DrawVisitor visitor;

    stage1->accept(&visitor);
    player->getSprite()->accept(&visitor);
 //   std::cout <<" got to end of field draw" << std::endl;

}
void FieldState::Update(GameEngine *game)
{
    game->getGameCamera()->setCamera(player->getSprite()->getX(),player->getSprite()->getY(),stage1);
    camera = game->getGameCamera()->getCamera();
    stage1->setRect(camera);
    player->getSprite()->setPositionRect(player->getSprite()->getX() - camera.x,player->getSprite()->getY() - camera.y);
    if(x ==10)
    {
        player->setIsMoving(false);
        x = 1;
        game->PushState(BattleState::Instance());
    }
//    std::cout <<" got to end of field update" << std::endl;
}
void FieldState::HandleEvents(GameEngine *game)
{
    if(player->GetMoving() == true)
    {
 //       std::cout << x << std::endl;
        x = rand() % 500 + 1;

    }
//    std::cout <<" got to end of handle events" << std::endl;

    move->Move(game->getSetup());
    if(game->getSetup()->getMainEvent()->key.keysym.sym == SDLK_i)
    {
        game->PushState(MenuState::Instance());
    }

}
void FieldState::Pause()
{

}
void FieldState::Resume(GameEngine *game)
{
    std::cout<<player->getName() <<" is level "  << player->getEntityLevel()->getCurrentLevel()<< std::endl;
    std::cout<<player->getName() <<" has "  << player->getEntityLevel()->getCurrentXP()<< " xp "<< std::endl;
    std::cout<<player->getName() <<" needs "  << (player->getEntityLevel()->getNextLevelXP()) - (player->getEntityLevel()->getCurrentXP())<<" xp for the next level" << std::endl;
    move->Stop();
    player->getSprite()->setPositionRect(player->getSprite()->getX() - camera.x,player->getSprite()->getY() - camera.y);

}


void FieldState::Cleanup()
{
    std::cout <<" got to  field cleanup" << std::endl;
   delete stage1;
   delete move;

}

