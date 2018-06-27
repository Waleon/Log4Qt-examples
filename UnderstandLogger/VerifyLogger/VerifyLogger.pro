QT += core gui

TEMPLATE = app
CONFIG += console
DESTDIR = $$OUT_PWD/../bin

include($$PWD/../Logger.pri)

SOURCES += main.cpp
