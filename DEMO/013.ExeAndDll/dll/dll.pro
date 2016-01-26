#-------------------------------------------------
#
# Project created by QtCreator 2016-01-18T11:24:25
#
#-------------------------------------------------

QT       -= gui
QT       += network

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
