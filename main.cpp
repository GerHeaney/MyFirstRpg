
//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "GameSetup/gameengine.h"
#include "State/IntroState.h"
#include "Battle/battlestate.h"
#include "State/gameover.h"
#undef main

int main( int argc, char* args[] )
{



    GameEngine*  game = new GameEngine(1368,768);
    game->PushState(FieldState::Instance());
    game->GameLoop();

    return 0;
}
