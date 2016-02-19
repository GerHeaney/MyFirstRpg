#ifndef FONTBUTTON_H
#define FONTBUTTON_H


#include <string.h>
#include <stdio.h>
#include <iostream>
#include "SDL_ttf.h"
#include "GameSetup/sdl_setup.h"



class FontButton
{
public:
    FontButton(SDL_setup *passedSetup, std::string passedPath, std::string drawText) ;
    ~FontButton();
    void Draw(int X, int Y);
    void handleEvent();
    void setPosition(int X, int Y);


    std::string path;

    bool getPressed() const;

    void setPressed(bool value);

private:
    bool pressed;
    SDL_Point mPosition;
    SDL_setup * setup;
    SDL_Rect  button;
    SDL_Texture* mTexture;
    TTF_Font * gameFont;
     SDL_Rect outlineRect;
     std::string text;
     SDL_Color textColor;
     void SetTextColour(int Red,int Green,int Blue);
     void free();


};

#endif // FONTBUTTON_H
