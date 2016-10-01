#-------------------------------------------------
#
# Project created by QtCreator 2016-09-30T11:23:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qwtDemo
TEMPLATE = app

DEFINES += QT_DLL QWT_DLL

SOURCES += main.cpp\
        mainwindow.cpp \
    clyyplot.cpp

HEADERS  += mainwindow.h \
    clyyplot.h

FORMS    += mainwindow.ui

INCLUDEPATH += "../qwt/inc/"

CONFIG(release, debug|release): {
    LIBS += -L"../qwt/lib/" -lqwt
}
CONFIG(debug, debug|release): {
    LIBS += -L"../qwt/lib/" -lqwtd
}
