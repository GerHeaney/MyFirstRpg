#ifndef DISPLAYFIELD_H
#define DISPLAYFIELD_H
#include "GameSetup/sdl_setup.h"
#include <sstream>
class DisplayField
{
public:
    DisplayField();
    ~DisplayField();
    void Init();
    void Display(SDL_setup *setup, int red =250, int green =250, int blue = 250);
    void setPosition(int x, int y);
    void setText(std::string item1 = "",std::string item2 = "");
    std::string toString(int number);
    SDL_Color getTextColor() const;
    void setTextColor(int red, int green, int blue);

private:
    int xPos;
    int yPos;
    SDL_Rect  button;
    TTF_Font * gameFont;
    std::string text;
    SDL_Color textColor;

};

#endif // DISPLAYFIELD_H
