#include "qdraggablewindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

QDraggableWindow::QDraggableWindow(QWidget *parent) :
    QWidget(parent)
{
    MainWindow* mw_ptr = static_cast<MainWindow*>(this->parent()->parent()->parent());
    //this(DraggableWindow)
    //  ->parent(CentralWidget)
    //      ->parent(MainWidget)
    //          ->parent(MainWindow)

    button = new QRightClickButton(mw_ptr);

    mw_ptr->getUI()->horizontalLayout_5->insertWidget(1,button);
    mw_ptr->getUI()->windows_bar->show();
}


void QDraggableWindow::closeprompt()
{
    button->hide();
    this->close();
}

void QDraggableWindow::toggleprompt()
{
    if (this->isHidden())
    {
        this->show();
    }
    else
    {
        this->hide();
    }

}

QDraggableWindow::~QDraggableWindow()
{
    delete button;
}
