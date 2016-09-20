#ifndef QWINDOWSBAR_H
#define QWINDOWSBAR_H

#include <QFrame>

class QWindowsBar : public QFrame
{
    Q_OBJECT
public:
    explicit QWindowsBar(QWidget *parent = 0);

signals:

public slots:
    void mousePressEvent(QMouseEvent *e) Q_DECL_OVERRIDE;

};

#endif // QWINDOWSBAR_H
