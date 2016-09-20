#include "qdesktopicon.h"
#include "QBitmap"
#include "qrightclickbutton.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

//DEBUG
#include "QDebug"
QDesktopIcon::QDesktopIcon(QWidget *parent) :
    QWidget(parent)
{
    button = new QRightClickButton(parent);
    Buttonimg = new QPixmap();
    label = new QLabel(parent);
}

void QDesktopIcon::Init(QString imgpath,QString txt)
{
    button->setGeometry(this->geometry().left()+this->geometry().width()*0.25,this->geometry().top()+this->geometry().height()*0.25,this->geometry().width()*0.5,this->geometry().height()*0.4);
    label->setGeometry(this->geometry().left(),this->geometry().top()+this->geometry().height()*0.7,this->geometry().width(),this->geometry().height()*0.2);

    this->setIcon(imgpath);
    this->setLabel(txt);
}

void QDesktopIcon::mousePressEvent(QMouseEvent *e)
{
    //A click on an icon has been detected, the Start menu has to be hidden
    MainWindow* mw_ptr = static_cast<MainWindow*>(this->parent()->parent()->parent());
    //this(QDesktopIcon)
    //  ->parent(CentralWidget)
    //      ->parent(MainWidget)
    //          ->parent(MainWindow)
    mw_ptr->getUI()->MenuBar->hide();

    int ms_int =button->timer->restart();
    if (ms_int<250)
    {
        emit doubleClicked();
    }
    if(e->button()==Qt::RightButton)
        emit rightClicked();
    if(e->button()==Qt::LeftButton)
        emit clicked();

}

QDesktopIcon::~QDesktopIcon()
{
    this->close();
}

void QDesktopIcon::setIcon(QString string)
{
    Buttonimg->load(string);
    button->setMask(Buttonimg->scaled(button->size()).mask());
    button->setStyleSheet("border-image:url("+string+");background-color: black;");
}

void QDesktopIcon::setLabel(QString string)
{
    label->setText(string);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("QLabel { color : white; }");
    QFont font("MS Sans Serif",9);
    label->setFont(font);
}

