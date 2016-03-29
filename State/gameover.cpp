#include "gameover.h"

GameOver GameOver::gameOver;


void GameOver::Init(GameEngine *game)
{
    background = new BackgroundSprite(game->getRenderer(),"resources/Battle/gameover.png");
    newGame = new FontButton(game->getSetup(),"NEW GAME");
    quit = new FontButton(game->getSetup(),"QUIT");

    newGame->setPosition(game->getScreenWidth()/2,game->getScreenHeight()*0.8);
    quit->setPosition(game->getScreenWidth()/2,game->getScreenHeight()*0.9);
}

void GameOver::Update(GameEngine *game)
{
    if(newGame->getPressed())
    {
        game->PushState(IntroState::Instance());
    }
    if(quit->getPressed())
    {
        game->Quit();
    }
}

void GameOver::Draw(GameEngine *game)
{DrawVisitor visitor;
    background->accept(&visitor);
    newGame->Draw(game->getScreenWidth()*0.7,game->getScreenHeight()*0.3);
    quit->Draw(game->getScreenWidth()*0.7,game->getScreenHeight()*0.375);
}

void GameOver::HandleEvents(GameEngine *game)
{
    while(SDL_PollEvent(game->getSetup()->getMainEvent()))
    {
        newGame->handleEvent();
        quit->handleEvent();
    }
}

void GameOver::Cleanup()
{
    delete background;
    delete newGame;
    delete quit;
}

void GameOver::Pause()
{
}

void GameOver::Resume(GameEngine *game)
{
}
