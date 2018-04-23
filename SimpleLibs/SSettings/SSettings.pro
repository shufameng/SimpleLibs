#-------------------------------------------------
#
# Project created by QtCreator 2018-04-12T01:31:27
#
#-------------------------------------------------

QT       -= gui

TARGET = SSettings
TEMPLATE = lib

DEFINES += SSETTINGS_LIBRARY

SOURCES += ssettings.cpp

HEADERS += ssettings.h\
        ssettings_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
