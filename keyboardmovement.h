#ifndef KEYBOARDMOVEMENT_H
#define KEYBOARDMOVEMENT_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "maincharacter.h"
#include "sdl_setup.h"


class KeyboardMovement
{
public:
    KeyboardMovement(SDL_setup * passedSetup, MainCharacter *passedPlayer);
    void Move();

private:

    SDL_setup * setup;
    MainCharacter * player;
    int x;
    int y;
    bool MoveRight;
    bool MoveLeft;
    bool MoveUp;
    bool MoveDown;

    int timeCheck;


};

#endif // KEYBOARDMOVEMENT_H
