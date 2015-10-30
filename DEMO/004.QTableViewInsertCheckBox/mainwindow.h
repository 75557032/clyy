#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class clyyModel;
class clyyDelegate;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    clyyModel *m_pModel;
    clyyDelegate *m_pDelegate;

};

#endif // MAINWINDOW_H
