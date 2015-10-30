#ifndef CLYYMODEL_H
#define CLYYMODEL_H

#include <QAbstractItemModel>

const int c_nflags_col_no = 0;
const int c_npaint_col_no = 1;
const int c_nparbar_col_no = 2;

class clyyData
{
public:
    void setColData(int nIndex, const QVariant &data){ m_ColData[nIndex] = data; }
    QVariant colData(int nIndex){ return m_ColData.at(nIndex); }
    int count(){ return m_ColData.count(); }
    clyyData &operator <<(const QVariant &data){ m_ColData << data; return *this; }

private:
    QList<QVariant> m_ColData;

};

class clyyModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit clyyModel(QObject *pParent = nullptr);
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

};

#endif // CLYYMODEL_H
