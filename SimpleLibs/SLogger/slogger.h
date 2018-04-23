#ifndef SLOGGER_H
#define SLOGGER_H

#include "slogger_global.h"
#include <QString>
#include <QFile>
#include <QDir>
#include <QMutex>

class SLOGGERSHARED_EXPORT SLogger
{

public:
    SLogger(const QDir &logDir);
    ~SLogger();

    bool addLog(const QString &log);

private:
    QDir mLogDir;
    QMutex mLogMutex;
};

#endif // SLOGGER_H
