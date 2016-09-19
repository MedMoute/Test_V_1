//Qt
#include"QDrag"
#include "QMimeData"
//DEBUG
#include "QDebug"

#include "qcudesktopwidget.h"
#include "dosprompt.h"
#include "ui_dosprompt.h"


QCuDesktopWidget::QCuDesktopWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setAcceptDrops(true);
}

void QCuDesktopWidget::mousePressEvent(QMouseEvent *event)
{
    //qDebug()<<"Click on desktop detected";
    QDraggableWindow *child ;

    if (!childAt(event->pos())) //Clicked a free part of the desktop, nothing to grab
        return;

    if(childAt(event->pos())->parent()==this)
        child=dynamic_cast<QDraggableWindow*>(childAt(event->pos()));//Check if the "child" is ACTUALLY a DOSPrompt through dynamic_cast
    else
        child = static_cast<QDraggableWindow*>(childAt(event->pos()));

    if (!child)
        return;

    while(child->parent()!=this)//This will return the further showed widget in the hierarchy.
    {
        if(child->parent()->parent()==this)
            child=dynamic_cast<QDraggableWindow*>(child->parent());//Check if the "child" is ACTUALLY a DOSPrompt through dynamic_cast
        else
            child=static_cast<QDraggableWindow*>(child->parent());

        if(!child)//The first-gen widget is NOT a DOSPrompt
            return;
    }//Will stop at the first-generation child

    if(!child)
        return;
    child->raise();//Put the widget on top of the others

    //Reimplementing the mouse event so the drag of the prompt is enabled
    if(QRegion(child->SelectablePart).contains(event->pos()-child->pos()))
    {
        QDrag *drag = new QDrag(this);

        QByteArray itemData;
        QDataStream dataStream(&itemData, QIODevice::WriteOnly);
        dataStream << QPoint(event->pos() - child->pos())<<this->children().indexOf(child);

        QMimeData *mimeData = new QMimeData;
        mimeData->setData("application/x-dnditemdata", itemData);

        drag->setHotSpot(event->pos());
        drag->setMimeData(mimeData);

        if (drag->exec() )
        {
            this->show();
        }
    }

}

void QCuDesktopWidget::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
            QDataStream dataStream(&itemData, QIODevice::ReadOnly);
            QPoint offset;
            int idx;
            dataStream >> offset >> idx;

            static_cast<QDraggableWindow*>(this->children().at(idx))->move(event->pos() - offset);

            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void QCuDesktopWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void QCuDesktopWidget::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata"))
    {

        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);
        QPoint offset;
        int idx;
        dataStream >> offset >> idx;
        static_cast<QDraggableWindow*>(this->children().at(idx))->move(event->pos() - offset);
        this->show();

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    }
    else {
        event->ignore();
    }
}
