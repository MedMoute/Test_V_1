//DEBUG
#include "QDebug"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTime"

#include <QMenu>

#include "explorer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //Setup greening background
    this->resize(1060, 630);
    QPixmap bckgrd ("./img1.png");
    background = bckgrd.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::FastTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Background,background);
    this->setPalette(palette);

    //Setup Intro screen w/ login

    login = new LoginForm(this);

    QObject::connect(login,SIGNAL(loggedin()),this,SLOT(LaunchMainWindow()));
}

MainWindow::~MainWindow()
{
    delete ui;
    while (dos.size()>0)
    {
        delete dos.front();
        dos.pop_front();
    }
}

void MainWindow::LaunchMainWindow()
{
    //Setup Main Screen
    ui->setupUi(this);

    //Init desktop icons
    ui->icon_help->Init("./icons/icon_24-0.png","Help");
    ui->icon_hintsfolder->Init("./icons/icon_5-0.png","Hints");
    ui->icon_notefolder->Init("./icons/icon_4-0.png","Notes");
    ui->icon_notepad->Init("./icons/icon_60-0.png","Notepad");
    ui->icon_system->Init("./icons/icon_36-0.png","System");
    ui->icon_todo->Init("./icons/icon_61-0.png","TODO.exe");
    ui->icon_trash->Init("./icons/icon_33-0.png","Recycle Bin");
    ui->icon_update->Init("./icons/icon_65-0.png","Updates");
    ui->icon_webchat->Init("./icons/icon_18-0.png","Webchat");

    //Init Start bar icons
    ui->pushButton_prog->setIcon(QIcon("./icons/icon_37-0.png"));
    ui->pushButton_docs->setIcon(QIcon("./icons/icon_5-0.png"));
    ui->pushButton_find->setIcon(QIcon("./icons/icon_44-0.png"));
    ui->pushButton_help->setIcon(QIcon("./icons/icon_24-0.png"));
    ui->pushButton_shut->setIcon(QIcon("./icons/icon_46-0.png"));
    ui->pushButton_run->setIcon(QIcon("./icons/icon_25-0.png"));
    ui->pushButton_sett->setIcon(QIcon("./icons/icon_36-0.png"));

    ui->pushButton_docs->setStyleSheet("Text-align:left");
    ui->pushButton_prog->setStyleSheet("Text-align:left");
    ui->pushButton_sett->setStyleSheet("Text-align:left");
    ui->pushButton_find->setStyleSheet("Text-align:left");
    ui->pushButton_run->setStyleSheet("Text-align:left");
    ui->pushButton_help->setStyleSheet("Text-align:left");
    ui->pushButton_shut->setStyleSheet("Text-align:left");

    ui->windows_bar->setStyleSheet("QFrame { background-color : white; }");
    ui->windows_bar->setWindowFlags(Qt::WindowStaysOnTopHint);

    ui->MenuBar->setStyleSheet("QWidget { background-color : #d4d0c8; }");
    ui->TextFrame->setStyleSheet("QFrame { background-color : grey ;color:white; }");
    //hide Starting menu at start
    ui->MenuBar->hide();

    ui->pushButton_start->setIcon(QIcon("./icons/shell32_40-1.png"));

    ui->timelabel->setText(QTime::currentTime().toString(Qt::SystemLocaleShortDate));

    QObject::connect(ui->icon_todo,SIGNAL(doubleClicked()),this,SLOT(startTODO()));
    QObject::connect(ui->icon_help,SIGNAL(doubleClicked()),this,SLOT(startHelp()));
    QObject::connect(ui->icon_update,SIGNAL(doubleClicked()),this,SLOT(startUpdating()));
//    QObject::connect(ui->icon_webchat->getButton(),SIGNAL(clicked()),this,SLOT(startIRC()));
//    QObject::connect(ui->icon_notepad->getButton(),SIGNAL(clicked()),this,SLOT(startNotepad()));
    QObject::connect(ui->icon_hintsfolder,SIGNAL(doubleClicked()),this,SLOT(startHintExplorer()));
//    QObject::connect(ui->icon_notefolder->getButton(),SIGNAL(clicked()),this,SLOT(startNotesExplorer()));
//    QObject::connect(ui->icon_trash->getButton(),SIGNAL(clicked()),this,SLOT(startRecycleExplorer()));
//    QObject::connect(ui->icon_system->getButton(),SIGNAL(clicked()),this,SLOT(startSystem()));
    QObject::connect(ui->pushButton_start,SIGNAL(clicked()),this,SLOT(toggleStartMenu()));
}

void MainWindow::startTODO()
{
    DOSPrompt* dos_ = new DOSPrompt(ui->centralWidget,dos.size()+1);
    dos.push_back(dos_);
    dos_->show();
    dos_->InitBatch();
}

void MainWindow::startHintExplorer()
{
    Explorer* exp = new Explorer(ui->centralWidget);
    exp->show();
}

void MainWindow::startHelp()
{
    qDebug()<<"Start Help";
}

void MainWindow::startUpdating()
{
    qDebug()<<"StartUpdating";
}

void MainWindow::toggleStartMenu()
{
    if (ui->MenuBar->isHidden())
    {
        ui->MenuBar->show();
    }
    else
    {
        ui->MenuBar->hide();
    }
}
