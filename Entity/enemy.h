#ifndef ENEMY_H
#define ENEMY_H
#include "Entity/entity.h"
#include "Sprite/enemysprite.h"

class Enemy: public Entity
{
public:    
    Enemy(SDL_setup *gameSetup, std::string passedName, std::string path);
    ~Enemy();

    virtual void setOrigin(int X, int Y);
    virtual bool GetMoving();
    virtual void setIsMoving(bool value);


    virtual int getMaxHealth() const;
    virtual void setMaxHealth(int value);

    virtual int getAbilityPower() const;
    virtual void setAbilityPower(int value);

    virtual int getMaxAP();
    virtual void setMaxAP(int value );

    virtual int getAttackDamage() const;
    virtual void setAttackDamage(int value);
    virtual std::string toString(int number);
    void setSprite(EnemySprite * value);
    EnemySprite * getSprite();
    virtual MenuSprite * getIcon();
    virtual std::string getName() const;
    virtual void setName(const std::string &value);
    virtual std::string getBattleStats();

    virtual int getCurrentHealth() const;
    virtual void setCurrentHealth(int value);
    virtual void attack(Entity * player);
    virtual void useAbility(ISkill * skill,Entity* player);
    void isSelected(SDL_setup * setup, ISprite *sprite);

    virtual bool getCanAttack() const;
    virtual void setCanAttack(bool value);

    bool getSelected() const;
    void setSelected(bool value);

    bool getMouseOver() const;
    void setMouseOver(bool value);
    virtual Level *getEntityLevel();

    virtual int getExperience();
    virtual void setExperience(int value);

    virtual Item *getWeapon() const;
    virtual void setWeapon(Item *value);

    virtual std::map<std::string, int>* getSkillMap() ;
    virtual void setSkillMap(const std::map<std::string, int> &value);
     virtual SkillList *getSkillList() const;

private:
    EnemySprite * enemySprite;


    bool selected;











    // Entity interface
public:

    virtual void useItem(Item *item);

    // Entity interface
public:
    virtual void levelUP();

    // Entity interface
public:
    virtual void setLevel(int aLevel);

    // Entity interface
public:
    virtual void useItem(Entity *player, Item *item);

    // Entity interface
public:
    virtual bool useItem(Entity *player, std::string item);

    // Entity interface
public:

    virtual Inventory *getInventory() const;
    virtual void setInventory(Inventory *value);

    // Entity interface
public:
    virtual Item::TYPE getResistance() const;
    virtual void setResistance();
};

#endif // ENEMY_H
