#ifndef QJS_GLOBAL_H
#define QJS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QJS_LIBRARY)
#  define QJSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QJSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QJS_GLOBAL_H
