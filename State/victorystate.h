#ifndef VICTORYSTATE_H
#define VICTORYSTATE_H
#include "GameSetup/sdl_setup.h"
#include "Sprite/backgroundsprite.h"
#include "State/gamestate.h"
#include "RenderItems/button.h"
#include "State/fieldstate.h"
#include "RenderItems/fontbutton.h"
#include "Visitor/drawvisitor.h"

class VictoryState : public GameState
{
public:
    virtual void Init(GameEngine* game);
    virtual void Update(GameEngine* game);
    virtual void Draw(GameEngine* game);
    virtual void HandleEvents(GameEngine* game);
    virtual void Cleanup();

    virtual void Pause();
    virtual void Resume(GameEngine *game);
    void screenClick(GameEngine *game);
    static VictoryState * Instance()
    {
        return &victory;
    }


    bool getSelected() const;
    void setSelected(bool value);

    int getRewardXP() const;
    void setRewardXP(int value);

    bool getClicked() const;
    void setClicked(bool value);

protected:
    VictoryState() {}
private:
    static VictoryState  victory;
    MenuSprite * textRow;
    MenuSprite * expRow;
    MenuSprite * goldRow;
    MenuSprite * player1Row;
    MenuSprite * player2Row;
    MenuSprite * player3Row;
    std::vector<MenuSprite*> rows;
    DisplayField * line1;  
    int rewardXP =  0;
    int counter;
    int levelcheck;
    int scrPos = 30;
    bool clicked;
};

#endif // VICTORYSTATE_H
