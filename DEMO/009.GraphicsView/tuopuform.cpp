#include "tuopuform.h"
#include "ui_tuopuform.h"
#include "clyyyuan.h"

#include <QGraphicsScene>
#include <QGraphicsScene>
#include <QtGlobal>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QGraphicsItem>
#include <QMenu>
#include <QWidget>
#include <QGraphicsView>
#include <QDebug>
#include <QMouseEvent>
#include <QList>
#include "clyyevent.h"

tuopuform *clyytuopu;

tuopuform::tuopuform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tuopuform)
{
    ui->setupUi(this);
    clyyScene=new QGraphicsScene(ui->graphicsView);
    clyylist=new QList<clyyeventrecord>;
    ui->graphicsView->setScene(clyyScene);
    ui->graphicsView->show();
    QBrush sa;
    sa.setTextureImage(QImage("C:\\xxx.gif"));
    clyyScene->setBackgroundBrush(sa);
    //clyyScene->sceneRect();
    //clyyScene->setBackgroundBrush();
    this->CreateWangYuan(0,0,200,500);
    this->CreateZiWang(0,0,200,500);
    this->CreateLianLu(0,0,200,500);
    ui->actionChangGui->setChecked(true);
    regevent(ui->graphicsView,(clyyevent)(&tuopuform::graphicsevent));
    ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
    qDebug() <<sizeof(clyyrecord);
//异常处理
    try
    {
        qDebug() <<"try";
        //throw 0;//抛出异常
    }
    catch(...)
    {
        qDebug() <<"catch";
        goto finally;
    }
    finally:
    {
        qDebug() <<"finally";
    }
//异常处理
}

tuopuform::~tuopuform()
{
/*    for(int i=0;i!=clyylist->count();++i)
    {
        clyyeventrecord* temp=(clyyeventrecord*)clyylist->at(i);
        delete temp;
    }*/
    delete clyylist;
    delete ui;
}

clyyWangYuan *tuopuform::CreateWangYuan(qreal x, qreal y, qreal w, qreal h, QGraphicsRectItem *parent)
{
#ifdef CLYYMUBAN
   return CreateT<clyyWangYuan>(x,y,w,h,parent);
#else
    clyyWangYuan *LTemp=new clyyWangYuan(x,y,w,h,parent);
    clyyScene->addItem(LTemp);
    return LTemp;
#endif
}

clyyZiWang *tuopuform::CreateZiWang(qreal x, qreal y, qreal w, qreal h, QGraphicsEllipseItem *parent)
{
#ifdef CLYYMUBAN
   return CreateT<clyyZiWang>(x,y,w,h,parent);
#else
    clyyZiWang *LTemp=new clyyZiWang(x,y,w,h,parent);
    clyyScene->addItem(LTemp);
    return LTemp;
#endif
}

clyyLianLu *tuopuform::CreateLianLu(qreal x, qreal y, qreal w, qreal h, QGraphicsLineItem *parent)
{
#ifdef CLYYMUBAN
   return CreateT<clyyLianLu>(x,y,w,h,parent);
#else
    clyyLianLu *LTemp=new clyyLianLu(x,y,w,h,parent);
    clyyScene->addItem(LTemp);
    return LTemp;
#endif
}

void tuopuform::DeleteGraphicsItem(QGraphicsItem * item)
{
    int i=0;
    emit GraphicsItemDeleteChange(item,&i);
    qDebug() <<i;
    delete item;
}

bool tuopuform::eventFilter(QObject *target, QEvent *event)
{
    bool LEve=QMainWindow::eventFilter(target,event);
    clyyevent temp=findevent(target);
    if(NULL!=temp)
    {
       (this->*temp)(event);
    }
    return LEve;
}

void tuopuform::regevent(QObject *object, clyyevent eventpointer)
{
    object->installEventFilter(this);
    clyyeventrecord temp;
    temp.object=object;
    temp.eventpointer=eventpointer;
    clyylist->append(temp);
}

clyyevent tuopuform::findevent(QObject *object)
{
    clyyevent temp(NULL);
    for(int i=0;i!=clyylist->count();++i)
    {
        if(((*clyylist)[i]).object==object)
        {
            temp=((*clyylist)[i]).eventpointer;
            break;
        }
    }
    return temp;
}

bool tuopuform::graphicsevent(QEvent *event)
{
    if (event->type()==QEvent::MouseButtonPress)
    {
        qDebug() <<"事件"<< event->staticMetaObject.className();
    }
    if (event->type()==clyyEventType)
    {
        qDebug() <<((clyyEvent*)event)->res;
        qDebug() <<"自定义事件";
        ((clyyEvent*)event)->res=90;
    }
    return true;
}

#ifdef CLYYMUBAN
template<typename T1,typename T2> T1 * tuopuform::CreateT(qreal x, qreal y, qreal w, qreal h, T2 *parent)
{
    T1 * a=new T1(x,y,w,h,parent);
    clyyScene->addItem(a);
    return a;
}
#endif

void tuopuform::on_actionAddWangYuan_triggered()
{
    QList<QGraphicsItem*> xx=clyyScene->selectedItems();
    if(0!=xx.count())
    {
        for(int i=xx.count()-1;i>=0;--i)
        {
            qDebug() <<"cc"<< i;
            DeleteGraphicsItem(xx[i]);
        }
    }
}

void tuopuform::on_actionAddZiWang_triggered()
{
    clyyEvent xx(clyyEventType);
    xx.res=10;
    qApp->sendEvent(ui->graphicsView,&xx);
    qDebug() <<xx.res;
    clyyEvent *aa=new clyyEvent(clyyEventType);
    aa->res=10;
    qApp->postEvent(ui->graphicsView,aa);
    qDebug() <<"发送"<<aa->res;
}

void tuopuform::on_actionAddLianLu_triggered()
{
    QWidget ss;
    ss.setAttribute(Qt::WA_ShowModal, true);
    ss.show();
    qDebug() <<"model";
}
