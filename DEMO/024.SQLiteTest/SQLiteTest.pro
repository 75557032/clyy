#-------------------------------------------------
#
# Project created by QtCreator 2014-05-05T08:46:14
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SQLiteTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += D:/Qt/5.2.1/Src/qtbase/src/3rdparty/sqlite
SOURCES += D:/Qt/5.2.1/Src/qtbase/src/3rdparty/sqlite/sqlite3.c
