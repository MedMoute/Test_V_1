#include "qwindowsbar.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

QWindowsBar::QWindowsBar(QWidget *parent) :
    QFrame(parent)
{

}
void QWindowsBar::mousePressEvent(QMouseEvent *e)
{
    //A click on the bar has been detected, the Start menu has to be hidden
    MainWindow* mw_ptr = static_cast<MainWindow*>(this->parent()->parent());
    //this(QWindowsBar)
    //      ->parent(MainWidget)
    //          ->parent(MainWindow)
    mw_ptr->getUI()->MenuBar->hide();
}
