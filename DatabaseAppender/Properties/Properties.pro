QT += core gui sql

TEMPLATE = app
CONFIG += console

include($$PWD/../Logger.pri)

SOURCES += main.cpp

DISTFILES += log4qt.properties
