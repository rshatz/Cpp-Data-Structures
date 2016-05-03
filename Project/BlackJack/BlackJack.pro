QT += core
QT -= gui

CONFIG += c++11

TARGET = BlackJack
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    House.cpp

HEADERS += \
    House.h
