#include "qrightclickbutton.h"
//DEBUG
#include "QDebug"

QRightClickButton::QRightClickButton(QWidget *parent) :
    QPushButton(parent)
{
    timer = new QElapsedTimer();
    timer->start();
}

void QRightClickButton::mousePressEvent(QMouseEvent *e)
{
//qDebug()<<"Click on button detected";
    int ms_int =timer->restart();
    if (ms_int<250)
    {
        emit doubleClicked();
    }
    if(e->button()==Qt::RightButton)
        emit rightClicked();
    if(e->button()==Qt::LeftButton)
        emit clicked();

}

QRightClickButton::~QRightClickButton()
{
    delete timer;
}
