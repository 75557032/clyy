#include <QDebug>
#include <QPainter>
#include <QCheckBox>
#include "clyymodel.h"
#include "clyydelegate.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pModel(new clyyModel(this)),
    m_pDelegate(new clyyDelegate(this))
{
    ui->setupUi(this);
    clyyHeaderView *xx = new clyyHeaderView(Qt::Horizontal, ui->tableView);
    ui->tableView->setHorizontalHeader(xx);
    ui->tableView->setModel(m_pModel);
    ui->tableView->setItemDelegate(m_pDelegate);
}

MainWindow::~MainWindow()
{
    delete ui;
}

clyyHeaderView::clyyHeaderView(Qt::Orientation orientation, QWidget *parent) :
    QHeaderView(orientation, parent)
{
    m_pCheckBox = new QCheckBox(this);
    m_pCheckBox->setFixedSize(qRound(1.3 * m_pCheckBox->sizeHint().height()),
     m_pCheckBox->sizeHint().height());
    m_pCheckBox->setFocusPolicy(Qt::NoFocus);
}

clyyHeaderView::~clyyHeaderView()
{

}

void clyyHeaderView::paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const
{
     QPoint pot = rect.center();
     pot.setX(pot.x() - m_pCheckBox->width() / 2 );
     pot.setY(pot.y() - m_pCheckBox->height() / 2 );
     QRect rect_(pot, rect.size());
     m_pCheckBox->setGeometry(rect_);
    QHeaderView::paintSection(painter, rect, logicalIndex);
}
