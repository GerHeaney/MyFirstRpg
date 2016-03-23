#-------------------------------------------------
#
# Project created by QtCreator 2016-01-15T16:10:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyFirstRpg
TEMPLATE = app
CONFIG += console
LIBS += -L"C:/MinGW/lib" -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

INCLUDEPATH += C:/MinGW/include/SDL2

SOURCES += main.cpp \
    Entity/maincharacter.cpp \
    GameSetup/gameengine.cpp \
    GameSetup/sdl_setup.cpp \
    Input/keyboardmovement.cpp \
    Input/mousemovement.cpp \
    RenderItems/button.cpp \
    RenderItems/camera.cpp \  
    RenderItems/environment.cpp \
    RenderItems/fontbutton.cpp \
    RenderItems/tree.cpp \
    State/fieldstate.cpp \
    State/IntroState.cpp \
    RenderItems/gamerenderer.cpp \
    Visitor/drawvisitor.cpp \
    Sprite/backgroundsprite.cpp \
    Sprite/csprite.cpp \
    Sprite/movingsprite.cpp \
    Sprite/enemysprite.cpp \
    Entity/enemy.cpp \
    Sprite/menusprite.cpp \
    RenderItems/displayfield.cpp \
    Battle/battlestate.cpp \
    Battle/battlesystem.cpp \
    Battle/attack.cpp \
    Entity/level.cpp \
    State/victorystate.cpp \
    Menu/menustate.cpp \
    Item/weapon.cpp \
    Item/potion.cpp \
    Item/inventory.cpp \
    Skills/swordskill.cpp \
    Skills/axeskill.cpp \
    Skills/spearskill.cpp \
    Skills/maceskill.cpp \
    Skills/skilllist.cpp \
    Item/ether.cpp \
    State/gameover.cpp

HEADERS  += \
    Entity/entity.h \
    Entity/maincharacter.h \
    GameSetup/sdl_setup.h \
    Input/keyboardmovement.h \
    Input/mousemovement.h \
    RenderItems/button.h \
    RenderItems/camera.h \  
    RenderItems/environment.h \
    RenderItems/fontbutton.h \
    RenderItems/tree.h \  
    State/fieldstate.h \
    State/gamestate.h \
    State/IntroState.h \
    GameSetup/gameengine.h \
    RenderItems/gamerenderer.h \
    Visitor/ivisitor.h \
    Visitor/drawvisitor.h \
    Sprite/backgroundsprite.h \
    Sprite/isprite.h \
    Sprite/csprite.h \
    Sprite/movingsprite.h \
    Sprite/enemysprite.h \
    Entity/enemy.h \
    Sprite/menusprite.h \
    RenderItems/displayfield.h \
    Battle/battlestate.h \
    Battle/battlesystem.h \
    Battle/attack.h \
    Entity/level.h \
    State/victorystate.h \
    Menu/menustate.h \
    Item/item.h \
    Item/weapon.h \
    Item/potion.h \
    Item/inventory.h \
    Skills/iskill.h \
    Skills/swordskill.h \
    Skills/axeskill.h \
    Skills/spearskill.h \
    Skills/maceskill.h \
    Skills/skilllist.h \
    Item/ether.h \
    State/gameover.h




FORMS    +=
