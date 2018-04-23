#ifndef DIALOGDOWNLOADFILE_H
#define DIALOGDOWNLOADFILE_H

#include <QDialog>
#include "shttp.h"

namespace Ui {
class DialogDownloadFile;
}

class DialogDownloadFile : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDownloadFile(QWidget *parent = 0);
    ~DialogDownloadFile();

private slots:
    void on_pushButton_selectDir_clicked();

    void on_pushButton_download_clicked();

private:
    Ui::DialogDownloadFile *ui;
    SHttp mHttp;
};

#endif // DIALOGDOWNLOADFILE_H
