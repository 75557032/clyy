#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLibrary>

typedef int (*clyy)();
typedef const QMetaObject* (*newclyy)();

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QLibrary *ss;
    clyy add;
    newclyy clyynew;
};

#endif // MAINWINDOW_H
