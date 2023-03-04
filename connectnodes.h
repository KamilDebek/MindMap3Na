#ifndef CONNECTNODES_H
#define CONNECTNODES_H

#include <QGraphicsScene>
#include <QList>
#include <QGraphicsItem>
#include <QGraphicsLineItem>
class ConnectNodes
{
public:
    ConnectNodes(QGraphicsScene *scene);
    void addLine();
private:
    QGraphicsScene *mainScene;
};

#endif // CONNECTNODES_H
