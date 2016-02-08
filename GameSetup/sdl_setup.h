#ifndef SDL_SETUP_H
#define SDL_SETUP_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "SDL_ttf.h"
class SDL_setup
{
public:
    SDL_setup(bool *quit, int width, int height);
    ~SDL_setup();

    SDL_Renderer *getRenderer() const;
    void setRenderer(SDL_Renderer *value);

    SDL_Window *getWindow() const;
    void setWindow(SDL_Window *value);

    SDL_Event *getMainEvent() const;
    void setMainEvent(SDL_Event *value);

    void Begin();
    void End();
    int getScreenWidth();
    void setScreenWidth(int value);

    int getScreenHeight();
    void setScreenHeight(int value);

private:
    int screenWidth;
    int screenHeight;
    SDL_Window * window;
    SDL_Renderer * renderer;
    SDL_Event * mainEvent;
};

#endif // SDL_SETUP_H
