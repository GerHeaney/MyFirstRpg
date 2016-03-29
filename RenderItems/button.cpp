#include "button.h"

Button::Button( std::string path)
{
    buttonPath = path;
    over = false;
    clicked = false;






}
void Button::Init(SDL_setup *setup)
{
    textSurface = IMG_Load(buttonPath.c_str());
    textTexture = SDL_CreateTextureFromSurface(setup->getRenderer(),textSurface);

    overSurface = IMG_Load("resources/MainMenu/selected.png");
    overTexture =SDL_CreateTextureFromSurface(setup->getRenderer(),overSurface);

    selectedSurface = IMG_Load("resources/MainMenu/pressed.png");
    selectedTexture = SDL_CreateTextureFromSurface(setup->getRenderer(),selectedSurface);
    button = {0,0,textSurface->w,textSurface->h};
    mWidth = textSurface->w;
    mHeight = textSurface->h;
    pressed = false;

}

Button::~Button()
{
    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(overTexture);
    SDL_FreeSurface(overSurface);
    SDL_DestroyTexture(selectedTexture);
    SDL_FreeSurface(selectedSurface);

}

void Button::setPosition( int x, int y )
{
    mPosition.x = x;
    mPosition.y = y;



}
void Button::handleEvent(SDL_setup * setup)
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

            render(setup);
            over = false;
            clicked = false;

        }else{



            //Set mouse over sprite
            switch(setup->getMainEvent()->type )
            {
                case SDL_MOUSEMOTION:
                std::cout << "over the button" << std::endl;
               over = true;



                break;

                case SDL_MOUSEBUTTONDOWN:
                // button pressed
                std::cout <<"pressed" << std::endl;
                clicked = true;
               // render(setup,selectedTexture);


                break;

                case SDL_MOUSEBUTTONUP:
                std::cout <<"released" << std::endl;
                // button released
             //   render(setup,overTexture);


                pressed = true;

                break;
            }


        }






}

void Button::render(SDL_setup *setup)
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = {  mPosition.x,  mPosition.y, mWidth, mHeight };

    //Set clip rendering dimensions

        renderQuad.w = button.w;
        renderQuad.h = button.h;


    //Render to screen
    SDL_RenderCopy( setup->getRenderer(), textTexture, &button, &renderQuad);
    if(over)
    {
        SDL_RenderCopy( setup->getRenderer(), overTexture, &button, &renderQuad);
    }
    if(clicked)
    {
        SDL_RenderCopy( setup->getRenderer(), selectedTexture, &button, &renderQuad);
    }



}

bool Button::getPressed() const
{
    return pressed;
}

void Button::setPressed(bool value)
{
    pressed = value;
}


void Button::free()
{
}
int Button::getWidth()
{
    return mWidth;
}

int Button::getHeight()
{
    return mHeight;
}

