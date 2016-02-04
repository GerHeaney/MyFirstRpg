#ifndef CSPRITE_H
#define CSPRITE_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>

class CSprite

{
public:
    CSprite(SDL_Renderer *gameRenderer, std::string path, int x, int y, int w, int h);
    //CSprite(SDL_Renderer * gameRenderer, std::string path, int x, int y);
    ~CSprite();
    void Draw();
    void DrawBackground(SDL_Rect *clip);

    void setX(float X);
    void setY(float Y);
    void setPosition(float X, float Y);

    float getX();
    float getY();

    void setOrigin(float X, float Y);

    int getWidth();
    void setWidth(int value);

    int getHeight();
    void setHeight(int value);

    void setCamera();
    void setInitFrame(int startFrame,int row);
    void setupAnimation(int passedX, int passedY);
    void playAnimation(int startFrame, int endFrame,int row, float speed);

    float *getCameraX();
    void setCameraX(float *value);

    float *getCameraY();
    void setCameraY(float *value);

private:
    SDL_Rect camera;
    int cameraW;
    int cameraH;
//    float *cameraX = 0;
//    float *cameraY = 0;
    float xOrigin;
    float yOrigin;
    float XPos;
    float YPos;
    int Width;
    int Height;
    int currentFrame;
    int frameSpeed;

    int frameX;
    int frameY;
    SDL_Surface * surface;
    SDL_Texture * image;
    SDL_Rect rect;
    SDL_Renderer *renderer;
    SDL_Rect crop;


};

#endif // CSPRITE_H
