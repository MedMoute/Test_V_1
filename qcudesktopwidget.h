#ifndef QCUDESKTOPWIDGET_H
#define QCUDESKTOPWIDGET_H

#include <QWidget>

class QCuDesktopWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QCuDesktopWidget(QWidget *parent = 0);


protected:
    void dragEnterEvent(QDragEnterEvent *event)Q_DECL_OVERRIDE;
    void dragMoveEvent(QDragMoveEvent *event)Q_DECL_OVERRIDE;
    void dropEvent(QDropEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

signals:

public slots:

};

#endif // QDESKTOPWIDGET_H
