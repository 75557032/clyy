#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QUdpSocket>

namespace Ui {
class MainWindow;
}

class clyyTestObject : public QObject
{
    Q_OBJECT

public:
    clyyTestObject();
    ~clyyTestObject();
    int testSendTo(int a);
    virtual void testVir();

signals:
    void initSig();
    void test();

private:
    QUdpSocket *m_pSocket;

private slots:
    void init();
};

class clyyTest : public clyyTestObject
{
    Q_OBJECT

public:
    virtual void testVir();
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QThread *m_pThread;
    clyyTestObject *m_pObject;

private slots:
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
