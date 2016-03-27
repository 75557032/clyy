#ifndef DLL_GLOBAL_H
#define DLL_GLOBAL_H

#include <QtCore/qglobal.h>
#include "dll.h"
#include <QMetaObject>

#if defined(DLL_LIBRARY)
#  define DLLSHARED_EXPORT Q_DECL_EXPORT
#else
#  define DLLSHARED_EXPORT Q_DECL_IMPORT
#endif

int foo __attribute__((section ("shared"), shared)) = 0;
extern "C" DLLSHARED_EXPORT int addclyy();
extern "C" DLLSHARED_EXPORT const QMetaObject* newclyy();

#endif // DLL_GLOBAL_H
