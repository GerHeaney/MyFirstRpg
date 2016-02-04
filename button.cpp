#include "button.h"

Button::Button(SDL_setup *passedSetup, std::string path)
{
    buttonPath = path;
    surface = IMG_Load(buttonPath.c_str());
    setup = passedSetup;
    mTexture = SDL_CreateTextureFromSurface(setup->getRenderer(),surface);
    selectedTexture =SDL_CreateTextureFromSurface(setup->getRenderer(),surface);
    button = {0,0,surface->w,surface->h};
    mWidth = surface->w;
    mHeight = surface->h;
    pressed = false;




}
Button::~Button()
{
    SDL_DestroyTexture(mTexture);
    SDL_DestroyTexture(selectedTexture);
    delete surface;
}

void Button::setPosition( int x, int y )
{
    mPosition.x = x;
    mPosition.y = y;
    render();


}
void Button::handleEvent()
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
            selectedTexture = NULL;
            render();

        }
        //Mouse is inside button
        else
        {
            //Set mouse over sprite
            switch( setup->getMainEvent()->type )
            {
                case SDL_MOUSEMOTION:
                surface = IMG_Load("resources/MainMenu/selected.png");
                selectedTexture =SDL_CreateTextureFromSurface(setup->getRenderer(),surface);
                render();

                std:: cout << "over the button" << std::endl;
                break;

                case SDL_MOUSEBUTTONDOWN:
                // button pressed
                std::cout <<"pressed" << std::endl;
                surface = IMG_Load("resources/MainMenu/pressed.png");
                selectedTexture =SDL_CreateTextureFromSurface(setup->getRenderer(),surface);
                render();

                break;

                case SDL_MOUSEBUTTONUP:
                std::cout <<"released" << std::endl;
                // button released
                surface = IMG_Load("resources/MainMenu/selected.png");
                selectedTexture =SDL_CreateTextureFromSurface(setup->getRenderer(),surface);
                render();
                pressed = true;

                break;
            }

    }
}

void Button::render()
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = {  mPosition.x,  mPosition.y, mWidth, mHeight };

    //Set clip rendering dimensions

        renderQuad.w = button.w;
        renderQuad.h = button.h;


    //Render to screen
    SDL_RenderCopy( setup->getRenderer(), mTexture, &button, &renderQuad);
    SDL_RenderCopy( setup->getRenderer(), selectedTexture, &button, &renderQuad);


}

bool Button::getPressed() const
{
    return pressed;
}

void Button::setPressed(bool value)
{
    pressed = value;
}
//void Button::drawSelected()
//{
//    //Set rendering space and render to screen
//    SDL_Rect renderQuad = {  mPosition.x,  mPosition.y, mWidth, mHeight };

//    //Set clip rendering dimensions

//        renderQuad.w = button.w;
//        renderQuad.h = button.h;


//    //Render to screen
//    SDL_RenderCopy( setup->getRenderer(), selectedTexture, &button, &renderQuad);

//}

void Button::free()
{
    //Free texture if it exists
    if( mTexture != NULL )
    {
        SDL_DestroyTexture( mTexture );
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}
int Button::getWidth()
{
    return mWidth;
}

int Button::getHeight()
{
    return mHeight;
}

