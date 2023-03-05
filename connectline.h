#ifndef CONNECTLINE_H
#define CONNECTLINE_H

#include <QGraphicsLineItem>

#include "squarenode.h"

class ConnectLine : public QGraphicsLineItem
{
public:
    ConnectLine(SquareNode *fNode, SquareNode *sNode);
    ~ConnectLine();

    SquareNode *firstNode;
    SquareNode *secondNode;
    void refresh();
private:
    void deleteLine();

};

#endif // CONNECTLINE_H
