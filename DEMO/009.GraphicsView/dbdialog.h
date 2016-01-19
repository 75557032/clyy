#ifndef DBDIALOG_H
#define DBDIALOG_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class DBDialog;
}

class DBDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DBDialog(QWidget *parent = 0);
    ~DBDialog();
private slots:
    void on_pushButton_clicked();

private:
    Ui::DBDialog *ui;
    QSqlQueryModel *xx;
};

#endif // DBDIALOG_H
