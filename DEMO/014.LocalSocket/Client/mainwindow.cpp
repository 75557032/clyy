#include <QLocalSocket>
#include <clyyconst.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pLocalSocket(new QLocalSocket)
{
    ui->setupUi(this);
    m_pLocalSocket->connectToServer(SERVERNAME);
    if (!m_pLocalSocket->waitForConnected()) {
        qDebug() << "连接服务端失败";
    }
    connect(m_pLocalSocket, &QLocalSocket::readyRead, this, &MainWindow::readyRead);
}

MainWindow::~MainWindow()
{
    delete m_pLocalSocket;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    char data[] = {0x01, 0x02, 0x03, 0x04};
    m_pLocalSocket->write(data, 4);
    m_pLocalSocket->waitForBytesWritten();
}

void MainWindow::readyRead()
{
    QLocalSocket *pLocalSocket = static_cast<QLocalSocket *>(sender());
    QByteArray buf = pLocalSocket->readAll();
    ui->textEdit->append(buf.toHex());
}
