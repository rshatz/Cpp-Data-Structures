QT += core
QT -= gui

CONFIG += c++11

TARGET = BlackJack
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Dealer.cpp \
    MainMenu.cpp \
    Player.cpp

HEADERS += \
    Dealer.h \
    MainMenu.h \
    Player.h
