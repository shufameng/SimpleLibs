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
    // 1.下载最新的xml版本文件到临时文件夹.
    emit statusChanged("Check local version");
    QUrl url(URL_VER_FILE);
    mVerFile.setFileName(QDir::current().filePath(url.fileName()));

    // 打开文件写入数据
    if (!mVerFile.open(QIODevice::WriteOnly))
    {
        emit updateFinished(mVerFile.errorString());
        return;
    }

    // 开始下载文件
    QNetworkRequest request;
    request.setUrl(url);
    QNetworkReply *pReply = gNetworkManager.get(request);
    connect(pReply, SIGNAL(finished()), this, SLOT(onDownloadVerFileFinished()));
    connect(pReply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(onDownloadVerFileProgress(qint64,qint64)));
    connect(pReply, SIGNAL(readyRead()), this, SLOT(onDownloadVerFileReadyRead()));

    // 2.解析本地xml版本文件和下载的最新xml版本文件.
    // 3.对比xml版本文件,获取需要更新的文件.
    // 4.下载需要更新的文件到临时文件夹.
    // 5.关闭程序.
    // 6.将下载的更新程序从临时文件夹覆盖旧文件.
    // 7.启动程序.
}

void ThreadSUpdater::afterDownloadVerFile()
{
    // 1.下载最新的xml版本文件到临时文件夹.
    // 2.解析本地xml版本文件和下载的最新xml版本文件.



    // 3.对比xml版本文件,获取需要更新的文件.
    // 4.下载需要更新的文件到临时文件夹.
    // 5.关闭程序.
    // 6.将下载的更新程序从临时文件夹覆盖旧文件.
    // 7.启动程序.
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

