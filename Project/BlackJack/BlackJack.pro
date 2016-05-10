QT += core
QT -= gui

CONFIG += c++11

TARGET = BlackJack
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Player.cpp \
    Deck.cpp \
    BlackJack.cpp \
    ClearScreen.cpp

HEADERS += \
    Player.h \
    Deck.h \
    BlackJack.h \
    ClearScreen.h

