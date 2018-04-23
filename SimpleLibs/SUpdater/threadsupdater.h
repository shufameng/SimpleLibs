#ifndef THREADSUPDATER_H
#define THREADSUPDATER_H

#include <QThread>
#include <QFile>
#include <QSemaphore>

class ThreadSUpdater : public QThread
{
    Q_OBJECT

public:
    explicit ThreadSUpdater(QObject *parent = 0);
    ~ThreadSUpdater();

signals:
    void statusChanged(const QString &status);
    void updateFinished(const QString &errorString);

protected:
    virtual void run();
    void afterDownloadVerFile();

protected slots:
    void onDownloadVerFileFinished();
    void onDownloadVerFileProgress(qint64 bytesReceived, qint64 bytesTotal);
    void onDownloadVerFileReadyRead();
private:
    QFile mVerFile;
};

#endif // THREADSUPDATER_H
