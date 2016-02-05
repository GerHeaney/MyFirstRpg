#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "RenderItems/csprite.h"
#include "GameSetup/sdl_setup.h"



class MainCharacter
{
public:
    MainCharacter(SDL_setup *gameSetup, int width, int height);
    ~MainCharacter();

    void setX(int X);
    void setY(int Y);
    void setPosition(int X, int Y);

    int getX();
    int getY();

    void setOrigin(int X, int Y);

    int getWidth();
    void setWidth(int value);

    int getHeight();
    void setHeight(int value);

    void Draw();
    void Update();
    void Move();
    CSprite *getPlayer();
    void setPlayer(CSprite *value);
    void setCamera();
    void setInitFrame(int startFrame,int row);
    void playAnimation(int startFrame, int endFrame,int row, float speed);


    void setupAnimation(int passedX, int passedY);
    SDL_Rect getCamera();
    int getCameraX();
    int getCameraY();
    bool GetMoving();

    void setIsMoving(bool value);

private:

    bool MoveRight;
    bool MoveLeft;
    bool MoveUp;
    bool MoveDown;
    bool isMoving;

    int dotVel;
    int mVelX;
    int mVelY;
    int timeCheck;
    int XPos;
    int YPos;
    int xOrigin;
    int yOrigin;
    float cameraX;
    float cameraY;
    int screenWidth;
    int screenHeight;
    int levelWidth;
    int levelHeight;

    int currentFrame;
    int frameSpeed;

    int frameX;
    int frameY;
    SDL_Renderer * renderer;
    SDL_Surface * surface;
    SDL_Texture * image;
    SDL_Rect camera;
    SDL_Rect playerRect;
    CSprite* player;
    SDL_setup *setup;




};

#endif // MAINCHARACTER_H
