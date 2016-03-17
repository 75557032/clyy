#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVariant>
#include <QDebug>
#include <QWaitCondition>
#include <QMutex>
#include <QMutexLocker>

static QMutex clyy_mutex;
static QWaitCondition clyy_wait;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clyy_thread ss;
    ss.start();
    clyy_mutex.lock();
    if (clyy_wait.wait(&clyy_mutex, 10000)) {
        qDebug() << "true";
    } else {
        qDebug() << "flase";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void clyy_thread::run()
{
    qDebug() << "run";
    QMutexLocker lock(&clyy_mutex);
    qDebug() << "lock";
    msleep(2000);
    qDebug() << "unlock";
    clyy_wait.wakeAll();
}
