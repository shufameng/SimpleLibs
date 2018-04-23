#-------------------------------------------------
#
# Project created by QtCreator 2018-04-11T19:53:56
#
#-------------------------------------------------

QT       += widgets network

QT       -= gui

TARGET = SUpdater
TEMPLATE = lib

DEFINES += SUPDATER_LIBRARY

SOURCES += dlgsupdater.cpp \
    threadsupdater.cpp

HEADERS += dlgsupdater.h\
        supdater_global.h \
    threadsupdater.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SDialog/release/ -lSDialog
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SDialog/debug/ -lSDialog

INCLUDEPATH += $$PWD/../SDialog
DEPENDPATH += $$PWD/../SDialog

FORMS += \
    frmsupdater.ui
