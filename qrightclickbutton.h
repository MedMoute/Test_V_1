#ifndef QRIGHTCLICKBUTTON_H
#define QRIGHTCLICKBUTTON_H

#include <QPushButton>
#include <QMouseEvent>
#include <QElapsedTimer>

class QRightClickButton : public QPushButton
{
    Q_OBJECT

public:
    explicit QRightClickButton(QWidget *parent = 0);
    ~QRightClickButton();
    QElapsedTimer* timer;

private:


public slots:
    void mousePressEvent(QMouseEvent *e) Q_DECL_OVERRIDE;

signals:
    void rightClicked();
    void doubleClicked();
};

#endif // QRIGHTCLICKBUTTON_H
