#ifndef SUPDATER_GLOBAL_H
#define SUPDATER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SUPDATER_LIBRARY)
#  define SUPDATERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SUPDATERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SUPDATER_GLOBAL_H
