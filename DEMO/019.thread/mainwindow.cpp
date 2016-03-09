#include <QThread>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

static clyyObject *g_clyyObject = NULL;
static QThread *g_thread = NULL;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    g_thread = new QThread;
    g_clyyObject = new clyyObject;
    g_clyyObject->moveToThread(g_thread);
    connect(this, &MainWindow::test, g_clyyObject, &clyyObject::test);
    g_thread->start();
    qDebug() << "main:" << QThread::currentThread();
    emit test("xxx");
    qDebug() << "main:end";
}

MainWindow::~MainWindow()
{
    g_thread->quit();;
    g_thread->wait(30000);
    delete g_thread;
    delete g_clyyObject;
    delete ui;
}

void clyyObject::test(const QString log)
{
    qDebug() << log;
    qDebug() << QThread::currentThread();
}
