#include "sdialog.h"
#include "ui_sdialog.h"
#include <QDesktopWidget>

SDialog::SDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SDialog)
{
    ui->setupUi(this);
    setBorderWidth(6);
    setTitleBarHeight(40);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint | Qt::Window);

    ui->toolButton_minSize->setIcon(style()->standardIcon(QStyle::SP_TitleBarMinButton));
    ui->toolButton_close->setIcon(style()->standardIcon(QStyle::SP_TitleBarCloseButton));
    ui->toolButton_resize->setIcon(style()->standardIcon(QStyle::SP_TitleBarMaxButton));

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
    ui->frame_leftBorder->setMinimumWidth(width);
    ui->frame_rightBorder->setMinimumWidth(width);
    ui->frame_topBorder->setMinimumHeight(width);
    ui->frame_botBorder->setMinimumHeight(width);
}

void SDialog::setBorderHidden(bool hide)
{
    ui->frame_leftBorder->setHidden(hide);
    ui->frame_rightBorder->setHidden(hide);
    ui->frame_topBorder->setHidden(hide);
    ui->frame_botBorder->setHidden(hide);
    ui->frame_topLeftBorder->setHidden(hide);
    ui->frame_topRightBorder->setHidden(hide);
    ui->frame_botLeftBorder->setHidden(hide);
    ui->frame_botRightBorder->setHidden(hide);
}

void SDialog::setTitleBarHeight(const int height)
{
    ui->frame_titleBar->setMinimumHeight(height);
}

int SDialog::getBorderWidth() const
{
    return ui->frame_leftBorder->width();
}

QFrame *SDialog::CentralFrame()
{
    return ui->frame_main;
}

bool SDialog::eventFilter(QObject *o, QEvent *e)
{
    if (e->type() == QEvent::WindowTitleChange)
    {
        ui->label_title->setText(windowTitle());
    }
    else if (e->type() == QEvent::WindowIconChange)
    {
        ui->toolButton_icon->setIcon(windowIcon());
    }
    else if (e->type() == QEvent::Resize)
    {
        if (isMaximized())
        {
            ui->toolButton_resize->setIcon(style()->standardIcon(QStyle::SP_TitleBarNormalButton));
            setBorderHidden(true);
        }
        else
        {
            ui->toolButton_resize->setIcon(style()->standardIcon(QStyle::SP_TitleBarMaxButton));
            setBorderHidden(false);
        }
    }
    return QDialog::eventFilter(o, e);
}

void SDialog::mousePressEvent(QMouseEvent *e)
{
    if (Qt::LeftButton != e->button())
        return;

    mLBtnOnPressing = true;
    mLBtnPressPos = e->pos();

    if (ui->frame_leftBorder->geometry().contains(mLBtnPressPos))
        mMousePressRegion = Left;
    else if (ui->frame_rightBorder->geometry().contains(mLBtnPressPos))
        mMousePressRegion = Right;
    else if (ui->frame_topBorder->geometry().contains(mLBtnPressPos))
        mMousePressRegion = Top;
    else if (ui->frame_botBorder->geometry().contains(mLBtnPressPos))
        mMousePressRegion = Bottom;
    else if (ui->frame_topLeftBorder->geometry().contains(mLBtnPressPos))
        mMousePressRegion = TopLeft;
    else if (ui->frame_topRightBorder->geometry().contains(mLBtnPressPos))
        mMousePressRegion = TopRight;
    else if (ui->frame_botLeftBorder->geometry().contains(mLBtnPressPos))
        mMousePressRegion = BotLeft;
    else if (ui->frame_botRightBorder->geometry().contains(mLBtnPressPos))
        mMousePressRegion = BotRight;
    else if (ui->frame_titleBar->geometry().contains(mLBtnPressPos))
        mMousePressRegion = TitleBar;
    else
        mMousePressRegion = Central;
}

void SDialog::mouseMoveEvent(QMouseEvent *e)
{
    if (!mLBtnOnPressing)
        return;

    // move dialog
    if (TitleBar == mMousePressRegion)
    {
        if (isMaximized())
            return;

        QDesktopWidget w;
        QPoint posMoveTo = e->globalPos() - mLBtnPressPos;
        if (posMoveTo.y() >= w.availableGeometry().bottom() - 40)
            posMoveTo.setY(w.availableGeometry().bottom() - 40);
        move(posMoveTo);
    }

    //resize dialog by dragging border
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
        mLBtnOnPressing = false;
}

void SDialog::on_toolButton_close_clicked()
{
    close();
}

void SDialog::on_toolButton_resize_clicked()
{
    if (isMaximized())
        showNormal();
    else
        showMaximized();
}

void SDialog::on_toolButton_minSize_clicked()
{
    showMinimized();
}
