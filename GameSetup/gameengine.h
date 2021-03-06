#ifndef MAINCLASS_H
#define MAINCLASS_H


#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <math.h>
#include "sdl_setup.h"
#include "RenderItems/csprite.h"
//#include "keyboardmovement.h"
#include "Input/mousemovement.h"
#include "Entity/maincharacter.h"
#include "RenderItems/environment.h"
//#include "IntroState.h"

#include <vector>
class GameState;

class GameEngine
{
public:
    GameEngine(int width, int height);
    ~GameEngine();
    void GameLoop();
    void ChangeState(GameState* state);
    void PushState(GameState* state);
    void PopState();

    void HandleEvents();
    void Update();
    void Draw();

    bool Running() { return running; }
    void Quit() { running = false; }


    SDL_Renderer *getRenderer();


    int getScreenWidth() const;

    int getScreenHeight() const;

    SDL_setup *getSetup() const;

    MainCharacter *getPlayer() const;
    void setPlayer(MainCharacter *value);

    int getLevelWidth() const;

    int getLevelHeight() const;

    Environment *getStage1() const;
    void setStage1(Environment *value);

private:
    float cameraX;
    float cameraY;
    int screenWidth;
    int screenHeight;
    int levelWidth;
    int levelHeight;
    bool quit;
    bool running;
    std::vector<GameState*> states;

    Environment* stage1;
    GameState * intro;


    SDL_Rect camera;
    SDL_setup* setup;
    MainCharacter *player;
    //KeyboardMovement *keyMove;
    MouseMovement * mouseMove;





};

#endif // MAINCLASS_H
