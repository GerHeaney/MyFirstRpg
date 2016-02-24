#include "RenderItems/fontbutton.h"

FontButton::FontButton(SDL_setup *passedSetup, std::string passedPath,std::string drawText)
{

    setup = passedSetup;
    path = passedPath;
    text = drawText;
    textColor = { 250, 250, 250 };


   // mTexture = SDL_CreateTextureFromSurface(setup->getRenderer(),surface);

    pressed = false;


}

FontButton::~FontButton()
{
 //   TTF_CloseFont(gameFont);



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
                //over the button
               case SDL_MOUSEMOTION:           
               SetTextColour(150,150,150);            
               break;

                    // button pressed
               case SDL_MOUSEBUTTONDOWN:             
               SetTextColour(50,50,50);
               if(pressed == true)
               {
                   pressed = false;
                   break;
               }else{
                   SDL_Delay(200);
                   pressed = true;
               }
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
