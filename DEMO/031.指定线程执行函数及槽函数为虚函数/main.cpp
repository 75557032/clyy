#include <QDebug>
#include "mainwindow.h"
#include <QApplication>
#include "test.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    int nRet = a.exec();
    return nRet;
}
