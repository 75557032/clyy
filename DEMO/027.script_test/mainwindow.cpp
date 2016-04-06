#include <QDebug>
#include <QScriptEngine>
#include "mainwindow.h"
#include "ui_mainwindow.h"

static QScriptValue fun(QScriptContext *context, QScriptEngine *engine)
{
    qDebug() << context->argument(0).toString();
    qDebug() << context->argument(1).toString();
    qDebug() << engine->objectName();
    return 1;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scriptEngine(new QScriptEngine),
    pclyy(new clyy)
{
    ui->setupUi(this);
    scriptEngine->setObjectName("ccc");
    QScriptValue obj = scriptEngine->newQObject(pclyy);
    scriptEngine->globalObject().setProperty("clyy", obj);
    QScriptValue handler = scriptEngine->evaluate("(function() { print('clyy'); })");
    qScriptConnect(this, SIGNAL(test()), obj, handler);
    QScriptValue func = scriptEngine->newFunction(fun);
    scriptEngine->globalObject().setProperty("fun", func);
}

MainWindow::~MainWindow()
{
    delete pclyy;
    delete scriptEngine;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString script = ui->textEdit->document()->toPlainText();
    ui->textEdit_2->clear();
    ui->textEdit_2->append(scriptEngine->evaluate(script).toString());
}

clyy::clyy()
{
    qDebug() << "clyy";
}

clyy::~clyy()
{
    qDebug() << "~clyy";
}

void clyy::test()
{
    qDebug() << "test";
}

int clyy::add(QString a, int b)
{
    return a.toInt() + b;
}

void MainWindow::on_pushButton_2_clicked()
{
    emit test();
}
