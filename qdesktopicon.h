#ifndef QDESKTOPICON_H
#define QDESKTOPICON_H

#include <QWidget>
#include "qrightclickbutton.h"
#include <QLabel>

class QDesktopIcon : public QWidget
{
    Q_OBJECT
public:
    explicit QDesktopIcon(QWidget *parent = 0);
    ~QDesktopIcon();

    void Init(QString str,QString str2);
    void setIcon(QString);
    void setLabel(QString);

    QRightClickButton* getButton(){return button;}

private:
    QRightClickButton* button;
    QLabel* label;
    QPixmap* Buttonimg;

protected:

public slots:
    void mousePressEvent(QMouseEvent *e) Q_DECL_OVERRIDE;

signals:
    void rightClicked();
    void doubleClicked();
    void clicked();
};

#endif // QDESKTOPICON_H
