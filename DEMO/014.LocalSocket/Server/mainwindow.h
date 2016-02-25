#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QLocalServer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void newConnection();
    void readyRead();

private:
    Ui::MainWindow *ui;
    QLocalServer *m_pLocalServer;
};

#endif // MAINWINDOW_H
