#ifndef QDRAGGABLEWINDOW_H
#define QDRAGGABLEWINDOW_H

#include <QWidget>
#include <qrightclickbutton.h>

class QDraggableWindow : public QWidget
{
    Q_OBJECT
public:
    explicit QDraggableWindow(QWidget *parent = 0);
    ~QDraggableWindow();

    QRightClickButton* button;
    QRect SelectablePart;
private:

public slots:
    void closeprompt();
    void toggleprompt();

};

#endif // QDRAGGABLEWINDOW_H
