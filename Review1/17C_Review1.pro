QT += core
QT -= gui

CONFIG += c++11

TARGET = 17C_Review1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    rowarray.cpp \
    table.cpp

HEADERS += \
    rowarray.h \
    table.h
