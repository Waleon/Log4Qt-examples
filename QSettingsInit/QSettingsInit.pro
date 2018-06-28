QT += core gui

TEMPLATE = app

include($$PWD/Logger.pri)

HEADERS += my_application.h

SOURCES += main.cpp \
           my_application.cpp
