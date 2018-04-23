#ifndef SDIALOG_GLOBAL_H
#define SDIALOG_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SDIALOG_LIBRARY)
#  define SDIALOGSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SDIALOGSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SDIALOG_GLOBAL_H
