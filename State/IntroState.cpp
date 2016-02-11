#include "IntroState.h"

IntroState IntroState::intro;
//{
//    setup = passedSetup;
//    menu = new CSprite(setup->getRenderer(),"resources/MainMenu/mainmenu.png",0,0,setup->getScreenWidth(),setup->getScreenHeight());
//}
void IntroState::Init(GameEngine *game)
{
  menu = new BackgroundSprite(game->getRenderer(),"resources/MainMenu/mainmenu.png");
  drawer = new DrawVisitor();
  nButton = new Button(game->getSetup(),"resources/MainMenu/new.png");
  lButton = new Button(game->getSetup(),"resources/MainMenu/load.png");
  qButton = new Button(game->getSetup(),"resources/MainMenu/quit.png");
  nButton->Init();
  lButton->Init();
  qButton->Init();
  nButton->setPosition(game->getScreenWidth()/3 + 100, game->getScreenHeight() - 100 - (nButton->getHeight()*3) );
  lButton->setPosition(game->getScreenWidth()/3 + 100, game->getScreenHeight() - 100 - (lButton->getHeight()*2) );
  qButton->setPosition(game->getScreenWidth()/3 + 100, game->getScreenHeight() - 100 - qButton->getHeight());
  camera = game->getPlayer()->getCamera();
  menu->setRect(camera);






}

void IntroState::Draw(GameEngine *game)
{


    menu->accept(drawer);
    nButton->render();
    lButton->render();
    qButton->render();





}
void IntroState::Update(GameEngine *game)
{


}
void IntroState::HandleEvents(GameEngine *game)
{
    nButton->handleEvent();
    lButton->handleEvent();
    qButton->handleEvent();
    if(nButton->getPressed() == true)
    {
        game->ChangeState(FieldState::Instance());
    }
    if(qButton->getPressed() == true)
    {

        game->Quit();
    }

}
void IntroState::Pause()
{

}
void IntroState::Resume()
{

}
void IntroState::Cleanup()
{
    std::cout << "reached the cleanup" << std::endl;
    delete nButton;

}
