#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QScriptEngine;
class clyy;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void test();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QScriptEngine *scriptEngine;
    clyy *pclyy;
};

class clyy : public QObject
{
    Q_OBJECT

public:
    clyy();
    ~clyy();
    Q_INVOKABLE void test();
    Q_INVOKABLE int add(QString a, int b);
};

#endif // MAINWINDOW_H
