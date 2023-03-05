#ifndef SQUARENODE_H
#define SQUARENODE_H

#include <QRectF>
#include <QPen>
#include <QBrush>
#include <QGraphicsProxyWidget>
#include <QGraphicsRectItem>

#include "nodescolor.h"

class SquareNode : public QGraphicsRectItem
{

public:
    SquareNode(qreal posX = 0, qreal posY = 0, QColor color = Qt::blue);
    ~SquareNode();

    QLineEdit *lineEdit;
};

#endif // SQUARENODE_H
