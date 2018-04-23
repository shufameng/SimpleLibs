#ifndef SLANGUAGEMANAGER_H
#define SLANGUAGEMANAGER_H

#include "slanguagemanager_global.h"
#include <QString>
#include <QMap>

class SLANGUAGEMANAGERSHARED_EXPORT SLanguageManager
{
public:
    SLanguageManager();
    ~SLanguageManager();

    bool loadXML(const QString &xmlPath);
    bool loadINI(const QString &iniPath);
    const QString findText(const QString &key);

    inline const QString getErrorString() const
    { return mErrorString; }

protected:
    inline void setErrorString(const QString &string)
    { mErrorString = string; }

private:
    QMap<QString,QString> mData;
    QString mErrorString;
};

#endif // SLANGUAGEMANAGER_H
