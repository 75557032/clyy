#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QThread;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public: signals:
    void test(const QString xxx);

};

class clyyObject : public QObject
{
    Q_OBJECT

public slots:
    void test(const QString log);
};

#endif // MAINWINDOW_H
