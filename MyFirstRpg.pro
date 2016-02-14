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
LIBS += -L"C:/MinGW/lib" -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

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
    State/battlestate.cpp \
    State/fieldstate.cpp \
    State/IntroState.cpp \
    RenderItems/gamerenderer.cpp \
    Visitor/drawvisitor.cpp \
    Sprite/backgroundsprite.cpp \
    Sprite/csprite.cpp \
    Sprite/movingsprite.cpp \
    Sprite/enemysprite.cpp \
    Entity/enemy.cpp \
    Sprite/menusprite.cpp

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
    State/battlestate.h \
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
    Sprite/menusprite.h




FORMS    +=
