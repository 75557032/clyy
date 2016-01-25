#ifndef CLYYTITLEBAR_H
#define CLYYTITLEBAR_H

#include <QWidget>

namespace Ui {
class clyyTitleBar;
}

class clyyTitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit clyyTitleBar(QWidget *parent = 0);
    ~clyyTitleBar();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::clyyTitleBar *ui;
    QPoint lastPnt;

protected:
    bool eventFilter(QObject *o, QEvent *e);
};

#endif // CLYYTITLEBAR_H
