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
    void Display(SDL_setup *setup);
    void setPosition(int x, int y);
    void setText(std::string item1 = "",std::string item2 = "");
    std::string toString(int number);
private:
    int xPos;
    int yPos;
    SDL_Rect  button;
    TTF_Font * gameFont; 
    std::string text;
    SDL_Color textColor;

};

#endif // DISPLAYFIELD_H
