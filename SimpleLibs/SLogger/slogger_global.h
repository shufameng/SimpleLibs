#ifndef SLOGGER_GLOBAL_H
#define SLOGGER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SLOGGER_LIBRARY)
#  define SLOGGERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SLOGGERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SLOGGER_GLOBAL_H
