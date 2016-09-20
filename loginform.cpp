#include "loginform.h"
#include "ui_loginform.h"
#include "mainwindow.h"


LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);

    this->move(300,220);
    //Setting up stylesheet from root to tree
    ui->Wrapper->setStyleSheet("QWidget { background-color : #d4d0c8; }");

    ui->lineEdit->setStyleSheet(" background-color : white; ");
    ui->lineEdit_2->setStyleSheet(" background-color : white; ");

    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_2->setInputMethodHints(Qt::ImhHiddenText| Qt::ImhNoPredictiveText|Qt::ImhNoAutoUppercase);

    ui->TopBar->setStyleSheet("QFrame { background-color : #17166d;color : white; }");

       QObject::connect(ui->pushButton_close,SIGNAL(clicked()),static_cast<MainWindow*>(this->parent()),SLOT(close()));
       QObject::connect(ui->pushButton_ok,SIGNAL(clicked()),this,SLOT(Ok_Clicked()));
       QObject::connect(ui->pushButton_cancel,SIGNAL(clicked()),this,SLOT(ClearFields()));
       QObject::connect(ui->pushButton_new,SIGNAL(clicked()),this,SLOT(NewUser()));

}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::Ok_Clicked()
{
    //TODO ckeck auth
    emit loggedin();
    this->close();
}

void LoginForm::ClearFields()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void LoginForm::NewUser()
{

}
