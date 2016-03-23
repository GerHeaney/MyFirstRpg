#ifndef GAMEOVER_H
#define GAMEOVER_H


#include "GameSetup/sdl_setup.h"
#include "Sprite/backgroundsprite.h"
#include "State/gamestate.h"
#include "State/IntroState.h"
#include "Visitor/drawvisitor.h"
#include <RenderItems/fontbutton.h>

class GameOver : public GameState
{
public:



    // GameState interface
public:
    virtual void Init(GameEngine *game);
    virtual void Update(GameEngine *game);
    virtual void Draw(GameEngine *game);
    virtual void HandleEvents(GameEngine *game);
    virtual void Cleanup();
    virtual void Pause();
    virtual void Resume(GameEngine *game);
    static GameOver * Instance() {
        return &gameOver;

    }
private:
    static GameOver gameOver;
    BackgroundSprite * background;
    FontButton * newGame;
    FontButton * quit;












protected:
GameOver() {}
};

#endif // GAMEOVER_H
