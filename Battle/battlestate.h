#ifndef BATTLESTATE_H
#define BATTLESTATE_H

#include "GameSetup/sdl_setup.h"
#include "Sprite/enemysprite.h"
#include "Sprite/menusprite.h"
#include "State/gamestate.h"
#include "State/gameover.h"
#include "RenderItems/button.h"
#include "Entity/maincharacter.h"
#include "RenderItems/fontbutton.h"
#include "Visitor/drawvisitor.h"
#include "Entity/enemy.h"
#include "RenderItems/displayfield.h"
#include "Battle/battlesystem.h"
#include "Battle/enemylist.h"
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
    void Resume(GameEngine *game);

    void Draw();
    void chooseEnemy(GameEngine *game, Entity *player, Entity *enemy);
    void drawBattleMenu(GameEngine *game);
    bool PlayerTurn(GameEngine * game);
    bool EnemyTurn(GameEngine * game);
    void displayMessage(GameEngine * game);
    void checkSkills(GameEngine *game, Entity *player);
    static BattleState * Instance() {
        return &battle;
    }
    void drawSkillsMenu();
    void drawItemsMenu(GameEngine *game);
protected:
    BattleState() {}

private:
     MovingSprite* attackanim;
    DrawVisitor *visitor;
    std::vector<Entity*> enemies;
    BattleSystem * battleSystem;
    DisplayField * playerField;
    DisplayField * enemyField;
    DisplayField * battleInfo;
    MenuSprite * battleMenu;
    MenuSprite * infoBox;
    MenuSprite * selected;
    FontButton * Attack;
    FontButton * Ability;
    FontButton * Items;
    FontButton * Skill1;
    FontButton * Skill2;
    FontButton * Skill3;
    FontButton * Potions;
    FontButton * Ethers;
    static BattleState battle;
    SDL_Point pos1;
    SDL_Point pos2;
    SDL_Point pos3;
    SDL_Point pos4;
    std::vector<SDL_Point> positions;
    SDL_Rect menuRect;
    BackgroundSprite * background;

    Entity * pEnemy = NULL;
    MenuSprite * menu;
    Entity * player;
    SDL_Rect camera;
    bool turnFlag;
    int rewardXP;
    int buttonOffset = 35;

    void setEnemies(GameEngine *game);
};

#endif // BATTLESTATE_H
