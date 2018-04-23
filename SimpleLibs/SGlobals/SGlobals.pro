#-------------------------------------------------
#
# Project created by QtCreator 2018-04-12T01:36:31
#
#-------------------------------------------------

QT       -= gui

TARGET = SGlobals
TEMPLATE = lib

DEFINES += SGLOBALS_LIBRARY

SOURCES += sglobals.cpp

HEADERS += sglobals.h\
        sglobals_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
