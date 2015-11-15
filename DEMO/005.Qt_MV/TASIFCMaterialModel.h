#ifndef TASIFCMATERIALMODEL_H
#define TASIFCMATERIALMODEL_H

#include <QPointer>
#include <QAbstractItemModel>

class ITASIFCMaterialItems;

class CTASIFCMaterialModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit CTASIFCMaterialModel(ITASIFCMaterialItems *pMaterialItems = nullptr, QObject *pParent = nullptr);

public:
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

public:
    void setMaterialItems(ITASIFCMaterialItems *pMaterialItems);
    void resetMaterialItems();
    ITASIFCMaterialItems *materialItems();

private:
    QPointer<ITASIFCMaterialItems> m_MaterialItems;

private:
    QVariant showText(const QModelIndex &index) const;
    QVariant showBackgroundColor(const QModelIndex &index) const;

};

#endif // TASIFCMATERIALMODEL_H
