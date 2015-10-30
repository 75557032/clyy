#-------------------------------------------------
#
# Project created by QtCreator 2015-10-29T09:03:22
#QTableView嵌入CheckBox的DEMO
#第一列：flags
#第二列：delegate::print
#第三列：进度条
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTableViewInsertCheckBox
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    clyymodel.cpp \
    clyydelegate.cpp

HEADERS  += mainwindow.h \
    clyymodel.h \
    clyydelegate.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11
