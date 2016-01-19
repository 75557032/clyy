#ifndef TUOPUFORM_H
#define TUOPUFORM_H

//#define CLYYMUBAN

#include "clyyyuan.h"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QtGlobal>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QGraphicsItem>
#include <QList>

namespace Ui {
class tuopuform;
}

class tuopuform;

typedef bool (tuopuform::*clyyevent)(QEvent *);

struct clyyeventrecord
{
    QObject *object;
    clyyevent eventpointer;
};

class tuopuform : public QMainWindow
{
    Q_OBJECT
public:
    explicit tuopuform(QWidget *parent = 0);
    ~tuopuform();
    clyyWangYuan* CreateWangYuan(qreal x, qreal y, qreal w, qreal h, QGraphicsRectItem *parent=0);
    clyyZiWang* CreateZiWang(qreal x, qreal y, qreal w, qreal h, QGraphicsEllipseItem *parent=0);
    clyyLianLu* CreateLianLu(qreal x, qreal y, qreal w, qreal h, QGraphicsLineItem *parent=0);
    void DeleteGraphicsItem(QGraphicsItem *item);

signals:
    int GraphicsItemDeleteChange(QGraphicsItem *,int *);

private slots:
    void on_actionAddWangYuan_triggered();

    void on_actionAddZiWang_triggered();

    void on_actionAddLianLu_triggered();

private:
    Ui::tuopuform *ui;
    QGraphicsScene *clyyScene;
    QList<clyyeventrecord> *clyylist;
    bool eventFilter(QObject *target, QEvent *event);
    bool clyyeventFilter(QObject *target, QEvent *event);
    void regevent(QObject *object,clyyevent eventpointer);
    clyyevent findevent(QObject *object);

    bool graphicsevent(QEvent *event);
#ifdef CLYYMUBAN
    template<typename T1,typename T2> T1 * CreateT(qreal x, qreal y, qreal w, qreal h, T2 *parent);
#endif
};

extern tuopuform *clyytuopu;

#pragma GCC diagnostic ignored "-Wpragmas"  //取消某告警
//#warning 这是一个测试告警 //输出一个告警
#pragma pack(1) //结构体对齐方式
struct clyyrecord
{
    int a;
    char b;
};//__attribute__((packed));//取消结构体对齐=#pragma pack(1)
#pragma pack()//回归结构体对齐方式,默认为4
#pragma GCC diagnostic warning "-Wpragmas"//激活某告警

#endif // TUOPUFORM_H
