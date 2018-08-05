QT += core gui

TEMPLATE = app
CONFIG += console

include($$PWD/../Logger.pri)

HEADERS += my_logger.h

SOURCES += main.cpp

DISTFILES += log4qt.properties
