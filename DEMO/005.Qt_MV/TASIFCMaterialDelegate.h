#ifndef TASIFCMATERIALDELEGATE_H
#define TASIFCMATERIALDELEGATE_H

#include <QStyledItemDelegate>

class CTASIFCMaterialDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit CTASIFCMaterialDelegate(QObject *pParent = nullptr);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void destroyEditor(QWidget *editor, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

};

#endif // TASIFCMATERIALDELEGATE_H
