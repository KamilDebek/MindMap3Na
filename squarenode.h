#ifndef SQUARENODE_H
#define SQUARENODE_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPen>
#include <QBrush>
#include <QGraphicsProxyWidget>
#include <QGraphicsRectItem>

#include "nodescolor.h"

class SquareNode : public QGraphicsRectItem
{
public:
    SquareNode();
    ~SquareNode();
};

#endif // SQUARENODE_H
