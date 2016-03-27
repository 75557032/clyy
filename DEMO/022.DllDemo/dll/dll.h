#ifndef DLL_H
#define DLL_H

#include "dll_global.h"
#include <QMetaObject>
#include <QObject>

class DLLSHARED_EXPORT Dll
{
public:
    Dll();
};
class MyObject:public QObject
{
    Q_OBJECT
};

extern int addclyy();
extern const QMetaObject* newclyy();
#endif // DLL_H
