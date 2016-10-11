#-------------------------------------------------
#
# Project created by QtCreator 2016-09-20T15:55:52
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    test.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11
