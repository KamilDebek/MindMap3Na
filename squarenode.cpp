#include "squarenode.h"

SquareNode::SquareNode()
    : QGraphicsRectItem(0,0,200,100)
{
    QRectF rectOfProxy (0,0,40,20);
    QPen borderPen(Qt::black);
    borderPen.setWidth(2);
    QBrush blueBrush(Qt::blue);
    //QGraphicsRectItem *this = new QGraphicsRectItem(0,0,200,100);
    this->setPen(borderPen);
    this->setBrush(blueBrush);
    //scene->addItem(this);
    this->setFlag(QGraphicsRectItem::ItemIsMovable);
    this->setFlag(QGraphicsRectItem::ItemIsSelectable);
    this->setZValue(10);
    QGraphicsProxyWidget *colorProxy = new QGraphicsProxyWidget;
    nodesColor *nodeColor = new nodesColor(this);
    nodeColor->setStyleSheet("background-color: rgba(255, 255, 255, 30); font-size: 10px;");
    nodeColor->setText("Change Color");
    colorProxy->setWidget(nodeColor);
    //scene->addItem(colorProxy);
    colorProxy->setParentItem(this);
    colorProxy->setZValue(25);
    colorProxy->setGeometry(rectOfProxy);
    colorProxy->setPos(125,0);
    QLineEdit *text = new QLineEdit;
    text->setStyleSheet("background-color: rgba(255, 255, 255, 30); border: 1px solid black; border-radius: 5px;");
    QGraphicsProxyWidget *lineEditProxy = new QGraphicsProxyWidget;
    lineEditProxy->setWidget(text);
    lineEditProxy->setParentItem(this);
    lineEditProxy->setPos(0,30);
    lineEditProxy->setPreferredSize(180,30);
    lineEditProxy->setContentsMargins(10,0,10,0);
    text->setAlignment(Qt::AlignCenter);
}
