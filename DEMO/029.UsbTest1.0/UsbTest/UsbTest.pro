#-------------------------------------------------
#
# Project created by QtCreator 2016-05-05T10:19:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UsbTest
TEMPLATE = app

DESTDIR = $$PWD/../bin/

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += $$PWD/../LibUsb/include

LIBS += -L$$PWD/../LibUsb/MinGW32/dll/ -lusb-1.0.dll
