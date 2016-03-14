#ifndef MENUSTATE_H
#define MENUSTATE_H
#include "GameSetup/sdl_setup.h"
#include "Sprite/backgroundsprite.h"
#include "State/gamestate.h"
#include "RenderItems/button.h"
#include "RenderItems/displayfield.h"
#include "RenderItems/fontbutton.h"
#include "Visitor/drawvisitor.h"



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
    bool getExit() const;
    void setExit(bool value);

protected:
    MenuState(){}

private:
    enum States
      {
          STATE_INTRO,
          STATE_ITEM,
          STATE_EQUIP,
          STATE_SKILLS
      };
      States switchState(States state);
      static MenuState  menu;
      MenuSprite * back;
      MenuSprite * options;
      MenuSprite * selected;
      std::vector<FontButton*> buttons;
      DisplayField * line1;
      FontButton * Item;
      FontButton * Equip;
      FontButton * Skills;
      FontButton * Weapon;
      FontButton * Axe;
      FontButton * Mace;
      FontButton * Spear;
      FontButton * Sword;
      int offset = 20;
      int state;
      Entity * selectedPlayer;
      bool exit;
      //Add teh states stuff in main character so i can select a character

};

#endif // MENUSTATE_H
