#include "form.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Form *pForm = new Form;
    ui->scrollArea->setWidget(pForm);
}

MainWindow::~MainWindow()
{
    delete ui;
}
