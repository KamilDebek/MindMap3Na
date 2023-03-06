#include "connectline.h"

ConnectLine::ConnectLine(SquareNode *fNode,SquareNode *sNode)
    : QGraphicsLineItem(QLineF(fNode->pos() + fNode->rect().center(), sNode->pos() + sNode->rect().center()))
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
    this->setLine(QLineF(firstNode->pos() + firstNode->rect().center(), secondNode->pos() + secondNode->rect().center()));
}
