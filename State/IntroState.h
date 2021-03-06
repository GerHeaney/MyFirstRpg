#ifndef INTROMENU_H
#define INTROMENU_H
#include "GameSetup/sdl_setup.h"
#include "RenderItems/csprite.h"
#include "State/gamestate.h"
#include "RenderItems/button.h"
#include "State/fieldstate.h"
#include "RenderItems/fontbutton.h"

class IntroState : public GameState
{
public:
    Button * nButton;
    Button * lButton;
    Button * qButton;



    void Init(GameEngine* game) ;
    void Update(GameEngine* game);
    void Draw(GameEngine* game);
    void HandleEvents(GameEngine* game);
    void Cleanup();

    void Pause();
    void Resume();

    void Draw();
    static IntroState * Instance() {
        return &intro;
    }

private:
    CSprite* menu;
    SDL_setup* setup;
    static IntroState intro;
    SDL_Rect camera;
protected:
    IntroState() {}
};

#endif // INTROMENU_H
