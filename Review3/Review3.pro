QT += core
QT -= gui

CONFIG += c++11

TARGET = Review3
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    absrow.h \
    abstable.h \
    addtable.h \
    rowarray.h \
    table.h \
    simplevector.h
