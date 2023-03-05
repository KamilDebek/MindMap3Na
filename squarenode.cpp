#include "squarenode.h"

SquareNode::SquareNode(qreal posX, qreal posY, QColor color)
    : QGraphicsRectItem(0,  0, 200, 100)
{
    QPen borderPen(Qt::black);
    borderPen.setWidth(2);
    QBrush blueBrush(color);
    this->setPen(borderPen);
    this->setBrush(blueBrush);
    this->setFlag(QGraphicsRectItem::ItemIsMovable);
    this->setFlag(QGraphicsRectItem::ItemIsSelectable);
    this->setZValue(1);
    this->setPos(posX, posY);

    nodesColor *nodeColor = new nodesColor(this);
    nodeColor->setStyleSheet("background-color: rgba(255, 255, 255, 30); font-size: 10px;");
    nodeColor->setText("Change Color");
    QGraphicsProxyWidget *colorProxy = new QGraphicsProxyWidget;
    colorProxy->setWidget(nodeColor);
    colorProxy->setParentItem(this);
    colorProxy->setZValue(2);
    colorProxy->setPos(125, 0);

    QLineEdit *text = new QLineEdit;
    text->setStyleSheet("background-color: rgba(255, 255, 255, 30); border: 1px solid black; border-radius: 5px;");
    QGraphicsProxyWidget *lineEditProxy = new QGraphicsProxyWidget;
    lineEditProxy->setWidget(text);
    lineEditProxy->setParentItem(this);
    lineEditProxy->setPos(0, 30);
    lineEditProxy->setPreferredSize(180, 30);
    lineEditProxy->setContentsMargins(10,0,10,0);
    text->setAlignment(Qt::AlignCenter);
}

SquareNode::~SquareNode(){}

void SquareNode::addLine(QGraphicsLineItem *line)
{
    lines.push_back(line);
}
