#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHeaderView>

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

class QCheckBox;

class clyyHeaderView : public QHeaderView
{
    Q_OBJECT

public:
    explicit clyyHeaderView(Qt::Orientation orientation, QWidget *parent = 0);
    ~clyyHeaderView();

protected:
    QCheckBox *m_pCheckBox;
    void paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const;
};

#endif // MAINWINDOW_H
