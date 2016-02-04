#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "mainclass.h"


class GameState
{
public:
    virtual void Init(MainClass* game) = 0;
    virtual void Update(MainClass* game) = 0;
    virtual void Draw(MainClass* game) = 0;
    virtual void HandleEvents(MainClass* game) = 0;
    virtual void Cleanup() = 0;

    virtual void Pause() = 0;
    virtual void Resume() = 0;
    void ChangeState(MainClass* game, GameState* state) {
        game->ChangeState(state);
    }


private:


protected:
    GameState() {}


};
#endif // GAMESTATE_H
