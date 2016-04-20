QT += core
QT -= gui

CONFIG += c++11

TARGET = Q5
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    SortAnalyzer.cpp

HEADERS += \
    SortAnalyzer.h
