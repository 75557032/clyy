#include <QColor>
#include "TASIFCMaterialInterface.h"
#include "TASIFCMaterialModel.h"

CTASIFCMaterialModel::CTASIFCMaterialModel(ITASIFCMaterialItems *pMaterialItems, QObject *pParent)
    : QAbstractItemModel(pParent), m_MaterialItems(pMaterialItems)
{

}

QModelIndex CTASIFCMaterialModel::index(int row, int column, const QModelIndex &parent) const
{
    if (m_MaterialItems.isNull())
    {
        return QModelIndex();
    }
    if (parent.isValid())
    {
        return QModelIndex();
    }
    return createIndex(row, column);
}

QModelIndex CTASIFCMaterialModel::parent(const QModelIndex &child) const
{
    child;
    return QModelIndex();
}

int CTASIFCMaterialModel::rowCount(const QModelIndex &parent) const
{
    if (m_MaterialItems.isNull())
    {
        return 0;
    }
    if (parent.isValid())
    {
        return 0;
    }
    return m_MaterialItems->count();
}

int CTASIFCMaterialModel::columnCount(const QModelIndex &parent) const
{
    if (m_MaterialItems.isNull())
    {
        return 0;
    }
    if (parent.isValid())
    {
        return 0;
    }
    return m_MaterialItems->fieldCount();
}

QVariant CTASIFCMaterialModel::data(const QModelIndex &index, int role) const
{
    if (m_MaterialItems.isNull())
    {
        return QVariant();
    }
    if (!index.isValid())
    {
        return QVariant();
    }
    switch (role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole: return showText(index);
    case Qt::BackgroundColorRole: return showBackgroundColor(index);
    default: break;
    };
    return QVariant();
}

bool CTASIFCMaterialModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (m_MaterialItems.isNull())
    {
        return true;
    }
    if (!index.isValid())
    {
        return true;
    }
    if (Qt::EditRole == role)
    {
        if (m_MaterialItems->isReadWrite(index.column()))
        {
            ITASIFCMaterialItem *pItem = m_MaterialItems->materialItem(index.row());
            if (nullptr != pItem)
            {
                return pItem->setData(index.column(), value);
            }
        }
    }
    return true;
}

QVariant CTASIFCMaterialModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (m_MaterialItems.isNull())
    {
        return QVariant();
    }
    if (Qt::Horizontal == orientation)
    {
        if (Qt::DisplayRole == role)
        {
            return m_MaterialItems->fieldData(section);
        }
    }
    else
    {
        if (Qt::DisplayRole == role)
        {
            return section;
        }
    }
    return QVariant();
}

Qt::ItemFlags CTASIFCMaterialModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags result = QAbstractItemModel::flags(index);
    if (m_MaterialItems.isNull())
    {
        return result;
    }
    if (m_MaterialItems->isReadWrite(index.column()))
    {
        return result | Qt::ItemIsEditable;
    }
    return result;
}

void CTASIFCMaterialModel::setMaterialItems(ITASIFCMaterialItems *pMaterialItems)
{
    beginResetModel();
    m_MaterialItems = pMaterialItems;
    endResetModel();
}

void CTASIFCMaterialModel::resetMaterialItems()
{
    if (m_MaterialItems.isNull())
    {
        return;
    }
    beginResetModel();
    m_MaterialItems->resetData();
    endResetModel();
}

ITASIFCMaterialItems *CTASIFCMaterialModel::materialItems()
{
    return m_MaterialItems;
}

QVariant CTASIFCMaterialModel::showText(const QModelIndex &index) const
{
    ITASIFCMaterialItem *pItem = m_MaterialItems->materialItem(index.row());
    if (nullptr != pItem)
    {
        return pItem->data(index.column());
    }
    else
    {
        return QVariant();
    }
}

QVariant CTASIFCMaterialModel::showBackgroundColor(const QModelIndex &index) const
{
    ITASIFCMaterialItems::EnDataState dataState= m_MaterialItems->dataState(index.column(), index.row());
    switch (dataState)
    {
    case ITASIFCMaterialItems::onlyRead: return QColor(255, 0, 0);
    case ITASIFCMaterialItems::modifyData: return QColor(0, 255, 0);
    }

    return QVariant();
}
