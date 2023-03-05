#ifndef SQUARENODE_H
#define SQUARENODE_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPen>
#include <QBrush>
#include <QTextEdit>
#include <QGraphicsProxyWidget>
#include <QGraphicsRectItem>
#include <QList>
#include <QGraphicsLineItem>

#include "nodescolor.h"

class SquareNode : public QGraphicsRectItem
{

public:
    SquareNode(qreal posX = 0, qreal posY = 0, QColor color = Qt::blue);
    ~SquareNode();

    //QList<ConnectLine*> lines;
    //void addLine(ConnectLine* line);
};

#endif // SQUARENODE_H
