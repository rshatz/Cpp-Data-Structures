QT += core
QT -= gui

CONFIG += c++11

TARGET = Q6
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Analyzer.cpp

HEADERS += \
    Analyzer.h \
    OptimizedVector.h \
    SimpleVector.h \
    ListVector.h
