#ifndef CLYYDELEGATE_H
#define CLYYDELEGATE_H

#include <QStyledItemDelegate>

class clyyDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit clyyDelegate(QObject *pParent = nullptr);

protected:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) override;
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

};

#endif // CLYYDELEGATE_H
