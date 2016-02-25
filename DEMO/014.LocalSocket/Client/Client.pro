#-------------------------------------------------
#
# Project created by QtCreator 2016-02-25T13:28:23
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(../defaults.pri)

TARGET = Client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
