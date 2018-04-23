#-------------------------------------------------
#
# Project created by QtCreator 2018-04-11T00:07:05
#
#-------------------------------------------------

QT       -= gui

TARGET = SLanguageManager
TEMPLATE = lib

DEFINES += SLANGUAGEMANAGER_LIBRARY

SOURCES += slanguagemanager.cpp

HEADERS += slanguagemanager.h\
        slanguagemanager_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
