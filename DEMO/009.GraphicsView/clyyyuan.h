#ifndef CLYYYUAN_H
#define CLYYYUAN_H

#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QtGlobal>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QMovie>
#include <math.h>

extern qreal calcAngle( qreal sx, qreal sy, qreal dx, qreal dy);

class clyyWangYuan : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit clyyWangYuan(qreal x, qreal y, qreal w, qreal h, QGraphicsRectItem *parent=0);
    ~clyyWangYuan();
private:
    QGraphicsTextItem * clyytext;
    QGraphicsPixmapItem * clyybmp;
    QMovie *animatedBg;
public slots:
    void bgUpdated();
};

class clyyZiWang : public QGraphicsEllipseItem
{
public:
    explicit clyyZiWang(qreal x, qreal y, qreal w, qreal h, QGraphicsEllipseItem *parent=0);
    ~clyyZiWang();
};

class clyyLianLu : public QGraphicsLineItem
{
public:
    explicit clyyLianLu(qreal x, qreal y, qreal w, qreal h, QGraphicsLineItem *parent=0);
    ~clyyLianLu();
};
extern void Initialize();
extern void Cleanup();
__attribute__((constructor)) void Initialize();
__attribute__((destructor)) void Cleanup();
#endif // CLYYYUAN_H
