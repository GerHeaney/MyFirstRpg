#include "mainclass.h"
#include "gamestate.h"
#include "IntroState.h"
MainClass::MainClass(int width, int height)
{

    screenWidth = width;
    screenHeight = height;
    quit = false;

    setup = new SDL_setup(&quit,width,height);
    stage1 = new Environment(setup,screenWidth,screenHeight);
    //grass = new CSprite(setup->getRenderer(),"resources/map.png",0,0,screenWidth,screenHeight,&cameraX,&cameraY);
    player = new MainCharacter(setup,screenWidth,screenHeight,stage1->getLevelWidth(),stage1->getLevelHeight());
    //mouseMove = new MouseMovement(setup,player,&cameraX,&cameraY);
    //keyMove = new KeyboardMovement(setup,player);
    // //keyMove = new KeyboardMovement();

}

MainClass::~MainClass()
{

    delete setup;
    delete stage1;
    //delete keyMove;
    delete player;

}
void MainClass::ChangeState(GameState* state)
{
    // cleanup the current state
    if ( !states.empty() ) {
        states.back()->Cleanup();
        states.pop_back();
    }

    // store and init the new state
    states.push_back(state);
    states.back()->Init(this);
}

void MainClass::PushState(GameState* state)
{
    // pause current state
    if ( !states.empty() ) {
        states.back()->Pause();
    }

    // store and init the new state
    states.push_back(state);
    states.back()->Init(this);
}

void MainClass::PopState()
{
    // cleanup the current state
    if ( !states.empty() ) {
        states.back()->Cleanup();
        states.pop_back();
    }

    // resume previous state
    if ( !states.empty() ) {
        states.back()->Resume();
    }
}


void MainClass::HandleEvents()
{
    // let the state handle events
    states.back()->HandleEvents(this);
}

void MainClass::Update()
{
    // let the state update the game
    states.back()->Update(this);
}

void MainClass::Draw()
{
    // let the state draw the screen
    states.back()->Draw(this);
}

SDL_Renderer *MainClass::getRenderer()
{
    return setup->getRenderer();
}

int MainClass::getScreenWidth() const
{
    return screenWidth;
}

int MainClass::getScreenHeight() const
{
    return screenHeight;
}

SDL_setup *MainClass::getSetup() const
{
    return setup;
}

MainCharacter *MainClass::getPlayer() const
{
    return player;
}

void MainClass::setPlayer(MainCharacter *value)
{
    player = value;
}

int MainClass::getLevelWidth() const
{
    return stage1->getLevelWidth();
}

int MainClass::getLevelHeight() const
{
    return stage1->getLevelHeight();
}

Environment *MainClass::getStage1() const
{
    return stage1;
}

void MainClass::setStage1(Environment *value)
{
    stage1 = value;
}



void MainClass::GameLoop()
{

    while(!quit && setup->getMainEvent()->type !=SDL_QUIT)
    {
        setup->Begin();
        HandleEvents();
        Update();
        Draw();
        //player->setCamera();
        //camera = player->getCamera();
        //stage1->DrawBack(&camera);
        //player->Draw();
        //intro->Draw(this);
        //stage1->DrawFront(&camera);
        //keyMove->Move(setup,belf);
        //keyMove->Move();
        //mouseMove->Move();
        setup->End();

    }
}
