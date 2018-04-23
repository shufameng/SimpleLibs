#include "threadsupdater.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDir>
#include <QDebug>

#define URL_VER_FILE "http://localhost/version.xml"

QNetworkAccessManager gNetworkManager;

ThreadSUpdater::ThreadSUpdater(QObject *parent) :
    QThread(parent)
{

}

ThreadSUpdater::~ThreadSUpdater()
{

}

void ThreadSUpdater::run()
{
    // 1.�������µ�xml�汾�ļ�����ʱ�ļ���.
    emit statusChanged("Check local version");
    QUrl url(URL_VER_FILE);
    mVerFile.setFileName(QDir::current().filePath(url.fileName()));

    // ���ļ�д������
    if (!mVerFile.open(QIODevice::WriteOnly))
    {
        emit updateFinished(mVerFile.errorString());
        return;
    }

    // ��ʼ�����ļ�
    QNetworkRequest request;
    request.setUrl(url);
    QNetworkReply *pReply = gNetworkManager.get(request);
    connect(pReply, SIGNAL(finished()), this, SLOT(onDownloadVerFileFinished()));
    connect(pReply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(onDownloadVerFileProgress(qint64,qint64)));
    connect(pReply, SIGNAL(readyRead()), this, SLOT(onDownloadVerFileReadyRead()));

    // 2.��������xml�汾�ļ������ص�����xml�汾�ļ�.
    // 3.�Ա�xml�汾�ļ�,��ȡ��Ҫ���µ��ļ�.
    // 4.������Ҫ���µ��ļ�����ʱ�ļ���.
    // 5.�رճ���.
    // 6.�����صĸ��³������ʱ�ļ��и��Ǿ��ļ�.
    // 7.��������.
}

void ThreadSUpdater::afterDownloadVerFile()
{
    // 1.�������µ�xml�汾�ļ�����ʱ�ļ���.
    // 2.��������xml�汾�ļ������ص�����xml�汾�ļ�.



    // 3.�Ա�xml�汾�ļ�,��ȡ��Ҫ���µ��ļ�.
    // 4.������Ҫ���µ��ļ�����ʱ�ļ���.
    // 5.�رճ���.
    // 6.�����صĸ��³������ʱ�ļ��и��Ǿ��ļ�.
    // 7.��������.
}

void ThreadSUpdater::onDownloadVerFileFinished()
{
    mVerFile.close();

    QNetworkReply *pReply = dynamic_cast<QNetworkReply*>(sender());
    if (!pReply)
    {
        emit updateFinished("reply object is null");
        return;
    }

    if (QNetworkReply::NoError != pReply->error())
    {
        emit updateFinished(pReply->errorString());
        return;
    }
    else
    {
        emit statusChanged("Version file successful download.");
        afterDownloadVerFile();
    }
}

void ThreadSUpdater::onDownloadVerFileProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    //emit statusChanged(QString("%1%").arg(100*(double)bytesReceived/(double)bytesTotal));
}

void ThreadSUpdater::onDownloadVerFileReadyRead()
{
    QNetworkReply *pReply = dynamic_cast<QNetworkReply*>(sender());
    if (!pReply)
    {
        emit updateFinished("reply object is null");
        return;
    }
    mVerFile.write(pReply->readAll());
}

