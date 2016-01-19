#include "dbdialog.h"
#include "ui_dbdialog.h"
#include "mainwindow.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include <QVariant>
#include <QDebug>
#include <QTableView>
#include <QSqlResult>
#include <QSqlDriver>

DBDialog::DBDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DBDialog)
{
    ui->setupUi(this);
    xx=new QSqlQueryModel(this);
    QSqlQuery *query=new QSqlQuery("select * from test",*mydb);
    QMessageBox::information(this,"w我k靠",query->record().fieldName(0),QMessageBox::Ok);
    xx->setQuery(*query);
    ui->tableView->setModel(xx);
    ui->tableView->setShowGrid(true);
}

DBDialog::~DBDialog()
{
    delete ui;
}

void DBDialog::on_pushButton_clicked()
{

}
