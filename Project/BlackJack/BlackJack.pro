QT += core
QT -= gui

CONFIG += c++11

TARGET = BlackJack
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Dealer.cpp \
    Player.cpp \
    Deck.cpp \
    BlackJack.cpp

HEADERS += \
    Dealer.h \
    Player.h \
    Deck.h \
    BlackJack.h

