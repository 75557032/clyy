#include <QApplication>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPainter>
#include "clyymodel.h"
#include "clyydelegate.h"

clyyDelegate::clyyDelegate(QObject *pParent) : QStyledItemDelegate(pParent)
{

}

void clyyDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    switch (index.column())
    {
    case c_npaint_col_no:
    {
        painter->save();//保存当前状态
        QStyleOptionButton check_box_style_option;
        check_box_style_option.state = option.state;
        check_box_style_option.state |= QStyle::State_Enabled;
        if(index.data().toBool())
        {
            check_box_style_option.state |= QStyle::State_On;
        }
        else
        {
            check_box_style_option.state |= QStyle::State_Off;
        }
        check_box_style_option.direction = QApplication::layoutDirection();
        QRect newRect = QStyle::alignedRect(option.direction, Qt::AlignCenter,
                                                        QSize(option.decorationSize.width() + 5,option.decorationSize.height()),
                                                        QRect(option.rect.x() , option.rect.y(),
                                                              option.rect.width(), option.rect.height()));
        check_box_style_option.rect = newRect;
        QApplication::style()->drawControl(QStyle::CE_CheckBox, &check_box_style_option, painter);
        painter->restore();//恢复保存状态
        return;
    }
    case c_nparbar_col_no:
    {
        painter->save();
        QStyleOptionProgressBarV2 progressbar_style_option;
        progressbar_style_option.minimum = 0;
        progressbar_style_option.maximum = 20;
        progressbar_style_option.progress = index.model()->data(index, Qt::DisplayRole).toInt();
        progressbar_style_option.rect = option.rect;
        QApplication::style()->drawControl(QStyle::CE_ProgressBar, &progressbar_style_option, painter);
        painter->restore();
        return;
    }
    }
    QStyledItemDelegate::paint(painter, option, index);
}

bool clyyDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option __attribute__((unused)), const QModelIndex &index)
{
    if((event->type() == QEvent::MouseButtonRelease) || (event->type() == QEvent::MouseButtonDblClick))
    {
        QMouseEvent *mouse_event = static_cast<QMouseEvent*>(event);
        if(mouse_event->button() != Qt::LeftButton)
        {
            return false;
        }
        if(event->type() == QEvent::MouseButtonDblClick)
        {
            return true;
        }
    }
    else if(event->type() == QEvent::KeyPress)
    {
        if(static_cast<QKeyEvent*>(event)->key() != Qt::Key_Space && static_cast<QKeyEvent*>(event)->key() != Qt::Key_Select)
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    bool checked = index.model()->data(index, Qt::DisplayRole).toBool();
    return model->setData(index, !checked, Qt::EditRole);
}

QWidget *clyyDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (c_npaint_col_no == index.column())
    {
        return nullptr;
    }
    return QStyledItemDelegate::createEditor(parent, option, index);
}

