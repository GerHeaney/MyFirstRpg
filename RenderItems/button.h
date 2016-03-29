#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "GameSetup/sdl_setup.h"
#include "Input/mousemovement.h"
class MouseMovement;
class Button
{

    public:
        Button(std::string path);

        void Init(SDL_setup *setup);
        void setPosition( int x, int y );
        ~Button();
        void handleEvent(SDL_setup * setup);
        bool loadFromFile( std::string path );
        int getWidth();
        int getHeight();
        void free();
        std::string buttonPath;
        void Update();
        void render(SDL_setup *setup);

        bool getPressed() const;
        void setPressed(bool value);

        SDL_Point getPosition() const;

private:
        //After the state pattern was implemented the draw selected function was no longer needed.
        //the purpose of the function was to update the button when events occur

       // void drawSelected();




        //Image dimensions
        int mWidth;
        int mHeight;      
        MouseMovement *move;

protected:
        SDL_setup * setup;
        SDL_Rect  button;
        SDL_Surface * textSurface;
        SDL_Surface * overSurface;
        SDL_Surface * selectedSurface;
        SDL_Texture * textTexture;
        SDL_Texture * overTexture;
        SDL_Texture * selectedTexture;
        SDL_Point mPosition;
        bool pressed;
        bool over;
        bool clicked;

        //Currently used global sprite


};


#endif // BUTTON_H
