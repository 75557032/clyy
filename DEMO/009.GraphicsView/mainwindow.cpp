#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tuopuform.h"
#include <QGraphicsItem>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QStandardItemModel>
#include <QTreeView>
#include "dbdialog.h"

class a1
{
    virtual void func();
};

class b1:public virtual a1
{
    virtual void foo();
};

class a2
{
    virtual void func();
};

class b2:public a2
{
    virtual void foo();
};

class a3
{
    virtual void func();
    char a;
};

class b3:public virtual a3
{
    virtual void foo();
};

class a4
{
    virtual void func();
    char a;
};

class b4:public a4
{
    virtual void foo();
};

class clyybase
{
public:
   explicit clyybase( int n) {qDebug() <<"clyybase"<<n;}
};

typedef clyybase* saaa;

class clyythis :public clyybase
{
public:
    clyythis():clyybase(0){ qDebug() <<"clyythis";}
    saaa xx,ss;
};

QSqlDatabase * mydb;
DBDialog * myDBDialog;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),tv(new QTreeView),
#ifdef DUOCHONGJICHENG
    Ui::MainWindow()
#else
    ui(new Ui::MainWindow)
#endif
{
#ifdef DUOCHONGJICHENG
    setupUi(this);
#else
    ui->setupUi(this);
#endif
    this->setWindowState(Qt::WindowMaximized);
    clyytuopu=new tuopuform();
    connect(clyytuopu,&tuopuform::GraphicsItemDeleteChange,this,&MainWindow::DeleteGraphicsItem);
#ifdef DUOCHONGJICHENG
    gridLayout->addWidget(clyytuopu);
#else
    ui->gridLayout->addWidget(clyytuopu);
    ui->gridLayout_2->addWidget(tv);
#endif
    mydb=new QSqlDatabase(QSqlDatabase::addDatabase("QPSQL"));
    mydb->setHostName("127.0.0.1");
    mydb->setDatabaseName("postgres");
    mydb->setPort(5432);
    mydb->setUserName("postgres");
    mydb->setPassword("123456");
    if(!mydb->open())
    {
        qDebug() <<"数据库连接失败"<<mydb->lastError();
    }
    myDBDialog=new DBDialog(this);
    QStandardItemModel *ss=new QStandardItemModel(0,1);
    QStandardItem *sa=new QStandardItem;
    QStandardItem *aa=new QStandardItem;
    sa->setText("sa");
    aa->setText("a1");
    ss->appendRow(sa);
    sa->appendRow(aa);
    aa->setEditable(false);
    aa->setText("aa");
    tv->setModel(ss);
    tv->setHeaderHidden(true);
    tv->expandAll();
    qDebug() <<sizeof(a1)<<":"<<sizeof(b1);
    qDebug() <<sizeof(a2)<<":"<<sizeof(b2);
    qDebug() <<sizeof(a3)<<":"<<sizeof(b3);
    qDebug() <<sizeof(a4)<<":"<<sizeof(b4);
    clyythis xx;

    int num,count=10;
    num=count;
    count=num++;
    qDebug()<<count;
}

MainWindow::~MainWindow()
{
    delete myDBDialog;
    mydb->close();
    delete mydb;
    delete tv;
#ifndef DUOCHONGJICHENG
    delete ui;
#endif
}

int MainWindow::DeleteGraphicsItem(QGraphicsItem *item,int *a)
{
    qDebug() <<"cc"<< item;
    *a = 20;
    return 10;
}

void MainWindow::on_actionDB_triggered()
{
    myDBDialog->show();
}
