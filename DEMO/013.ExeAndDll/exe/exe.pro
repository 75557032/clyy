#-------------------------------------------------
#
# Project created by QtCreator 2016-01-18T11:23:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = exe
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-dll-Desktop_Qt_5_5_1_MinGW_32bit-Debug/release/ -ldll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-dll-Desktop_Qt_5_5_1_MinGW_32bit-Debug/debug/ -ldll
else:unix: LIBS += -L$$PWD/../build-dll-Desktop_Qt_5_5_1_MinGW_32bit-Debug/ -ldll

INCLUDEPATH += $$PWD/../dll
DEPENDPATH += $$PWD/../dll
