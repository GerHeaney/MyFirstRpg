#ifndef BATTLESTATE_H
#define BATTLESTATE_H

#include "GameSetup/sdl_setup.h"
#include "Sprite/enemysprite.h"
#include "Sprite/menusprite.h"
#include "State/gamestate.h"
#include "RenderItems/button.h"
#include "Entity/maincharacter.h"
#include "RenderItems/fontbutton.h"
#include "Visitor/drawvisitor.h"
#include "Entity/enemy.h"
#include "RenderItems/displayfield.h"
#include <time.h>


class BattleState : public GameState
{
public:
    void Init(GameEngine* game) ;
    void Update(GameEngine* game);
    void Draw(GameEngine* game);
    void HandleEvents(GameEngine* game);
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
    DisplayField playerField;
    DisplayField enemyField;
    FontButton * Attack;
    FontButton * Ability;
    FontButton * Item;
    static BattleState battle;
    SDL_Point playerPosition;
    SDL_Point enemyPosition;
    SDL_Rect menuRect;
    BackgroundSprite * background;
    Enemy * enemy;
    MenuSprite * menu;
    MainCharacter * player;
    SDL_Rect camera;

};

#endif // BATTLESTATE_H
