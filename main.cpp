
//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "mainclass.h"
#include "IntroState.h"
#include "battlestate.h"
#undef main

int main( int argc, char* args[] )
{


    MainClass*  mainClass = new MainClass(1200,900);
    mainClass->ChangeState(IntroState::Instance());
    mainClass->GameLoop();

    return 0;
}
