#ifndef SDIALOG_H
#define SDIALOG_H

#include "sdialog_global.h"
#include <QDialog>
#include <QMouseEvent>
#include <QFrame>

namespace Ui {
class SDialog;
}

class SDIALOGSHARED_EXPORT SDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SDialog(QWidget *parent = 0);
    ~SDialog();

    //
    enum MousePressRegion
    {
        Left, Right, Top, Bottom,
        TopLeft, TopRight, BotLeft, BotRight, TitleBar, Central
    };

public slots:
    void setBorderWidth(const int width);
    void setBordersHidden(bool hide);
    void setTitleBarHeight(const int height);
    int getBorderWidth() const;
    QWidget *clientWidget();

protected:
    bool eventFilter(QObject *o, QEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private slots:
    void on_toolButton_closeDialog_clicked();
    void on_toolButton_maxRestoreDialog_clicked();
    void on_toolButton_minSizeDialog_clicked();

private:
    Ui::SDialog *ui;
    MousePressRegion mMousePressRegion;
    bool mIsLBtnOnPressing;
    QPoint mLBtnPressPos;

};

#endif // SDIALOG_H
