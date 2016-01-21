#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVariant>

namespace Ui {
class MainWindow;
}

class clyy
{
public:
    clyy():a(0), b(0.0){}
    int a;
    double b;
    operator QVariant() const
    {
        return QVariant::fromValue(*this);
    }
};

Q_DECLARE_METATYPE(clyy)

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

signals:
    void clyyTest(clyy);

public slots:
    void clyyTestSlot(clyy test);
private slots:
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
