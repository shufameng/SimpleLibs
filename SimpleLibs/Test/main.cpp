#include "testdialog.h"
#include <QApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile qssFile("://qss_1.qss");
    if (!qssFile.open(QIODevice::ReadOnly))
    {
        qDebug() << qssFile.errorString();
    }
    a.setStyleSheet(qssFile.readAll());
    qssFile.close();

    TestDialog w;
    w.setWindowTitle(QString::fromLocal8Bit("测试窗口(TestDialog)"));
    w.show();

    return a.exec();
}
