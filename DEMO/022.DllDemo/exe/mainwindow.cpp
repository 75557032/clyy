#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLibrary>
#include <QMessageBox>
#include <QString>
#include <windows.h>
#include <QTypeInfo>
#include <QMetaObject>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ss=new QLibrary("dll.dll");
    if (!ss->load())
    {
       QMessageBox::information(NULL, "Title", "1");
     }
    add=(clyy)(ss->resolve("addclyy"));
    clyynew=(newclyy)(ss->resolve("newclyy"));
    if (!add)
    {
        QMessageBox::information(NULL, "Title", "2");
    }
    if (!clyynew)
    {
        QMessageBox::information(NULL, "Title", "2");
    }
    //MessageBox(NULL,QString("a我靠").toStdWString().c_str(),QString("哈a。哈").toStdWString().c_str(),0);
}

MainWindow::~MainWindow()
{
    delete ss;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString s=QString::number(add(),10);
    QMessageBox::information(NULL, "Title", s);
    const QMetaObject *xx=clyynew();
    QObject *bb=xx->newInstance();
    QMessageBox::information(NULL, "Title", bb->staticMetaObject.className());
}
