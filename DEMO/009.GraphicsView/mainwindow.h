#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#define DUOCHONGJICHENG

#include <QMainWindow>
#include <QGraphicsItem>
#include <QSqlDatabase>
#include <QTreeView>

#ifdef DUOCHONGJICHENG
#include "ui_mainwindow.h"
#endif

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
#ifdef DUOCHONGJICHENG
        ,public Ui::MainWindow
#endif
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int DeleteGraphicsItem(QGraphicsItem * item, int *a);
#ifndef DUOCHONGJICHENG
private slots:
    void on_actionDB_triggered();

private:
        Ui::MainWindow *ui;
        QTreeView * tv;
#endif
};
extern QSqlDatabase * mydb;
#endif // MAINWINDOW_H
