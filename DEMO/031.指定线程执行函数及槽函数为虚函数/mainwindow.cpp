#include <QDebug>
#include <QEvent>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "test.h"

//template <typename F>
//class clyyEvent : public QEvent
//{
//private:
//    F fun;

//public:
//    clyyEvent(F && fun) : QEvent(QEvent::None), fun(std::move(fun))
//    {
//        qDebug() << "clyyEvent";
//    }
//    ~clyyEvent()
//    {
//        qDebug() << "~clyyEvent";
//        fun();
//    }
//};

//template <typename F>
//static void postToThread(F && fun, QObject * obj = qApp) {
//    qDebug() << "postToThread";
//    qApp->postEvent(obj, new clyyEvent<F>(std::move(fun)));
//}

#include <functional>

using namespace std;

template <typename F>
static void postToThread(F && fun, QObject *obj = qApp)
{
    qDebug() << "postToThread";
    QObject src;
    QObject::connect(&src, &QObject::destroyed, obj, std::move(fun), Qt::BlockingQueuedConnection);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pThread(new QThread),
    m_pObject(new clyyTestObject)
{
    ui->setupUi(this);
    m_pObject->moveToThread(m_pThread);
    m_pThread->start();
    emit m_pObject->initSig();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    clyyTest xx;
    xx.test();



    qDebug() << "on_pushButton_clicked:" << QThread::currentThread();
    int a = 10;
    if (QThread::currentThread() != m_pObject->thread()) {
        postToThread([&]
        {
            a = m_pObject->testSendTo(a);
        }, m_pObject);
    } else {
        a = m_pObject->testSendTo(a);
    }
    qDebug() << a;
    qDebug() << "on_pushButton_clicked";
}

clyyTestObject::clyyTestObject()
{
    connect(this, &clyyTestObject::initSig, this, &clyyTestObject::init);
    connect(this, &clyyTestObject::test, this, &clyyTestObject::testVir);
    test();
}

clyyTestObject::~clyyTestObject()
{

}

int clyyTestObject::testSendTo(int a)
{
    qDebug() << "testSendTo" << a;
    m_pSocket->writeDatagram("xxx", QHostAddress("127.0.0.1"), 2000);
    return a + 10;
}

void clyyTestObject::testVir()
{
    qDebug() << "clyyTestObject::testVir()";
}

void clyyTestObject::init()
{
    m_pSocket = new QUdpSocket;
}

void clyyTest::testVir()
{
    qDebug() << "clyyTest::testVir()";
}
