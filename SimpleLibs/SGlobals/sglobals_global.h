#ifndef SGLOBALS_GLOBAL_H
#define SGLOBALS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SGLOBALS_LIBRARY)
#  define SGLOBALSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SGLOBALSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SGLOBALS_GLOBAL_H
