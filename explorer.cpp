#include "explorer.h"
#include "ui_explorer.h"
#include "mainwindow.h"

//DEBUG
#include "QDebug"


Explorer::Explorer(QWidget *parent) :
    QDraggableWindow(parent),
    ui(new Ui::Explorer)
{
    ui->setupUi(this);
    Init();

    //Set up selectable part for dragging
    SelectablePart=ui->TopBar->rect();

    button->setText("Explorer");
    button->setStyleSheet("Text-align:left");

    QObject::connect(ui->pushButton_close,SIGNAL(clicked()),this,SLOT(closeprompt()));
    QObject::connect(ui->pushButton_minimize,SIGNAL(clicked()),this,SLOT(hide()));
    QObject::connect(button,SIGNAL(clicked()),this,SLOT(toggleprompt()));
    QObject::connect(button,SIGNAL(rightClicked()),this,SLOT(toggleprompt()));
}

Explorer::~Explorer()
{
    delete ui;
}

void Explorer::Init()
{
    MainWindow* mw_ptr = static_cast<MainWindow*>(this->parent()->parent()->parent());
    //this(DraggableWindow)
    //  ->parent(CentralWidget)
    //      ->parent(MainWidget)
    //          ->parent(MainWindow)
    this->setGeometry((200+25*(this->parent()->children().size()-27))%(mw_ptr->size().width()),(100+25*(this->parent()->children().size()-27))%(mw_ptr->size().height()),this->size().width(),this->size().height());

    //Setting up stylesheet from root to tree
    ui->wrapper->setStyleSheet("QWidget { background-color : #d4d0c8; }");
    ui->TopPart->setStyleSheet("QFrame { background-color : #d4d0c8; }");

    ui->MainPart->setStyleSheet("QWidget { background-color : #d4d0c8; border-style: outset; border-width: 1px;border-color: grey; }");
    ui->TopBar->setStyleSheet("QFrame { background-color : #17166d;color : white; }");

    ui->pushButton_Edit->setStyleSheet("Text-align:left");
    ui->pushButton_File->setStyleSheet("Text-align:left");
    ui->pushButton_Tools->setStyleSheet("Text-align:left");
    ui->pushButton_View->setStyleSheet("Text-align:left");

    QFont font("MS Sans Serif",9);
    ui->label->setFont(font);
    ui->label_2->setFont(font);
    ui->label_3->setFont(font);

    ui->treeView->setStyleSheet("QWidget { background-color : white; }");
    ui->scrollAreaWidgetContents->setStyleSheet("QWidget { background-color : white; }");
}
