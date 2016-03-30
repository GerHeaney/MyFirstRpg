#include "gameengine.h"
#include "State/gamestate.h"
#include "State/IntroState.h"
GameEngine::GameEngine(int width, int height)
{
    srand(time(NULL));
    screenWidth = width;
    screenHeight = height;
    quit = false;
    running = true;

    setup = new SDL_setup(&quit,width,height);
    inventory = inventory->partyInventory();
    Potion *potion = new Potion();
    Ether * ether = new Ether(setup);
    potion->setQuantity(99);

     ether->setQuantity(99);
    inventory->addItem(ether);
     inventory->addItem(potion);

    player2 = new MainCharacter(setup,"Ger","resources/Characters/belf22.png");
    player = new MainCharacter(setup,"Bill","resources/Characters/belf1.png");
    Weapon * javelin =new Weapon(setup,Item::SPEAR,"Javelin",200,100,"resources/Items/spear.png");
    Weapon * ironSword = new Weapon(setup,Item::SWORD,"Iron Sword",200,100,"resources/Items/sword.png");
    Weapon * hatchet = new Weapon(setup,Item::AXE,"Hatchet",200,100,"resources/Items/axe.png");
    Weapon * hammer = new Weapon(setup,Item::MACE,"Hammer",200,100,"resources/Items/mace.png");
    Weapon * battleAxe = new Weapon(setup,Item::AXE,"Battle Axe",200,170,"resources/Items/axe.png");

    player->setWeapon(javelin);
    player2->setWeapon(ironSword);
    inventory->addItem(javelin);
    inventory->addItem(ironSword);
    inventory->addItem(hatchet);
    inventory->addItem(hammer);
    inventory->addItem(battleAxe);
    player->getSkillMap()->at("Spear Skill") = 20;

    gameCamera = new Camera();
    gameCamera->setCameraW(width);
    gameCamera->setCameraH(height);
    party.push_back(player);
    party.push_back(player2);






 }

GameEngine::~GameEngine()
{

    delete setup;
    delete stage1;
    //delete keyMove;
    delete player;
    delete gameCamera;

}
void GameEngine::ChangeState(GameState* state)
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

void GameEngine::PushState(GameState* state)
{
    // pause current state
    if ( !states.empty() ) {
        states.back()->Pause();
    }

    // store and init the new state
    states.push_back(state);
    states.back()->Init(this);
}

void GameEngine::PopState()
{
    // cleanup the current state
    if ( !states.empty() ) {
        states.back()->Cleanup();
        states.pop_back();
    }

    // resume previous state
    if ( !states.empty() ) {
        states.back()->Resume(this);
    }
}


void GameEngine::HandleEvents()
{
    // let the state handle events
    states.back()->HandleEvents(this);
}

void GameEngine::Update()
{
    // let the state update the game
    states.back()->Update(this);
}

void GameEngine::Draw()
{
    // let the state draw the screen
    states.back()->Draw(this);
}

SDL_Renderer *GameEngine::getRenderer()
{
    return setup->getRenderer();
}

int GameEngine::getScreenWidth() const
{
    return screenWidth;
}

int GameEngine::getScreenHeight() const
{
    return screenHeight;
}

SDL_setup *GameEngine::getSetup() const
{
    return setup;
}

MainCharacter *GameEngine::getPlayer() const
{
    return player;
}

void GameEngine::setPlayer(MainCharacter *value)
{
    player = value;
}

int GameEngine::getLevelWidth() const
{
    return stage1->getLevelWidth();
}

int GameEngine::getLevelHeight() const
{
    return stage1->getLevelHeight();
}

Environment *GameEngine::getStage1() const
{
    return stage1;
}

void GameEngine::setStage1(Environment *value)
{
    stage1 = value;
}

Camera *GameEngine::getGameCamera() const
{
    return gameCamera;
}

void GameEngine::setGameCamera(Camera *value)
{
    gameCamera = value;
}

std::vector<Entity *> *GameEngine::getParty()
{
    return &party;
}



void GameEngine::GameLoop()
{

    while (running && setup->getMainEvent()->type != SDL_QUIT)
    {


        setup->Begin();
        Draw();
        Update();
        HandleEvents();
        setup->End();



    }
}
