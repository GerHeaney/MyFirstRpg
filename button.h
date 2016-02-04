#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "sdl_setup.h"

class Button
{
    public:
        Button(SDL_setup * passedSetup, std::string path);
        void setPosition( int x, int y );
        ~Button();
        void handleEvent();
        bool loadFromFile( std::string path );
        int getWidth();
        int getHeight();
        void free();
        std::string buttonPath;
        void Update();
        void render();

        bool getPressed() const;
        void setPressed(bool value);

private:
        //After the state pattern was implemented the draw selected function was no longer needed.
        //the purpose of the function was to update the button when events occur

       // void drawSelected();

        SDL_Surface * surface;
        SDL_Texture* mTexture;
        SDL_Texture* selectedTexture;
        SDL_setup * setup;
        SDL_Rect  button;

        //Image dimensions
        int mWidth;
        int mHeight;
        SDL_Point mPosition;
        bool pressed;

        //Currently used global sprite


};


#endif // BUTTON_H
