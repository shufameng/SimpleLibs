#include "slanguagemanager.h"
#include <QXmlStreamReader>
#include <QFile>

SLanguageManager::SLanguageManager()
{
}

SLanguageManager::~SLanguageManager()
{

}

bool SLanguageManager::loadXML(const QString &xmlPath)
{
    QFile xmlFile(xmlPath);
    if (!xmlFile.open(QIODevice::ReadOnly))
    {
        setErrorString(QString("SLanguageManager:Open xml file failed, %1").arg(xmlFile.errorString()));
        return false;
    }

    QXmlStreamReader reader(&xmlFile);
    while (!reader.atEnd())
    {
        QXmlStreamReader::TokenType type = reader.readNext();
        if (QXmlStreamReader::StartElement == type)
        {
            if (reader.name() != "xml")
            {
                mData[reader.name().toString()] = reader.readElementText();
            }
        }
        else if (QXmlStreamReader::Invalid == type)
        {
            setErrorString(QString("SLanguageManager:Parse xml failed, %1").arg(reader.errorString()));
            return false;
        }
        else
        {

        }
    }
    return true;
}

bool SLanguageManager::loadINI(const QString &iniPath)
{
    return true;
}

const QString SLanguageManager::findText(const QString &key)
{
    QMap<QString,QString>::iterator it = mData.find(key);
    if (mData.end() == it)
        return "";
    else
        return it.value();
}
