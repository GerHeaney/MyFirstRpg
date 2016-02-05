
//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "gameengine.h"
#include "State/IntroState.h"
#include "State/battlestate.h"
#undef main

int main( int argc, char* args[] )
{


    GameEngine*  mainClass = new GameEngine(1200,900);
    mainClass->ChangeState(IntroState::Instance());
    mainClass->GameLoop();

    return 0;
}
