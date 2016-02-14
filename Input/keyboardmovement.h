#ifndef KEYBOARDMOVEMENT_H
#define KEYBOARDMOVEMENT_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "Entity/maincharacter.h"
#include "GameSetup/sdl_setup.h"


class KeyboardMovement
{
public:
    KeyboardMovement(SDL_setup * setup, Entity *passedPlayer,int width,int height);
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
    int levelWidth;
    int levelHeight;

    int timeCheck;


};

#endif // KEYBOARDMOVEMENT_H
