#ifndef DISPLAYFIELD_H
#define DISPLAYFIELD_H
#include "GameSetup/sdl_setup.h"


class DisplayField
{
public:
    DisplayField(SDL_setup *passedSetup, std::string passedPath, std::string drawText);

private:
    bool pressed;
    SDL_Point mPosition;
    SDL_setup * setup;
    SDL_Rect  button;
    SDL_Surface * surface;
    SDL_Texture* mTexture;
    TTF_Font * gameFont;
    SDL_Rect outlineRect;
    std::string text;
    SDL_Color textColor;
    std::string path;
};

#endif // DISPLAYFIELD_H
