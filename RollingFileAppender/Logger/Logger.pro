QT += core gui

TEMPLATE = app
CONFIG += console

include($$PWD/../Logger.pri)

SOURCES += main.cpp

DISTFILES += $$PWD/../QtSrc.log
