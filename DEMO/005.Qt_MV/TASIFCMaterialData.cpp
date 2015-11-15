#include <assert.h>
#include <QStringList>
#include "TASIFCMaterialData.h"

CTASIFCMaterialItem::CTASIFCMaterialItem(const QString &strSourceMaterial, const QString &strTargetMaterial)
    : m_strSourceMaterial(strSourceMaterial), m_strTargetMaterial(strTargetMaterial)
{
    //
}

QVariant CTASIFCMaterialItem::data(int nIndex) const
{
    switch (nIndex)
    {
    case IFCSOURCEMATERIALITEMCOL: return m_strSourceMaterial;
    case IFCTARGETMATERIALITEMCOL: return m_strTargetMaterial;
    default: return QVariant();
    };
}

bool CTASIFCMaterialItem::setData(int nIndex, const QVariant &value)
{
    switch (nIndex)
    {
    case IFCSOURCEMATERIALITEMCOL:
    {
        m_strSourceMaterial = value.toString();
        return true;
    }
    case IFCTARGETMATERIALITEMCOL:
    {
        m_strTargetMaterial = value.toString();
        return true;
    }
    };
    return false;
}

CTASIFCMaterialItems::~CTASIFCMaterialItems()
{
    clear();
}

ITASIFCMaterialItem *CTASIFCMaterialItems::materialItem(int nIndex) const
{
    if ((0 > nIndex) || (m_List.count() <= nIndex))
    {
        return nullptr;
    }
    return m_List.at(nIndex);
}

void CTASIFCMaterialItems::addMaterialItem(ITASIFCMaterialItem *pMaterialItem)
{
    assert(pMaterialItem);
    if (nullptr == findItemBySourceMaterial(pMaterialItem->sourceMaterial()))
    {
        m_List.append(pMaterialItem);
    }
}

void CTASIFCMaterialItems::clear()
{
    for (int i = m_List.count() - 1; i >= 0; --i)
    {
        delete m_List.at(i);
    }
    m_List.clear();
}

ITASIFCMaterialItem *CTASIFCMaterialItems::findItemBySourceMaterial(const QString &strSourceMaterial) const
{
    for (int i = 0; i < m_List.count(); ++i)
    {
        if (m_List.at(i)->sourceMaterial() == strSourceMaterial)
        {
            return m_List.at(i);
        }
    }
    return nullptr;
}

QVariant CTASIFCMaterialItems::fieldData(int nIndex) const
{
    switch (nIndex)
    {
    case IFCSOURCEMATERIALITEMCOL: return "m_strSourceMaterial";
    case IFCTARGETMATERIALITEMCOL: return "m_strTargetMaterial";
    default: return QVariant();
    }
}

bool CTASIFCMaterialItems::isReadWrite(int nIndex) const
{
    switch (nIndex)
    {
    case IFCSOURCEMATERIALITEMCOL: return false;
    case IFCTARGETMATERIALITEMCOL: return true;
    default: return false;
    }
}

ITASIFCMaterialItems::EnDataState CTASIFCMaterialItems::dataState(int nCol, int nRow) const
{
    if (!isReadWrite(nCol))
    {
        return onlyRead;
    }
    ITASIFCMaterialItem *pItem = materialItem(nRow);
    if (nullptr == pItem)
    {
        return none;
    }
    QString strDefult = defaultTarget(pItem->sourceMaterial());
    if (strDefult == pItem->targetMaterial())
    {
        return defauleData;
    }
    else
    {
        return modifyData;
    }
}

void CTASIFCMaterialItems::resetData()
{
    for (int i = 0; i < m_List.count(); ++i)
    {
        ITASIFCMaterialItem *pItem = m_List.at(i);
        if (nullptr == pItem)
        {
            continue;
        }
        QString strDefult = defaultTarget(pItem->sourceMaterial());
        pItem->setTargetMaterial(strDefult);
    }
}
