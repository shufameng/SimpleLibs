#-------------------------------------------------
#
# Project created by QtCreator 2018-04-10T23:52:36
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test
TEMPLATE = app


SOURCES += main.cpp\
        testdialog.cpp \
    dialogdownloadfile.cpp

HEADERS  += testdialog.h \
    dialogdownloadfile.h

FORMS += \
    frametest.ui \
    dialogdownloadfile.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SDialog/release/ -lSDialog
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SDialog/debug/ -lSDialog

INCLUDEPATH += $$PWD/../SDialog
DEPENDPATH += $$PWD/../SDialog

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SLanguageManager/release/ -lSLanguageManager
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SLanguageManager/debug/ -lSLanguageManager

INCLUDEPATH += $$PWD/../SLanguageManager
DEPENDPATH += $$PWD/../SLanguageManager

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SLogger/release/ -lSLogger
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SLogger/debug/ -lSLogger

INCLUDEPATH += $$PWD/../SLogger
DEPENDPATH += $$PWD/../SLogger

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SHttp/release/ -lSHttp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SHttp/debug/ -lSHttp

INCLUDEPATH += $$PWD/../SHttp
DEPENDPATH += $$PWD/../SHttp
