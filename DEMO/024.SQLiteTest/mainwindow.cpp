#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sqlite3.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlDriver>

bool sqliteDBMemFile( QSqlDatabase& memdb, QString filename, bool save )
{
    bool state = false;
    QVariant v = memdb.driver()->handle();
    sqlite3 * handle = *static_cast<sqlite3 **>(v.data());
    if( handle != 0 ) // check that it is not NULL
    {
        sqlite3 * pInMemory = handle;
        std::string str=filename.toStdString();
        const char * zFilename = str.c_str();
        int rc; /* Function return code */
        sqlite3 *pFile; /* Database connection opened on zFilename */
        sqlite3_backup *pBackup; /* Backup object used to copy data */
        sqlite3 *pTo; /* Database to copy to (pFile or pInMemory) */
        sqlite3 *pFrom; /* Database to copy from (pFile or pInMemory) */

        rc = sqlite3_open( zFilename, &pFile );
        if( rc==SQLITE_OK ){
            pFrom = ( save ? pInMemory : pFile);
            pTo = ( save ? pFile : pInMemory);

            pBackup = sqlite3_backup_init(pTo, "main", pFrom, "main");
            if( pBackup ){
                    (void)sqlite3_backup_step(pBackup, -1);
                    (void)sqlite3_backup_finish(pBackup);
            }
            rc = sqlite3_errcode(pTo);
        }

        (void)sqlite3_close(pFile);

        if( rc == SQLITE_OK ) state = true;

    }
    return state;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase dbconn=QSqlDatabase::addDatabase("QSQLITE");
    dbconn.setDatabaseName(":memory:");
    if(!dbconn.open())
    {
        qDebug()<<"fdsfds";
    }
    QSqlQuery query;
    query.exec("create table student(id varchar,name varchar)");
    query.exec(QObject::tr("insert into student values(1,'李刚')"));
    query.exec(QObject::tr("insert into student values(2,'苹果')"));
    query.exec(QObject::tr("insert into student values(3,'葡萄')"));
    query.exec(QObject::tr("insert into student values(3,'李子')"));
    query.exec(QObject::tr("insert into student values(4,’橘子')"));
    query.exec(QObject::tr("insert into student values(5,'核桃')"));
    query.exec(QObject::tr("insert into student values(6,'芒果')"));
    sqliteDBMemFile(dbconn,QString("c:\\sa.db"),true);
    query.exec("select * from student");
    while(query.next())//query.next()指向查找到的第一条记录，然后每次后移一条记录
    {
           int ele0=query.value(0).toInt();//query.value(0)是id的值，将其转换为int型
           QString ele1=query.value(1).toString();
           qDebug()<<ele0<<ele1;//输出两个值
  }
}

MainWindow::~MainWindow()
{
    delete ui;
}
