#-------------------------------------------------
#
# Project created by QtCreator 2016-04-29T19:35:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UsbTest
TEMPLATE = app

DESTDIR = $$PWD/../bin


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += $$PWD/../libusb/include

LIBS += -L$$PWD/../libusb/lib/gcc -lusb
