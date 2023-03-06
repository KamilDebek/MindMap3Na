#ifndef SQUARENODE_H
#define SQUARENODE_H

#include <QRectF>
#include <QPen>
#include <QBrush>
#include <QGraphicsProxyWidget>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

#include "nodescolor.h"

class SquareNode : public QGraphicsRectItem
{

public:
    SquareNode(qreal posX = 0, qreal posY = 0, QColor color = Qt::blue);
    QLineEdit *lineEdit;
protected:
//    virtual void focusOutEvent(QFocusEvent *event) override;
//    virtual void focusInEvent(QFocusEvent * event) override;
};

#endif // SQUARENODE_H
