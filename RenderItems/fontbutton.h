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
    FontButton(SDL_setup *passedSetup, std::string drawText) ;
    ~FontButton();
    void Draw(int X, int Y);
    void handleEvent();
    void setPosition(int X, int Y);


    std::string path;

    bool getPressed() const;

    void setPressed(bool value);

    SDL_Point getPosition() const;

    bool getInside() const;
    void setInside(bool value);

    SDL_Rect getButton() const;
    void setButton(const SDL_Rect &value);

    std::string getText() const;
    void setText(const std::string &value);

    SDL_Color getTextColor() const;
    void setTextColor(const SDL_Color &value);

private:
    bool pressed;
    bool inside;
    SDL_Point mPosition;
    SDL_setup * setup;
    SDL_Rect  button;  
    SDL_Rect outlineRect;
    std::string text;
    SDL_Color textColor;
    void SetTextColour(int Red,int Green,int Blue);
    void free();


};

#endif // FONTBUTTON_H
