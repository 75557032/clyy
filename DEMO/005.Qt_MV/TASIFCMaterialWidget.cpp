#include <QTableView>
#include <QVBoxLayout>
#include <QAction>
#include <QMessageBox>
#include "TASIFCMaterialInterface.h"
#include "TASIFCMaterialDelegate.h"
#include "TASIFCMaterialModel.h"
#include "TASIFCMaterialWidget.h"


CTASIFCMaterialWidget::CTASIFCMaterialWidget(ITASIFCMaterialItems *pItem, QWidget *pParent, Qt::WindowFlags f)
    : QWidget(pParent, f), m_pTableView(new QTableView(this)), m_pMaterialModel(new CTASIFCMaterialModel)
    , m_pMaterialDelegate(new CTASIFCMaterialDelegate), m_pItem(pItem)
{
    initUi();
    m_pMaterialModel->setMaterialItems(m_pItem);
    m_pTableView->setContextMenuPolicy(Qt::ActionsContextMenu);
    m_pTableView->setModel(m_pMaterialModel);
    m_pTableView->setItemDelegate(m_pMaterialDelegate);
    QAction *p = new QAction("xx", m_pTableView);
    connect(p, &QAction::triggered, this, &CTASIFCMaterialWidget::resetModel);
    m_pTableView->addAction(p);
}

CTASIFCMaterialWidget::~CTASIFCMaterialWidget()
{
    delete m_pMaterialDelegate;
    delete m_pMaterialModel;
}

void CTASIFCMaterialWidget::initUi()
{
    m_pVBoxLayout = new QVBoxLayout(this);
    m_pVBoxLayout->addWidget(m_pTableView);
}

void CTASIFCMaterialWidget::resetModel()
{
    m_pMaterialModel->resetMaterialItems();
    QMessageBox::about(nullptr, "xx", "sa");
}
