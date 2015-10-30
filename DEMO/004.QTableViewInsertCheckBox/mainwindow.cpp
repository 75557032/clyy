#include <QDebug>
#include "clyymodel.h"
#include "clyydelegate.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pModel(new clyyModel(this)),
    m_pDelegate(new clyyDelegate(this))
{
    ui->setupUi(this);
    ui->tableView->setModel(m_pModel);
    ui->tableView->setItemDelegate(m_pDelegate);
}

MainWindow::~MainWindow()
{
    delete ui;
}
