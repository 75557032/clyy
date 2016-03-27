#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>

namespace Ui {
class MainWindow;
}

#include "ui_mainwindow.h"

class MainWindow : public QMainWindow,public Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void  processConnection();
    void  processText();
private:
//    Ui::MainWindow *ui;
    QTcpServer   *listenSocket;  // 侦听套接字
    QTcpSocket   *readWriteSocket;//读写套接字
};

#endif // MAINWINDOW_H
