#include "sdialog.h"
#include "ui_sdialog.h"
#include <QDesktopWidget>
#include <QFile>
#include <QDebug>

SDialog::SDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SDialog)
{
    ui->setupUi(this);
    setBorderWidth(6);
    setTitleBarHeight(40);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint | Qt::Window);

    ui->toolButton_minSizeDialog->setIcon(style()->standardIcon(QStyle::SP_TitleBarMinButton));
    ui->toolButton_closeDialog->setIcon(style()->standardIcon(QStyle::SP_TitleBarCloseButton));
    ui->toolButton_maxRestoreDialog->setIcon(style()->standardIcon(QStyle::SP_TitleBarMaxButton));

    installEventFilter(this);

    setWindowIcon(style()->standardIcon(QStyle::SP_DesktopIcon));
    setWindowTitle("My Custom Dialog");
}

SDialog::~SDialog()
{
    delete ui;
}

void SDialog::setBorderWidth(const int width)
{
    ui->widget_leftBorder->setMinimumWidth(width);
    ui->widget_rightBorder->setMinimumWidth(width);
    ui->widget_topBorder->setMinimumHeight(width);
    ui->widget_botBorder->setMinimumHeight(width);
}

void SDialog::setBordersHidden(bool hide)
{
    ui->widget_leftBorder->setHidden(hide);
    ui->widget_rightBorder->setHidden(hide);
    ui->widget_topBorder->setHidden(hide);
    ui->widget_botBorder->setHidden(hide);
    ui->widget_topLeftBorder->setHidden(hide);
    ui->widget_topRightBorder->setHidden(hide);
    ui->widget_botLeftBorder->setHidden(hide);
    ui->widget_botRightBorder->setHidden(hide);
}

void SDialog::setTitleBarHeight(const int height)
{
    ui->widget_dialogTitleBar->setMinimumHeight(height);
}

int SDialog::getBorderWidth() const
{
    return ui->widget_leftBorder->width();
}

QWidget *SDialog::clientWidget()
{
    return ui->widget_client;
}

bool SDialog::eventFilter(QObject *o, QEvent *e)
{
    if (e->type() == QEvent::WindowTitleChange)
    {
        ui->label_dialogTitle->setText(windowTitle());
    }
    else if (e->type() == QEvent::WindowIconChange)
    {
        ui->toolButton_dialogIcon->setIcon(windowIcon());
    }
    else if (e->type() == QEvent::Resize)
    {
        if (isMaximized())
        {
            ui->toolButton_maxRestoreDialog->setIcon(style()->standardIcon(QStyle::SP_TitleBarNormalButton));
            setBordersHidden(true);
        }
        else
        {
            ui->toolButton_maxRestoreDialog->setIcon(style()->standardIcon(QStyle::SP_TitleBarMaxButton));
            setBordersHidden(false);
        }
    }
    return QDialog::eventFilter(o, e);
}

void SDialog::mousePressEvent(QMouseEvent *e)
{
    if (Qt::LeftButton != e->button())
        return;

    mIsLBtnOnPressing = true;
    mLBtnPressPos = e->pos();

    if (ui->widget_leftBorder->geometry().contains(mLBtnPressPos))
        mMousePressRegion = Left;
    else if (ui->widget_rightBorder->geometry().contains(mLBtnPressPos))
        mMousePressRegion = Right;
    else if (ui->widget_topBorder->geometry().contains(mLBtnPressPos))
        mMousePressRegion = Top;
    else if (ui->widget_botBorder->geometry().contains(mLBtnPressPos))
        mMousePressRegion = Bottom;
    else if (ui->widget_topLeftBorder->geometry().contains(mLBtnPressPos))
        mMousePressRegion = TopLeft;
    else if (ui->widget_topRightBorder->geometry().contains(mLBtnPressPos))
        mMousePressRegion = TopRight;
    else if (ui->widget_botLeftBorder->geometry().contains(mLBtnPressPos))
        mMousePressRegion = BotLeft;
    else if (ui->widget_botRightBorder->geometry().contains(mLBtnPressPos))
        mMousePressRegion = BotRight;
    else if (ui->widget_dialogTitleBar->geometry().contains(mLBtnPressPos))
        mMousePressRegion = TitleBar;
    else
        mMousePressRegion = Central;
}

void SDialog::mouseMoveEvent(QMouseEvent *e)
{
    if (!mIsLBtnOnPressing)
        return;

    // move dialog
    if (TitleBar == mMousePressRegion)
    {
        if (isMaximized())
            return;

        QDesktopWidget w;
        QPoint posMoveTo = e->globalPos() - mLBtnPressPos;
        if (posMoveTo.y() >= w.availableGeometry().bottom() - 20)
            posMoveTo.setY(w.availableGeometry().bottom() - 20);
        move(posMoveTo);
    }

    // resize dialog by dragging border
    int w = getBorderWidth();
    if (Left == mMousePressRegion)
    {
        QRect r = geometry();
        r.setLeft(e->globalPos().x() - w);
        if (r.width() >= minimumWidth())
            setGeometry(r);
    }
    else if (Right == mMousePressRegion)
    {
        QRect r = geometry();
        r.setRight(e->globalPos().x() + w);
        if (r.width() >= minimumWidth())
            setGeometry(r);
    }
    else if (Top == mMousePressRegion)
    {
        QRect r = geometry();
        r.setTop(e->globalPos().y() - w);
        if (r.height() >= minimumHeight())
            setGeometry(r);
    }
    else if (Bottom == mMousePressRegion)
    {
        QRect r = geometry();
        r.setBottom(e->globalPos().y() + w);
        if (r.height() >= minimumHeight())
            setGeometry(r);
    }
    else if (TopLeft == mMousePressRegion)
    {
        QRect r = geometry();
        r.setTopLeft(e->globalPos() - QPoint(w, w));

        if (r.height() < minimumHeight())
            r.setTop(r.bottom() - minimumHeight());
        if (r.width() < minimumWidth())
            r.setLeft(r.right() - minimumWidth());
        setGeometry(r);
    }
    else if (TopRight == mMousePressRegion)
    {
        QRect r = geometry();
        r.setTopRight(e->globalPos() - QPoint(-w, w));

        if (r.height() < minimumHeight())
            r.setTop(r.bottom() - minimumHeight());
        if (r.width() < minimumWidth())
            r.setRight(r.left() + minimumWidth());
        setGeometry(r);
    }
    else if (BotLeft == mMousePressRegion)
    {
        QRect r = geometry();
        r.setBottomLeft(e->globalPos() - QPoint(w, -w));

        if (r.height() < minimumHeight())
            r.setBottom(r.top() + minimumHeight());
        if (r.width() < minimumWidth())
            r.setLeft(r.right() - minimumWidth());
        setGeometry(r);
    }
    else if (BotRight == mMousePressRegion)
    {
        QRect r = geometry();
        r.setBottomRight(e->globalPos() - QPoint(-w, -w));

        if (r.height() < minimumHeight())
            r.setBottom(r.top() + minimumHeight());
        if (r.width() < minimumWidth())
            r.setRight(r.left() + minimumWidth());
        setGeometry(r);
    }
}

void SDialog::mouseReleaseEvent(QMouseEvent *e)
{
    if (Qt::LeftButton == e->button())
        mIsLBtnOnPressing = false;
}

void SDialog::on_toolButton_closeDialog_clicked()
{
    close();
}

void SDialog::on_toolButton_maxRestoreDialog_clicked()
{
    if (isMaximized())
        showNormal();
    else
        showMaximized();
}

void SDialog::on_toolButton_minSizeDialog_clicked()
{
    showMinimized();
}
