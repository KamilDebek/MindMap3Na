#include "customview.h"

CustomView::CustomView(QWidget *parent) : QGraphicsView(parent)
{
    scene = new QGraphicsScene(parent);
    this->setScene(scene);

    zoomDelta = 0.1;
    _scale = 1.0;
}

void CustomView::zoom(float scaleFactor)
{
    scale(scaleFactor, scaleFactor);
    _scale *= scaleFactor;
}

void CustomView::zoomIn()
{
    zoom(1 + zoomDelta);
}

void CustomView::zoomOut()
{
    zoom (1 - zoomDelta);
}


void CustomView::wheelEvent(QWheelEvent *event)
{
    QPoint scrollAmount = event->angleDelta();

    // Apply zoom.
    scrollAmount.y() > 0 ? zoomIn() : zoomOut();
}


void CustomView::addNode(qreal x, qreal y, QColor color, QString nText)
{
    SquareNode *newItem = new SquareNode(x, y, color);
    newItem->lineEdit->setText(nText);
    scene->addItem(newItem);
    squaresList.push_back(newItem);
}

void CustomView::newNode()
{
    addNode();
}

void CustomView::addLine(SquareNode *fNode, SquareNode *sNode)
{
    ConnectLine *line = new ConnectLine(fNode, sNode);
    scene->addItem(line);
    linesList.push_back(line);
}

void CustomView::connectLines()
{
    if (scene->selectedItems().count() == 2)
    {
        QList <SquareNode *> itemsList = graphicsItemToSquareNode(scene->selectedItems());
        ConnectLine *line = new ConnectLine(itemsList[0], itemsList[1]);

        //itemsList[0]->setFlag(QGraphicsItem::ItemIsMovable, false);
        //itemsList[1]->setFlag(QGraphicsItem::ItemIsMovable, false);
        linesList.push_back(line);

        scene->addItem(line);
    }
}

void CustomView::deleteNode()
{
    QList<QGraphicsItem *> itemsList = this->scene->selectedItems();
    for(int i = 0; i < itemsList.count(); i++)
    {
        for(int it = 0; it < squaresList.count(); it++)
        {
            if(itemsList[i] == squaresList[it])
            {
                deleteLines(squaresList[it]);
                delete squaresList[it];
                squaresList.removeAt(it);
            }
        }
    }
}

void CustomView::deleteLines(SquareNode *node)
{
    for(int i = 0; i < linesList.count(); i++)
    {
        if(linesList[i] != nullptr && (node == linesList[i]->firstNode || node == linesList[i]->secondNode))
        {
            delete linesList[i];
            linesList.removeAt(i);
            i = -1;
        }
    }
}

void CustomView::refreshLines()
{
    for(int i = 0; i < this->linesList.count(); i++)
    {
        this->linesList[i]->refresh();
    }
}

void CustomView::clearScene()
{
    qDeleteAll(squaresList);
    squaresList.clear();
    qDeleteAll(linesList);
    linesList.clear();
}


QList<SquareNode *> CustomView::squares()
{
    return squaresList;
}

QList<ConnectLine *> CustomView::lines()
{
    return linesList;
}


QList<SquareNode *> CustomView::graphicsItemToSquareNode(QList<QGraphicsItem *> itemsList)
{
    QList<SquareNode *> nodes;

    for(int i = 0; i < itemsList.count(); i++)
    {
        for(int it = 0; it < squaresList.count(); it++)
        {
            if(itemsList[i] == squaresList[it])
            {
                nodes.push_back(squaresList[it]);
            }
        }
    }

    return nodes;
}

