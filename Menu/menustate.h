#ifndef MENUSTATE_H
#define MENUSTATE_H
#include "GameSetup/sdl_setup.h"
#include "Sprite/backgroundsprite.h"
#include "State/gamestate.h"
#include "RenderItems/button.h"
#include "State/fieldstate.h"
#include "RenderItems/fontbutton.h"
#include "Visitor/drawvisitor.h"
#include "State/victorystate.h"


class MenuState : public GameState
{
public:

    virtual void Init(GameEngine* game);
    virtual void Update(GameEngine* game);
    virtual void Draw(GameEngine* game);
    virtual void HandleEvents(GameEngine* game);
    virtual void Cleanup();

    virtual void Pause();
    virtual void Resume(GameEngine *game);
    static MenuState * Instance() {
        return &menu;
    }
protected:
      MenuState(){}

private:
      enum MenuStates
      {
          STATE_INTRO,
          STATE_ITEM,
          STATE_EQUIP,
          STATE_SKILLS
      };
      static MenuState  menu;
      MenuSprite * back;
      MenuSprite * options;
      MenuSprite * selected;
      std::vector<FontButton*> buttons;
      DisplayField * line1;
      FontButton * Item;
      FontButton * Equip;
      FontButton * Skills;
      int offset = 20;
      int state;
      //Add teh states stuff in main character so i can select a character

};

#endif // MENUSTATE_H
