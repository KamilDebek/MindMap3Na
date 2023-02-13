#include "draggablerectitem.h"

DraggableRectItem::DraggableRectItem(QGraphicsItem* parent):
    QGraphicsRectItem(parent), m_dragged(false)
{
    setFlags(QGraphicsItem::ItemIsSelectable|
             QGraphicsItem::ItemIsMovable);
}

void DraggableRectItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    m_dragged = true;
    QGraphicsRectItem::mouseMoveEvent(event);
}

void DraggableRectItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    if(m_dragged) this->setPos(this->x(),this->y());

    m_dragged = false;

    QGraphicsRectItem::mouseReleaseEvent(event);
}
