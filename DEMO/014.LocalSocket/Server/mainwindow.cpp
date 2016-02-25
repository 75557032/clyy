#include <QLocalServer>
#include <QLocalSocket>
#include <clyyconst.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pLocalServer(new QLocalServer)
{
    ui->setupUi(this);
    connect(m_pLocalServer, &QLocalServer::newConnection, this, &MainWindow::newConnection);
    m_pLocalServer->listen(SERVERNAME);
}

MainWindow::~MainWindow()
{
    delete m_pLocalServer;
    delete ui;
}

void MainWindow::newConnection()
{
    QLocalSocket *pLocalSocket = m_pLocalServer->nextPendingConnection();
    connect(pLocalSocket, &QLocalSocket::readyRead, this, &MainWindow::readyRead);
}

void MainWindow::readyRead()
{
    QLocalSocket *pLocalSocket = static_cast<QLocalSocket *>(sender());
    QByteArray buf = pLocalSocket->readAll();
    ui->textEdit->append(buf.toHex());
    unsigned char buf1[] = {0xAA, 0x55, 0x01};
    pLocalSocket->write(reinterpret_cast<char *>(buf1), 3);
    pLocalSocket->waitForBytesWritten();
}
