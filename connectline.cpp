#include "connectline.h"

ConnectLine::ConnectLine(SquareNode *fNode,SquareNode *sNode)
    : QGraphicsLineItem(QLineF(fNode->pos(), sNode->pos()))
{
    firstNode = fNode;
    secondNode = sNode;

    QPen linePen(Qt::black);
    linePen.setWidth(3);
    this->setPen(linePen);
}

ConnectLine::~ConnectLine() { }

void ConnectLine::deleteLine()
{
    delete this;
}

void ConnectLine::refresh()
{
    this->setLine(QLineF(firstNode->pos(), secondNode->pos()));
}
