#-------------------------------------------------
#
# Project created by QtCreator 2014-03-29T15:31:01
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtDemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tuopuform.cpp \
    clyyyuan.cpp \
    dbdialog.cpp

HEADERS  += mainwindow.h \
    tuopuform.h \
    clyyyuan.h \
    clyyevent.h \
    dbdialog.h

FORMS    += mainwindow.ui \
    tuopuform.ui \
    dbdialog.ui

#INCLUDEPATH += $$quote("D:/pgsql/include/")
#LIBS += -LD:/pgsql/lib -lpq
#DEFINES += HAVE_STRUCT_TIMESPEC
