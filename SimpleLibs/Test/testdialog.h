#ifndef TESTDIALOG_H
#define TESTDIALOG_H

#include <QDialog>
#include <QThread>

#include "sdialog.h"
#include "slanguagemanager.h"
#include "slogger.h"

namespace Ui {
class WidgetTest;
}

class TestDialog : public SDialog
{
    Q_OBJECT

public:
    explicit TestDialog(QWidget *parent = 0);
    ~TestDialog();

private slots:
    void onPushButtonSLanguageManager();
    void onPushButtonSLogger();
    void onPushButtonSHttp();

private:
    Ui::WidgetTest *ui;
    SLogger *mLogger;
};

class LogThread : public QThread
{
    Q_OBJECT
public:
    LogThread(SLogger *logger, QObject *parent = 0) : QThread(parent), mLogger(logger)
    {}
    ~LogThread()
    {}
protected:
    void run()
    {
        int i =  1000;
        while (i --)
        {
            mLogger->addLog("You are not alone");
        }
    }
private:
    SLogger *mLogger;
};

#endif // TESTDIALOG_H
