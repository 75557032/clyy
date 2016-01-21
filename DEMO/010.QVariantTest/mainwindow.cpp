#include <QDebug>
#include <QVariant>
#include "mainwindow.h"
#include "ui_mainwindow.h"

static QVariant clyyVar;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this, &MainWindow::clyyTest, this, &MainWindow::clyyTestSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clyyTestSlot(clyy test)
{
    qDebug() << test.a;
    qDebug() << test.b;
    qDebug() << clyyVar.value<clyy>().a;
    qDebug() << clyyVar.value<clyy>().b;
}

void MainWindow::on_pushButton_clicked()
{
    clyy a;
    a.a = 100;
    a.b = 100.01;
    clyyVar = a;
    emit clyyTest(a);
}
