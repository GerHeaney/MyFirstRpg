#ifndef FIELDSTATE_H
#define FIELDSTATE_H

#include "sdl_setup.h"
#include "csprite.h"
#include "gamestate.h"
#include <math.h>
#include <time.h>
#include "battlestate.h"
#include "keyboardmovement.h"


class FieldState : public GameState
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
    static FieldState * Instance() {
        return &field;
    }
protected:
    FieldState() {}

private:
    static FieldState field;
     Environment* stage1;
     MainCharacter *player;
     SDL_Rect  camera;
     KeyboardMovement * move;
     int x;
};

#endif // FIELDSTATE_H
