#include "clyyyuan.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QtGlobal>
#include <QDebug>
#include <QBrush>
#include <QColor>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QMovie>
#include <QPen>
#include <QFont>
#include <math.h>


void Initialize()
{
    qDebug() <<"Initialize";
}

void Cleanup()
{
    qDebug() <<"Cleanup";
}

clyyWangYuan::clyyWangYuan(qreal x, qreal y, qreal w, qreal h, QGraphicsRectItem *parent):QObject(),QGraphicsRectItem(x,y,w,h,parent)
{
    this->setFlags(QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsMovable);
    clyytext=new QGraphicsTextItem(this);
    clyytext->setTextWidth(this->boundingRect().width());
    clyytext->setHtml("<div align=\"center\">sa</div>");
    clyytext->setPos(0,(h-clyytext->boundingRect().height())/2);
    this->setBrush(QBrush(QColor(0, 0, 255, 127)));
    clyybmp=new QGraphicsPixmapItem(this);
    animatedBg = new QMovie("C:\\xxx.gif");
    connect(animatedBg, &QMovie::updated, this, &clyyWangYuan::bgUpdated);
    animatedBg->start();
    //this->setRect(clyybmp->boundingRect());
}

clyyWangYuan::~clyyWangYuan()
{

}

void clyyWangYuan::bgUpdated()
{
    QPixmap pixmap(animatedBg->currentPixmap().scaled(this->boundingRect().width(),
                                                      this->boundingRect().height(),
                                                      Qt::IgnoreAspectRatio,
                                                      Qt::SmoothTransformation));
    clyybmp->setPixmap(pixmap);
}

clyyZiWang::clyyZiWang(qreal x, qreal y, qreal w, qreal h, QGraphicsEllipseItem *parent):QGraphicsEllipseItem(x,y,w,h,parent)
{
    this->setFlags(QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsMovable);
}

clyyZiWang::~clyyZiWang()
{

}

clyyLianLu::clyyLianLu(qreal x, qreal y, qreal w, qreal h, QGraphicsLineItem *parent):QGraphicsLineItem(x,y,w,h,parent)
{
    this->setFlags(QGraphicsItem::ItemIsSelectable);
    this->setPen(QPen(QColor(0, 0, 255, 127)));
    QGraphicsTextItem * clyytext=new QGraphicsTextItem(this);
    clyytext->setTextWidth(this->boundingRect().width());
    clyytext->setHtml("<div align=\"center\">sa</div>");
    QFont xx;
    xx.setPointSize(20);
    clyytext->setFont(xx);
    double linew=sqrt(w*w+h*h);
    qreal temp=((linew-clyytext->textWidth())/2)/linew;
    qreal temp1=clyytext->boundingRect().height()/2;
    clyytext->setPos(w*temp+temp1,h*temp);
    clyytext->setRotation(calcAngle(w,h,0,0)+90);
}

clyyLianLu::~clyyLianLu()
{

}


qreal calcAngle(qreal sx, qreal sy, qreal dx, qreal dy)
{
  qreal x, y, k1, k2;
  x = dx - sx;
  y = dy - sy;
  if ( (x == 0) && (y == 0) )
  {
     return 0;
  }
  if (x == 0)
  {
     if ( y < 0) return 0;////在Ｘ轴上时两种结果
     if ( y > 0) return 180;
  }
  if ( y == 0)
  {
     if ( x > 0 ) return 90;//在Ｙ轴上时两种结果
     if ( x < 0) return 270;
  }
  k1 = 0; //因为直线(L1)在Ｙ轴上，所以方程为：y=0x+0;即Y=0;斜率为0
  k2 = y / x; //直线(L2)的斜率为 y/x，前面已经去除了x=0或y=0的情况
  qreal  result = round(atan(fabs(k1 - k2)) * 180 / M_PI);
  //由于K1=0，所以 a := abs(k1 - k2) / abs(1 + k1 * k2);
  if ( (x > 0) && (y < 0) )
  {
     result = 90 - result;
  }
  else if ( (x > 0) && (y > 0) )
  {
     result = 90 + result;
  }
  else if ( (x < 0) && (y > 0) )
  {
     result = 270 - result;
  }
  else if ( (x < 0) && (y < 0) )
  {
     result = 270 + result;
  }
  return result;
}
