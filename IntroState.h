#ifndef INTROMENU_H
#define INTROMENU_H
#include "sdl_setup.h"
#include "csprite.h"
#include "gamestate.h"
#include "button.h"
#include "fieldstate.h"

class IntroState : public GameState
{
public:
    Button * nButton;
    Button * lButton;
    Button * qButton;


    void Init(MainClass* game) ;
    void Update(MainClass* game);
    void Draw(MainClass* game);
    void HandleEvents(MainClass* game);
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
protected:
    IntroState() {}
};

#endif // INTROMENU_H
