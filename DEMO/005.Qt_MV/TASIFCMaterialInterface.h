#ifndef TASIFCMATERIALINTERFACE
#define TASIFCMATERIALINTERFACE

#include <QObject>
#include <QString>
#include <QStringList>
#include <QMap>
#include <QSet>
#include <QVariant>

class ITASIFCMaterialItem
{
public:
    virtual ~ITASIFCMaterialItem(){}

public:
    virtual QString sourceMaterial() = 0;
    virtual QString targetMaterial() = 0;
    virtual void setSourceMaterial(const QString &strSourceMaterial) = 0;
    virtual void setTargetMaterial(const QString &strTargetMaterial) = 0;
    virtual QVariant data(int nIndex) const = 0;
    virtual bool setData(int nIndex, const QVariant &value) = 0;

};

class ITASIFCMaterialItems : public QObject
{
    Q_OBJECT

public:
    enum EnDataState
    {
        none,
        onlyRead,
        defauleData,
        modifyData
    };

public:
    virtual ITASIFCMaterialItem *materialItem(int nIndex) const = 0;
    virtual void addMaterialItem(ITASIFCMaterialItem *pMaterialItem) = 0;
    virtual int count() = 0;
    virtual void clear() = 0;
    virtual ITASIFCMaterialItem *findItemBySourceMaterial(const QString &strSourceMaterial) const = 0;
    virtual int fieldCount() = 0;
    virtual QVariant fieldData(int nIndex) const = 0;
    virtual bool isReadWrite(int nIndex) const = 0;
    virtual ITASIFCMaterialItems::EnDataState dataState(int nCol, int nRow) const = 0;
    virtual void resetData() = 0;

    static QString defaultTarget(const QString &strSource)
    {
        QString strFormatSource = findStringInBegin(strSource);
        if ("" == strFormatSource)
        {
            return QString("In-situ Concrete");
        }
        const QMap<QString, QString> &map = templateList();
        auto it = map.find(strFormatSource);
        if (it != map.end())
        {
            return it.value();
        }
        return QString("In-situ Concrete");
    }
    static void targetList(QStringList &list)
    {
        const QMap<QString, QString> &map = templateList();
        list = QStringList::fromSet(map.values().toSet());
    }

private:
    static QMap<QString, QString> initMap()
    {
        QMap<QString, QString> result;
        result[QString("Concrete").toLower()] = "In-situ Concrete";
        result[QString("Precast").toLower()] = "Precast";
        result[QString("Brick").toLower()] = "Brick";
        result[QString("Block").toLower()] = "Block";
        result[QString("Stone").toLower()] = "Stone";
        result[QString("Light panel").toLower()] = "Light Panel";
        result[QString("Color steel plate").toLower()] = "Color Steel Plate";
        result[QString("Wooden").toLower()] = "Wooden Partition";
        result[QString("Glass").toLower()] = "Glass";
        result[QString("Masonry").toLower()] = "Brick";
        result[QString("Steel").toLower()] = "Steel";
        return result;
    }
    static const QMap<QString, QString> &templateList()
    {
        static QMap<QString, QString> s_TemplateList = initMap();
        return s_TemplateList;
    }
    static QString findStringInBegin(const QString &strSource)
    {
        const QMap<QString, QString> &map = templateList();
        QString strFormatSource = strSource.toLower();
        QString strReslut = "";
        int nMin = -1;
        for (auto it = map.begin(); it != map.end(); ++it)
        {
            int nIndex = strFormatSource.indexOf(it.key());
            if (-1 != nIndex)
            {
                if ((nMin > nIndex) || (-1 == nMin))
                {
                    nMin = nIndex;
                    strReslut = it.key();
                }
            }
        }
        return strReslut;
    }

};

#endif // TASIFCMATERIALINTERFACE

