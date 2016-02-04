#include "IntroState.h"

IntroState IntroState::intro;
//{
//    setup = passedSetup;
//    menu = new CSprite(setup->getRenderer(),"resources/MainMenu/mainmenu.png",0,0,setup->getScreenWidth(),setup->getScreenHeight());
//}
void IntroState::Init(MainClass *game)
{
  menu = new CSprite(game->getRenderer(),"resources/MainMenu/mainmenu.png",0,0,game->getScreenWidth(),game->getScreenHeight());
  nButton = new Button(game->getSetup(),"resources/MainMenu/new.png");
  lButton = new Button(game->getSetup(),"resources/MainMenu/load.png");
  qButton = new Button(game->getSetup(),"resources/MainMenu/quit.png");
  nButton->setPosition(game->getScreenWidth()/3 + 100, game->getScreenHeight() - 100 - (nButton->getHeight()*3) );
  lButton->setPosition(game->getScreenWidth()/3 + 100, game->getScreenHeight() - 100 - (lButton->getHeight()*2) );
  qButton->setPosition(game->getScreenWidth()/3 + 100, game->getScreenHeight() - 100 - qButton->getHeight());
}

void IntroState::Draw(MainClass *game)
{
    menu->Draw();
    nButton->render();
    lButton->render();
    qButton->render();





}
void IntroState::Update(MainClass *game)
{


}
void IntroState::HandleEvents(MainClass *game)
{
    nButton->handleEvent();
    lButton->handleEvent();
    qButton->handleEvent();
    if(nButton->getPressed() == true)
    {
        game->ChangeState(FieldState::Instance());
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
