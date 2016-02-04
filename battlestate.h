#ifndef BATTLESTATE_H
#define BATTLESTATE_H

#include "sdl_setup.h"
#include "csprite.h"
#include "gamestate.h"
#include "button.h"
#include "maincharacter.h"
#include <time.h>


class BattleState : public GameState
{
public:
    void Init(MainClass* game) ;
    void Update(MainClass* game);
    void Draw(MainClass* game);
    void HandleEvents(MainClass* game);
    void Cleanup();

    void Pause();
    void Resume();

    void Draw();
    static BattleState * Instance() {
        return &battle;
    }
protected:
    BattleState() {}

private:
    static BattleState battle;
    SDL_Point playerPosition;
    SDL_Point enemyPosition;
    SDL_Rect menuRect;
    CSprite * background;
    CSprite * enemy;
    CSprite * menu;
    MainCharacter * player;
    SDL_Rect camera;

};

#endif // BATTLESTATE_H
