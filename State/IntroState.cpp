#include "IntroState.h"

IntroState IntroState::intro;
//{
//    setup = passedSetup;
//    menu = new CSprite(setup->getRenderer(),"resources/MainMenu/mainmenu.png",0,0,setup->getScreenWidth(),setup->getScreenHeight());
//}
void IntroState::Init(GameEngine *game)
{
  menu = new BackgroundSprite(game->getRenderer(),"resources/MainMenu/mainmenu.png");

  nButton = new Button("resources/MainMenu/new.png");
  lButton = new Button("resources/MainMenu/load.png");
  qButton = new Button("resources/MainMenu/quit.png");
  nButton->Init(game->getSetup());
  lButton->Init(game->getSetup());
  qButton->Init(game->getSetup());
  nButton->setPosition(game->getScreenWidth()/3 + 100, game->getScreenHeight() - 100 - (nButton->getHeight()*3) );
  lButton->setPosition(game->getScreenWidth()/3 + 100, game->getScreenHeight() - 100 - (lButton->getHeight()*2) );
  qButton->setPosition(game->getScreenWidth()/3 + 100, game->getScreenHeight() - 100 - qButton->getHeight());
  game->getGameCamera()->setCamera(0,0,menu);
  camera = game->getGameCamera()->getCamera();
  std:: cout << "camera x is " <<camera.x << std::endl;
  std:: cout << "camera y is " <<camera.y << std::endl;
  std:: cout << "camera w is " <<camera.w << std::endl;
  std:: cout << "camera h is " <<camera.h << std::endl;
  menu->setRect(camera);






}

void IntroState::Draw(GameEngine *game)
{
    DrawVisitor visitor;


    menu->accept(&visitor);
    nButton->render(game->getSetup());
    lButton->render(game->getSetup());
    qButton->render(game->getSetup());





}
void IntroState::Update(GameEngine *game)
{


}
void IntroState::HandleEvents(GameEngine *game)
{
    while(SDL_PollEvent(game->getSetup()->getMainEvent()))
    {
    qButton->handleEvent(game->getSetup()->getMainEvent(),game->getSetup());
    nButton->handleEvent(game->getSetup()->getMainEvent(),game->getSetup());
    lButton->handleEvent(game->getSetup()->getMainEvent(),game->getSetup());
    }

    if(nButton->getPressed() == true)
    {
        game->PushState(FieldState::Instance());
    }
    if(qButton->getPressed() == true)
    {

        game->Quit();
    }

}
void IntroState::Pause()
{

}
void IntroState::Resume(GameEngine *game)
{

}
void IntroState::Cleanup()
{
    std::cout << "reached the cleanup" << std::endl;
    delete nButton;
    delete menu;
    delete lButton;
    delete qButton;

}
