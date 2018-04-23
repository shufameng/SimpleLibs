#ifndef DLGSUPDATER_H
#define DLGSUPDATER_H

#include "supdater_global.h"
#include "sdialog.h"

namespace Ui {
class FrmSUpdater;
}

class SUPDATERSHARED_EXPORT DlgSUpdater : public SDialog
{
    Q_OBJECT

public:
    explicit DlgSUpdater(QWidget *parent = 0);
    ~DlgSUpdater();

public slots:
    void checkUpdate();

private:
    Ui::FrmSUpdater *ui;
};

#endif // DLGSUPDATER_H
