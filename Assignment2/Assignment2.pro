QT += core
QT -= gui

CONFIG += c++11

TARGET = Assignment2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Vector.cpp

HEADERS += \
    Vector.h \
    node.h
