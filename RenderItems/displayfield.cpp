#include "displayfield.h"

DisplayField::DisplayField(SDL_setup *passedSetup, std::string passedPath, std::string drawText)
{
    gameFont = TTF_OpenFont( "resources/RPGSystem.ttf", 35 );
    setup = passedSetup;
    path = passedPath;
    text = drawText;
    textColor = { 250, 250, 250 };
    surface = TTF_RenderText_Solid( gameFont, text.c_str(),textColor );
    if( surface == NULL )
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
}

