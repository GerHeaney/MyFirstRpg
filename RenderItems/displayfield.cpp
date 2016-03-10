#include "displayfield.h"

DisplayField::DisplayField()
{
    gameFont = TTF_OpenFont( "resources/RPGSystem.ttf", 35 );
    textColor = { 250, 250, 250 };
    text = "  ";

}

DisplayField::~DisplayField()
{
    //delete gameFont;
    TTF_CloseFont(gameFont);

}
void DisplayField::Init()
{


}

void DisplayField::Display(SDL_setup * setup,int red,int green, int blue)
{
    SDL_Color colour = {red,green,blue};

    SDL_Surface * displaySurface = TTF_RenderText_Solid( gameFont, text.c_str(),colour );
    if( displaySurface == NULL )
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    SDL_Texture * displayTexture= SDL_CreateTextureFromSurface(setup->getRenderer(),displaySurface);


     button = {0,0,displaySurface->w,displaySurface->h};
    SDL_Rect renderQuad = {  xPos, yPos, displaySurface->w,displaySurface->h };


    //Render to screen
    SDL_RenderCopy( setup->getRenderer(),displayTexture, &button, &renderQuad);
    SDL_FreeSurface(displaySurface);
    SDL_DestroyTexture(displayTexture);


}

void DisplayField::setPosition(int x, int y)
{
    xPos = x;
    yPos = y;
}

void DisplayField::setText(std::string item1, std::string item2)
{
    text = (item1 + " " + item2);
   // std::cout << text << std::endl;
}

std::string DisplayField::toString(int number)
{
    std::ostringstream infoString;
    infoString << number;
    std::string numberString = infoString.str();
    return numberString;

}

SDL_Color DisplayField::getTextColor() const
{
    return textColor;
}

void DisplayField::setTextColor(int red, int green, int blue)
{
    textColor = {red,green,blue};
}
