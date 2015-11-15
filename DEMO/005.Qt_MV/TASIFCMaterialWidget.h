#ifndef TASIFCMATERIALWIDGET_H
#define TASIFCMATERIALWIDGET_H

#include <QWidget>

class QTableView;
class QVBoxLayout;
class CTASIFCMaterialModel;
class CTASIFCMaterialDelegate;
class ITASIFCMaterialItems;

class CTASIFCMaterialWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CTASIFCMaterialWidget(ITASIFCMaterialItems *pItem, QWidget *pParent = nullptr, Qt::WindowFlags f = 0);
    ~CTASIFCMaterialWidget();

private:
    void initUi();
    void resetModel();

private:
    QTableView *m_pTableView;
    QVBoxLayout *m_pVBoxLayout;
    CTASIFCMaterialModel *m_pMaterialModel;
    CTASIFCMaterialDelegate *m_pMaterialDelegate;
    ITASIFCMaterialItems *m_pItem;

};

#endif // TASIFCMATERIALWIDGET_H
