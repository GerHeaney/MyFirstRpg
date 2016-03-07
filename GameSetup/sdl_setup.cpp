#include "sdl_setup.h"

SDL_setup::SDL_setup(bool* quit, int width, int height)
{
    screenWidth = width;
    screenHeight = height;
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    if( TTF_Init() == -1 )
    {
        std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;

    }
    window = NULL;
    window = SDL_CreateWindow("MyFirstRPG",400,100,screenWidth,screenHeight,SDL_WINDOW_SHOWN);

       if (window == NULL)
        {
         std::cout << "Window couldn't be created" << std::endl;
         *quit =true;
        }
    renderer = NULL;
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC  );

    mainEvent = new SDL_Event();
}

SDL_setup::~SDL_setup()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    delete mainEvent;
}

SDL_Renderer *SDL_setup::getRenderer() const
{
    return renderer;
}

void SDL_setup::setRenderer(SDL_Renderer *value)
{
    renderer = value;
}

SDL_Window *SDL_setup::getWindow() const
{
    return window;
}

void SDL_setup::setWindow(SDL_Window *value)
{
    window = value;
}

SDL_Event *SDL_setup::getMainEvent() const
{
    return mainEvent;
}

void SDL_setup::setMainEvent(SDL_Event *value)
{
    mainEvent = value;
}

void SDL_setup::Begin()
{
    //SDL_PollEvent(mainEvent);
    SDL_RenderClear(renderer);
}
void SDL_setup::End()
{
   SDL_RenderPresent(renderer);
}

int SDL_setup::getScreenWidth()
{
    return screenWidth;
}

void SDL_setup::setScreenWidth(int value)
{
    screenWidth = value;
}

int SDL_setup::getScreenHeight()
{
    return screenHeight;
}

void SDL_setup::setScreenHeight(int value)
{
    screenHeight = value;
}
