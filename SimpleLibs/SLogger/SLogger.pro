#-------------------------------------------------
#
# Project created by QtCreator 2018-04-11T00:33:21
#
#-------------------------------------------------

QT       -= gui

TARGET = SLogger
TEMPLATE = lib

DEFINES += SLOGGER_LIBRARY

SOURCES += slogger.cpp

HEADERS += slogger.h\
        slogger_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
