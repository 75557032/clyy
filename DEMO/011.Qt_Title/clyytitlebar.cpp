#include <QMouseEvent>
#include "clyytitlebar.h"
#include "ui_clyytitlebar.h"

clyyTitleBar::clyyTitleBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clyyTitleBar)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->widget->installEventFilter(this);
    ui->pushButton->installEventFilter(this);
    ui->pushButton_2->installEventFilter(this);
}

clyyTitleBar::~clyyTitleBar()
{
    delete ui;
}

void clyyTitleBar::on_pushButton_clicked()
{
    close();
}

void clyyTitleBar::on_pushButton_2_clicked()
{
    this->setWindowState(Qt::WindowMinimized);
}

bool clyyTitleBar::eventFilter(QObject *o, QEvent *e)
{
    if ((o == ui->pushButton) || (o == ui->pushButton_2)) {
        if (e->type() == QEvent::MouseMove) {
            e->accept();
            return true;
        }
    }
    bool bResult = QWidget::eventFilter(o, e);
    if ((o == ui->widget) && (e->type() == QEvent::MouseButtonPress)) {
        QMouseEvent* evt = static_cast<QMouseEvent*>(e);
        lastPnt = evt->pos();
        return true;
    }
    if ((o == ui->widget) && (e->type() == QEvent::MouseMove)) {
        QMouseEvent* evt = static_cast<QMouseEvent*>(e);
        int dx = evt->pos().x() - lastPnt.x();
        int dy=evt->pos().y() - lastPnt.y();
        this->move(this->x()+dx, this->y()+dy);
        return true;
    }
    return bResult;
}
