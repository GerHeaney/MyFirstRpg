#include "RenderItems/fontbutton.h"

FontButton::FontButton(SDL_setup *passedSetup,std::string drawText)
{

    setup = passedSetup;  
    text = drawText;
    textColor = { 250, 250, 250 };


   // mTexture = SDL_CreateTextureFromSurface(setup->getRenderer(),surface);

    pressed = false;
    inside = false;


}

FontButton::~FontButton()
{
    setup = NULL;
    delete setup;
}
void FontButton::setPosition( int x, int y )
{
    mPosition.x = x;
    mPosition.y = y;
}

bool FontButton::getPressed() const
{
    return pressed;
}

void FontButton::setPressed(bool value)
{
    pressed = value;
}

SDL_Point FontButton::getPosition() const
{
    return mPosition;
}

bool FontButton::getInside() const
{
    return inside;
}

void FontButton::setInside(bool value)
{
    inside = value;
}

SDL_Rect FontButton::getButton() const
{
    return button;
}

void FontButton::setButton(const SDL_Rect &value)
{
    button = value;
}

std::string FontButton::getText() const
{
    return text;
}

void FontButton::setText(const std::string &value)
{
    text = value;
}




void FontButton::Draw(int X , int Y)
{
    TTF_Font * gameFont = TTF_OpenFont( "resources/RPGSystem.ttf", 35 );
    SDL_Surface * asurf = TTF_RenderText_Solid( gameFont, text.c_str(),textColor );

    if( asurf == NULL )
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    SDL_Texture * TT = SDL_CreateTextureFromSurface(setup->getRenderer(),asurf);

    setPosition(X,Y);
    button = {0,0,asurf->w,asurf->h};
    SDL_Rect renderQuad = {  X, Y, asurf->w,asurf->h };


    //Render to screen
    SDL_RenderCopy( setup->getRenderer(),TT, &button, &renderQuad);
    SDL_FreeSurface(asurf);
    SDL_DestroyTexture(TT);
    TTF_CloseFont(gameFont);

}
void FontButton::SetTextColour(int Red, int Green, int Blue)
{
     textColor = {Red,Green,Blue};
}

void FontButton::handleEvent()
{


    //Get mouse position
       int x, y;
       SDL_GetMouseState( &x, &y );

//       std::cout << " x position is " << x << std::endl;
//        std::cout << " y position is " << y << std::endl;
        inside = false;

       //Check if mouse is in button


       //Mouse is left of the button
       if( x > mPosition.x  && x < mPosition.x + button.w && y >mPosition.y && y < mPosition.y + button.h)
       {
           inside = true;
       }
//       //Mouse is right of the button
//       else if( x > mPosition.x + button.w )
//       {
//           inside = false;
//       }
       //Mouse above the button
//       else if( y >mPosition.y && y < mPosition.y + button.h)
//       {
//           inside = true;
//       }
       //Mouse below the button
//       else if( y > mPosition.y + button.h )
//       {
//           inside = false;
//       }

       //Mouse is outside button
       if( !inside )
       {
           SetTextColour(250,250,250);


       }
       //Mouse is inside button
       if(inside)
       {




           //Set mouse over sprite
           switch( setup->getMainEvent()->type )
           {
                //over the button
               case SDL_MOUSEMOTION:
               std::cout <<"Over button " + text<<std::endl;
               SetTextColour(150,150,150);            
               break;

                    // button pressed
               case SDL_MOUSEBUTTONDOWN:             
               SetTextColour(50,50,50);

                   this->pressed = true;

               break;

                   // button released
               case SDL_MOUSEBUTTONUP:           
               SetTextColour(150,150,150);

               break;
           }



   }
}
void FontButton::free()
{

}
