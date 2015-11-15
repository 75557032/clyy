#ifndef TASIFCMATERIALDATA_H
#define TASIFCMATERIALDATA_H

#include <QList>
#include "TASIFCMaterialInterface.h"

#define IFCMATERIALITEMCOUNT 2
#define IFCSOURCEMATERIALITEMCOL 0
#define IFCTARGETMATERIALITEMCOL 1

class CTASIFCMaterialItem : public ITASIFCMaterialItem
{
public:
    CTASIFCMaterialItem(const QString &strSourceMaterial, const QString &strTargetMaterial);

public:
    QString sourceMaterial() override { return m_strSourceMaterial; }
    QString targetMaterial() override { return m_strTargetMaterial; }
    void setSourceMaterial(const QString &strSourceMaterial) override { m_strSourceMaterial = strSourceMaterial; }
    void setTargetMaterial(const QString &strTargetMaterial) override { m_strTargetMaterial = strTargetMaterial; }
    QVariant data(int nIndex) const override;
    bool setData(int nIndex, const QVariant &value) override;

public:
    static int count(){ return IFCMATERIALITEMCOUNT; }

private:
    QString m_strSourceMaterial;
    QString m_strTargetMaterial;

};

class CTASIFCMaterialItems : public ITASIFCMaterialItems
{
public:
    ~CTASIFCMaterialItems();

public:
    ITASIFCMaterialItem *materialItem(int nIndex) const override;
    void addMaterialItem(ITASIFCMaterialItem *pMaterialItem) override;
    int count() override { return m_List.count(); }
    void clear() override;
    ITASIFCMaterialItem *findItemBySourceMaterial(const QString &strSourceMaterial) const override;
    int fieldCount() override { return CTASIFCMaterialItem::count(); }
    QVariant fieldData(int nIndex) const override;
    bool isReadWrite(int nIndex) const override;
    EnDataState dataState(int nCol, int nRow) const override;
    void resetData() override;

private:
    QList<ITASIFCMaterialItem *> m_List;

};

#endif // TASIFCMATERIALDATA_H
