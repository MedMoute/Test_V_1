#ifndef DOSPROMPT_H
#define DOSPROMPT_H

#include <QWidget>
#include "qrightclickbutton.h"
#include "qdraggablewindow.h"

namespace Ui {
class DOSPrompt;
}

class DOSPrompt : public QDraggableWindow
{
    Q_OBJECT

public:
    explicit DOSPrompt(QWidget *parent = 0,int pos=0);
    ~DOSPrompt();

    Ui::DOSPrompt* getUI(){return ui;}
    int getIDX(){return idx;}

    void InitHelp();
    void InitUpdating();
    void InitBatch();

private:
    Ui::DOSPrompt *ui;
    int idx;
};

#endif // DOSPROMPT_H
