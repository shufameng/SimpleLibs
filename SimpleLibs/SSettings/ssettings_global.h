#ifndef SSETTINGS_GLOBAL_H
#define SSETTINGS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SSETTINGS_LIBRARY)
#  define SSETTINGSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SSETTINGSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SSETTINGS_GLOBAL_H
