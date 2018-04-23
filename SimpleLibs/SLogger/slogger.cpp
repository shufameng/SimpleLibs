#include "slogger.h"
#include <QDateTime>
#include <QTextStream>

SLogger::SLogger(const QDir &logDir) :
    mLogDir(logDir)
{

}

SLogger::~SLogger()
{

}

bool SLogger::addLog(const QString &log)
{
    QFile logFile(mLogDir.filePath(QDate::currentDate().toString("yyyy-MM-dd.log")));

    mLogMutex.lock();
    if (!logFile.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        mLogMutex.unlock();
        return false;
    }
    QTextStream out(&logFile);
    out << QString("[%1]:%2").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")).arg(log) << "\r\n";
    logFile.flush();
    logFile.close();
    mLogMutex.unlock();

    return true;
}
