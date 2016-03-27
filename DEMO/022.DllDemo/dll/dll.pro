#-------------------------------------------------
#
# Project created by QtCreator 2014-03-13T17:21:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dll
TEMPLATE = lib

DEFINES += DLL_LIBRARY

SOURCES += dll.cpp

HEADERS += dll.h\
        dll_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
