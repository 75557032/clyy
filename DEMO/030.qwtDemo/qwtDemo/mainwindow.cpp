#include <QVBoxLayout>
#include "clyyplot.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

static double dAccuracy = 0.007;

static double plotDataFunc(double x, double y)
{
    //此处牵扯到一个精度的问题，不同的分辨率，x和y的数据节点是不同的
    //最好数据是一个范围，所以导出成一个函数指针
    //如果是经度，纬度，数据三列的话，只能加一个分辨率的常量来计算范围了
    int tempx = x / dAccuracy;
    int tempy = y / dAccuracy;
    return (tempx * dAccuracy + tempy * dAccuracy) * 3.33;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVBoxLayout *pMainLayout = new QVBoxLayout(ui->centralWidget);
    clyyPlot *pPlot = new clyyPlot(QString::fromLocal8Bit("热力图"));
    pMainLayout->addWidget(pPlot);
    pPlot->setBeginEndColor(Qt::darkCyan, Qt::red);
    pPlot->addColorStop(0.1, Qt::cyan);
    pPlot->addColorStop(0.6, Qt::green);
    pPlot->addColorStop(0.95, Qt::yellow);
    pPlot->setAxisMinMax(Qt::XAxis, -1.5, 1.5);
    pPlot->setAxisMinMax(Qt::YAxis, -1.5, 1.5);
    pPlot->setAxisMinMax(Qt::ZAxis, 0.0, 10.0);
    pPlot->setFunc(&plotDataFunc);
}

MainWindow::~MainWindow()
{
    delete ui;
}
