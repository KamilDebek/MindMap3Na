#include "connectnodes.h"

ConnectNodes::ConnectNodes(QGraphicsScene *scene)
{
    mainScene = scene;
}

void ConnectNodes::addLine()
{
    if (mainScene->selectedItems().count() == 2)
    {
        QList <QGraphicsItem *> itemsList = mainScene->selectedItems();
        QPen linePen(Qt::black);
        linePen.setWidth(3);
        int startPosX = itemsList[0]->x();
        int startPosY = itemsList[0]->y();
        int endPosX = itemsList[1]->x();
        int endPosY = itemsList[1]->y();
        QGraphicsLineItem *line = new QGraphicsLineItem(startPosX,startPosY,endPosX,endPosY);
        line->setPen(linePen);
        mainScene->addItem(line);
        itemsList[0]->setFlag(QGraphicsItem::ItemIsMovable, false);
        itemsList[1]->setFlag(QGraphicsItem::ItemIsMovable, false);
    }
}
