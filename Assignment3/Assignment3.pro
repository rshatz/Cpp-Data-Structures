QT += core
QT -= gui

CONFIG += c++11

TARGET = Assignment3
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    vector.cpp

HEADERS += \
    node.h \
    vector.h
