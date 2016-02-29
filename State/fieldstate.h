#ifndef FIELDSTATE_H
#define FIELDSTATE_H

#include "GameSetup/sdl_setup.h"
#include "Sprite/backgroundsprite.h"
#include "State/gamestate.h"
#include <math.h>
#include <time.h>
#include "Battle/battlestate.h"
#include "Input/keyboardmovement.h"
#include "Visitor/drawvisitor.h"


class FieldState : public GameState
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
    static FieldState * Instance() {
        return &field;
    }
protected:
    FieldState() {}

private:
    static FieldState field;
     BackgroundSprite * stage1;
     MainCharacter *player;
     SDL_Rect  camera;
     KeyboardMovement * move;
     int x;
};

#endif // FIELDSTATE_H
