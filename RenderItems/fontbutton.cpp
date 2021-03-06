#include "RenderItems/fontbutton.h"

FontButton::FontButton(SDL_setup *passedSetup, std::string passedPath,std::string drawText)
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
   // mTexture = SDL_CreateTextureFromSurface(setup->getRenderer(),surface);
    button = {0,0,surface->w,surface->h};
    pressed = false;



}
void FontButton::setPosition( int x, int y )
{
    mPosition.x = x;
    mPosition.y = y;



}



void FontButton::Draw(int X , int Y)
{

    SDL_Surface * asurf = TTF_RenderText_Solid( gameFont, text.c_str(),textColor );
    SDL_Texture * TT = SDL_CreateTextureFromSurface(setup->getRenderer(),asurf);

    setPosition(X,Y);
    SDL_Rect renderQuad = {  X, Y, surface->w,surface->h };


    //Render to screen
    SDL_RenderCopy( setup->getRenderer(),TT, &button, &renderQuad);
    SDL_FreeSurface(asurf);
    SDL_DestroyTexture(TT);





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

       //Check if mouse is in button
       bool inside = true;

       //Mouse is left of the button
       if( x < mPosition.x )
       {
           inside = false;
       }
       //Mouse is right of the button
       else if( x > mPosition.x + button.w )
       {
           inside = false;
       }
       //Mouse above the button
       else if( y < mPosition.y )
       {
           inside = false;
       }
       //Mouse below the button
       else if( y > mPosition.y + button.h )
       {
           inside = false;
       }

       //Mouse is outside button
       if( !inside )
       {
           SetTextColour(250,250,250);

       }
       //Mouse is inside button
       else
       {

           //Set mouse over sprite
           switch( setup->getMainEvent()->type )
           {
               case SDL_MOUSEMOTION:

               //Render green outlined quad
               SetTextColour(150,150,150);
               std:: cout << "over the button" << std::endl;
               break;

               case SDL_MOUSEBUTTONDOWN:
               // button pressed
               SetTextColour(50,50,50);
               std::cout <<"pressed" << std::endl;


               break;

               case SDL_MOUSEBUTTONUP:
               std::cout <<"released" << std::endl;
                SetTextColour(150,150,150);
               // button released


               pressed = true;

               break;
           }

   }
}
void FontButton::free()
{
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(mTexture);
}
