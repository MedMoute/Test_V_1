#ifndef EXPLORER_H
#define EXPLORER_H

#include <QWidget>
#include "qdraggablewindow.h"

namespace Ui {
class Explorer;
}

class Explorer : public QDraggableWindow
{
    Q_OBJECT

public:
    explicit Explorer(QWidget *parent = 0);
    ~Explorer();

    Ui::Explorer* getUI(){return ui;}
    void Init();

private:
    Ui::Explorer *ui;
};

#endif // EXPLORER_H
