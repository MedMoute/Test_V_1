#include "dosprompt.h"
#include "ui_dosprompt.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
//Qt
#include<QTextDocument>
#include<QTextBlock>

//DEBUG
#include "QDebug"


DOSPrompt::DOSPrompt(QWidget *parent,int pos) :
    idx(pos),
    QDraggableWindow(parent),
    ui(new Ui::DOSPrompt)
{

    ui->setupUi(this);
    MainWindow* mw_ptr = static_cast<MainWindow*>(this->parent()->parent()->parent());
    //this(DraggableWindow)
    //  ->parent(CentralWidget)
    //      ->parent(MainWidget)
    //          ->parent(MainWindow)
    this->setGeometry((100+25*mw_ptr->getDOS().size())%parent->size().width(),(100+25*mw_ptr->getDOS().size())%parent->size().height(),this->size().width(),this->size().height());

    QPalette palette;
    QBrush clr(QColor(120,120,120));
    palette.setBrush(QPalette::Background,clr);
    this->setPalette(palette);

    QPalette palette_txt;
    QBrush clr_txt(QColor(0,0,0));
    palette_txt.setBrush(QPalette::Background,clr_txt);
    this->ui->text->setPalette(palette_txt);

    QPalette palette_top;
    QBrush clr_top(QColor(150,150,150));
    palette_top.setBrush(QPalette::Background,clr_top);
    this->ui->topbar->setPalette(palette_top);

    this->ui->label->setStyleSheet("QLabel { color : white; }");
    this->ui->label->setText("DDOS Prompt V 0.11.7");

    button->setText("DDOS Prompt V 0.11.7");
    button->setStyleSheet("Text-align:left");

    //Set up selectable part for dragging
    SelectablePart=ui->topbar->rect();

    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(closeprompt()));
    QObject::connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(hide()));
    QObject::connect(button,SIGNAL(clicked()),this,SLOT(toggleprompt()));
    QObject::connect(button,SIGNAL(rightClicked()),this,SLOT(toggleprompt()));
}

void DOSPrompt::InitBatch()
{
    qDebug()<<ui->textEdit->document()->blockCount();
    ui->textEdit->append(">DDOS Batch initializer....\n>");
    qDebug()<<ui->textEdit->document()->blockCount();
    ui->textEdit->append(">DDOS Batch initializer....\n>");
    qDebug()<<ui->textEdit->document()->blockCount();
    ui->textEdit->append(">DDOS Batch initializer....\nA\n>");
    qDebug()<<ui->textEdit->document()->blockCount();
    qDebug()<<ui->textEdit->document()->findBlockByNumber(2).text();
    ui->textEdit->update();
}

DOSPrompt::~DOSPrompt()
{
    delete ui;
}
