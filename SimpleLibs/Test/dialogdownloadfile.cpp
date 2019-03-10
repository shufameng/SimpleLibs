#include "dialogdownloadfile.h"
#include "ui_dialogdownloadfile.h"
#include <QFileDialog>


DialogDownloadFile::DialogDownloadFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDownloadFile)
{
    ui->setupUi(this);
}

DialogDownloadFile::~DialogDownloadFile()
{
    delete ui;
}

void DialogDownloadFile::on_pushButton_selectDir_clicked()
{
    ui->lineEdit_saveDirPath->setText(QFileDialog::getExistingDirectory(this));
}

void DialogDownloadFile::on_pushButton_download_clicked()
{
//    mHttp.setDownloadDir(QDir(ui->lineEdit_saveDirPath->text()));
//    if (mHttp.downloadFile(QUrl(ui->lineEdit_url->text())))
//    {
//        ui->label_downloadResult->setText("download finished: no error");
//    }
//    else
//    {
//        ui->label_downloadResult->setText(QString("download failed: %1").arg(mHttp.getDownloadErrorString()));
//    }
}
