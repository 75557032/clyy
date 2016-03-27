#include "dll.h"
#include "dll_global.h"
#include <QMetaObject>
#include <QObject>
#include <QMessageBox>

Dll::Dll()
{
}

int addclyy()
{
    //const QMetaObject *xx=&(QObject::staticMetaObject);
    //xx->newInstance();
    return foo++;
}

const QMetaObject* newclyy()
{
    QMessageBox::information(NULL, "Title", MyObject::staticMetaObject.className());
    return &(MyObject::staticMetaObject);
}
