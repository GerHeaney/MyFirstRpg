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

    int getCropWidth();
    int getCropHeight();

    void setCamera();
    void setInitFrame(int startFrame,int row);
    void setupAnimation(int passedX, int passedY);
    void playAnimation(int startFrame, int endFrame,int row, float speed);

    int getCameraX();
    void setCameraX(int value);

    int getCameraY();
    void setCameraY(int value);

    SDL_Rect getCamera() const;

private:
    SDL_Rect camera;
    int cameraW;
    int cameraH;

    int xOrigin;
    int yOrigin;
    int XPos;
    int YPos;
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
