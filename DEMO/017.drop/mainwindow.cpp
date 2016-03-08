#include <QMimeData>
#include <QDrag>
#include <QDebug>
#include <QPainter>
#include <QPixmap>
#include <QColor>
#include <QDragEnterEvent>
#include <QDropEvent>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->installEventFilter(this);
    this->setAcceptDrops(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *o, QEvent *e)
{
    bool ret= QMainWindow::eventFilter(o, e);
    if (o != ui->pushButton) {
        return ret;
    }
    if (e->type() == QEvent::MouseButtonPress) {
        QDrag *drag = new QDrag(o);
        QMimeData *mimeData = new QMimeData;
        mimeData->setText("xxxx");
        drag->setMimeData(mimeData);
        //QPixmap drag_img = QPixmap::grabWidget(ui->pushButton);//这句可以直接复制按钮的显示为图片
        QPixmap drag_img(120, 18);
        drag_img.fill(Qt::transparent);
        QPainter painter(&drag_img);
        painter.drawText(QRectF(0, 0, 120,18), "sasas");
        drag->setPixmap(drag_img);
        Qt::DropAction resultAction = drag->exec(Qt::MoveAction);
        if (resultAction == Qt::MoveAction) {
            //如果dropEvent不进行确认，不会走到这个地方
            qDebug() << "确认处理及后续处理方法";
            qDebug() << drag->source()->objectName();
            qDebug() << drag->target()->objectName();
            ui->pushButton->move(mapFromGlobal(cursor().pos()));
        }
    }
    return ret;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *e)
{
    //拖动的控件移动到本区域
    QMainWindow::dragEnterEvent(e);
    qDebug() << "dragEnterEvent";
    e->acceptProposedAction();//确认this处理，如不确认，不会产生后续的事件
}

void MainWindow::dragMoveEvent(QDragMoveEvent *e)
{
    //在内部移动的事件，如果dragEnter中没有确认，此事件不会产生
    QMainWindow::dragMoveEvent(e);
    //qDebug() << "dragMoveEvent";//太多了，影响视觉
}

void MainWindow::dragLeaveEvent(QDragLeaveEvent *e)
{
    //在内部移动的事件，如果dragEnter中没有确认，此事件不会产生
    QMainWindow::dragLeaveEvent(e);
    qDebug() << "dragLeaveEvent";
}

void MainWindow::dropEvent(QDropEvent *e)
{
    //落地事件，如果dragEnter中没有确认，此事件不会产生
    QMainWindow::dropEvent(e);
    qDebug() << "dropEvent";
    e->acceptProposedAction();//确认落地，如不确认，拖动控件不会处理
}
