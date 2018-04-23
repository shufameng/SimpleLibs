#include "dlgsupdater.h"
#include "ui_frmsupdater.h"
#include "threadsupdater.h"

DlgSUpdater::DlgSUpdater(QWidget *parent) :
    SDialog(parent),
    ui(new Ui::FrmSUpdater)
{
    ui->setupUi(CentralFrame());
}

DlgSUpdater::~DlgSUpdater()
{
    delete ui;
}

void DlgSUpdater::checkUpdate()
{
    ThreadSUpdater *pThread = new ThreadSUpdater();
    pThread->start();
}
