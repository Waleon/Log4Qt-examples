QT += core gui

TEMPLATE = app
CONFIG += console

include($$PWD/../Logger.pri)

SOURCES += main.cpp

DISTFILES += log4qt.properties \
             $$PWD/../QtSrc.log
