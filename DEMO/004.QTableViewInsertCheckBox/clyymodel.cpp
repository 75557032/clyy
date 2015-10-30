#include <QList>
#include "clyymodel.h"

static QList<clyyData> clyy_list = {clyyData() << true << true << 0, clyyData() << false << true << 5
                                    , clyyData() << false << true << 10, clyyData() << true << true << 20};

clyyModel::clyyModel(QObject *pParent) : QAbstractItemModel(pParent)
{

}

QModelIndex clyyModel::index(int row, int column, const QModelIndex &parent __attribute__((unused))) const
{
    if (parent.isValid())
    {
        return QModelIndex();
    }
    return createIndex(row, column);
}

QModelIndex clyyModel::parent(const QModelIndex &child __attribute__((unused))) const
{
    return QModelIndex();
}

int clyyModel::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
    {
        return clyy_list.count();
    }
    return 0;
}

int clyyModel::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
    {
        return clyy_list[0].count();
    }
    return 0;
}

QVariant clyyModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    switch (role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
    {
        if (c_nflags_col_no == index.column())
        {
            break;
        }
        return clyy_list[index.row()].colData(index.column());
    }
    case Qt::CheckStateRole:
    {
        if (c_nflags_col_no == index.column())
        {
            return clyy_list[index.row()].colData(index.column()).toBool() ? Qt::Checked : Qt::Unchecked;
        }
    }
    }
    return QVariant();
}

Qt::ItemFlags clyyModel::flags(const QModelIndex &index) const
{
    if (c_nflags_col_no == index.column())
    {
        return Qt::ItemIsUserCheckable | Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
    }
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

bool clyyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid())
    {
        return true;
    }

    switch (role)
    {
    case Qt::EditRole:
    {
        if (c_nparbar_col_no == index.column())
        {
            return true;
        }
        clyy_list[index.row()].setColData(index.column(), value);
    }
        break;
    case Qt::CheckStateRole:
    {
        bool bTemp = clyy_list[index.row()].colData(index.column()).toBool();
        clyy_list[index.row()].setColData(index.column(), !bTemp);
    }
    }
    return true;
}

