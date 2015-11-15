#include <QDebug>
#include <QComboBox>
#include "TASIFCMaterialInterface.h"
#include "TASIFCMaterialDelegate.h"

CTASIFCMaterialDelegate::CTASIFCMaterialDelegate(QObject *pParent)
    : QStyledItemDelegate(pParent)
{

}

QWidget *CTASIFCMaterialDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    QWidget *pResult = nullptr;
    if (1 == index.column())
    {
        pResult = new QComboBox(parent);
        QStringList list;
        ITASIFCMaterialItems::targetList(list);
        static_cast<QComboBox *>(pResult)->insertItems(0, list);
    }
    else
    {
        pResult = QStyledItemDelegate::createEditor(parent, option, index);
    }
    return pResult;
}

void CTASIFCMaterialDelegate::destroyEditor(QWidget *editor, const QModelIndex &index) const
{
    QStyledItemDelegate::destroyEditor(editor, index);
}

void CTASIFCMaterialDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QStyledItemDelegate::setEditorData(editor, index);
}

void CTASIFCMaterialDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QStyledItemDelegate::setModelData(editor, model, index);
}

