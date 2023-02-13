#ifndef DRAGGABLERECTITEM_H
#define DRAGGABLERECTITEM_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
class DraggableRectItem : public QGraphicsRectItem
{
public:
    DraggableRectItem(QGraphicsItem* parent = 0);
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    QPointF anchorPoint;
    bool m_dragged;
};

#endif // DRAGGABLERECTITEM_H
