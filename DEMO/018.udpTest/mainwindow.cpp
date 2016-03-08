#include <QUdpSocket>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pUdp(new QUdpSocket)
{
    ui->setupUi(this);
    m_pUdp->bind(3800);
    connect(m_pUdp, &QUdpSocket::readyRead, this, &MainWindow::readyRead);
}

MainWindow::~MainWindow()
{
    delete m_pUdp;
    delete ui;
}

void MainWindow::readyRead()
{
    while (m_pUdp->hasPendingDatagrams()) {
        QByteArray aa;
        aa.resize(m_pUdp->pendingDatagramSize());
        m_pUdp->readDatagram(aa.data(), aa.size());
        qDebug() << QString::fromUtf8(aa);
    }
}

void MainWindow::on_pushButton_clicked()
{
    QByteArray aa = ui->lineEdit->text().toUtf8();
    m_pUdp->writeDatagram(aa, QHostAddress("192.168.1.255"), 3800);
}
