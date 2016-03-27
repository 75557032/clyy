#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)//,
    //ui(new Ui::MainWindow)
{
//    ui->setupUi(this);
    this->setupUi(this);
    this->listenSocket =new QTcpServer;
    this->listenSocket->listen(QHostAddress::Any,6001);
    QObject::connect(this->listenSocket,&QTcpServer::newConnection,this,&MainWindow::processConnection);
}

MainWindow::~MainWindow()
{
//    delete ui;
}

void MainWindow::processConnection()
{
    this->readWriteSocket =this->listenSocket->nextPendingConnection();
    QObject::connect(this->readWriteSocket,SIGNAL(readyRead()),this,SLOT(processText()));
}

void MainWindow::processText()
{
    QString LTempStr=this->readWriteSocket->readAll();
    //ui->
            textBrowser->append(LTempStr);
}
