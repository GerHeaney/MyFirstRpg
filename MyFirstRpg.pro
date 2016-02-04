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
LIBS += -L"C:/MinGW/lib" -lSDL2main -lSDL2 -lSDL2_image

INCLUDEPATH += C:/MinGW/include/SDL2

SOURCES += main.cpp\
    mainclass.cpp \
    sdl_setup.cpp \
    csprite.cpp \
    keyboardmovement.cpp \
    mousemovement.cpp \
    maincharacter.cpp \
    environment.cpp \
    tree.cpp \
    button.cpp \
    IntroState.cpp \
    fieldstate.cpp \
    battlestate.cpp \
    entity.cpp \
    camera.cpp

HEADERS  += \
    mainclass.h \
    sdl_setup.h \
    csprite.h \
    keyboardmovement.h \
    mousemovement.h \
    maincharacter.h \
    environment.h \
    tree.h \
    button.h \
    gamestate.h \
    IntroState.h \
    fieldstate.h \
    battlestate.h \
    entity.h \
    camera.h

FORMS    +=
