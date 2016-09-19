#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dosprompt.h"
#include "loginform.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow* getUI(){return ui;}
    std::list<DOSPrompt*> getDOS(){return dos;}

    LoginForm* login;

private:
    Ui::MainWindow *ui;
    QPixmap background;
    std::list<DOSPrompt*> dos;

public slots:
    void startTODO();
    void startHelp();
    void startUpdating();
//    void startIRC();
//    void startNotepad();
    void startHintExplorer();
//    void startNotesExplorer();
//    void startRecycleExplorer();
//    void startSystem();
    void LaunchMainWindow();

};

#endif // MAINWINDOW_H
