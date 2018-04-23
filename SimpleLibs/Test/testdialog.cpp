#include "testdialog.h"
#include "ui_frametest.h"
#include <QVBoxLayout>
#include <QDebug>
#include "dialogdownloadfile.h"

TestDialog::TestDialog(QWidget *parent) :
    SDialog(parent),
    ui(new Ui::FrameTest),
    mLogger(new SLogger(QDir::current()))
{
    setWindowTitle("Test Library Application");
    ui->setupUi(CentralFrame());

    connect(ui->pushButton_SLanguageManager, SIGNAL(clicked()), this, SLOT(onPushButtonSLanguageManager()));
    connect(ui->pushButton_SLogger, SIGNAL(clicked()), this, SLOT(onPushButtonSLogger()));
    connect(ui->pushButton_SHttp, SIGNAL(clicked()), this, SLOT(onPushButtonSHttp()));
}

TestDialog::~TestDialog()
{
    delete ui;
}

void TestDialog::onPushButtonSLanguageManager()
{
    SLanguageManager manager;
    if (!manager.loadXML("test.xml"))
    {
        qDebug() << manager.getErrorString();
    }
    else
    {
        qDebug() << manager.findText("BTN_YES");
        qDebug() << manager.findText("BTN_NO");
        qDebug() << manager.findText("BTN_CONTINUE");
        qDebug() << manager.findText("BTN_ARE_YOU_SURE");
    }
}

void TestDialog::onPushButtonSLogger()
{
    LogThread *t1 = new LogThread(mLogger, this);
    LogThread *t2 = new LogThread(mLogger, this);
    t1->start();
    t2->start();

    qDebug() << "lala";
}

void TestDialog::onPushButtonSHttp()
{
    DialogDownloadFile dlg(this);
    dlg.exec();
}
