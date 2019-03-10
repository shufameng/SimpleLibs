#-------------------------------------------------
#
# Project created by QtCreator 2018-04-10T23:40:20
#
#-------------------------------------------------

QT       += widgets

TARGET = SDialog
TEMPLATE = lib

DEFINES += SDIALOG_LIBRARY

SOURCES += sdialog.cpp

FORMS    += sdialog.ui

HEADERS += sdialog.h\
        sdialog_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

RESOURCES += \
    qss.qrc
