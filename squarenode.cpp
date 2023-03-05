#include "squarenode.h"

SquareNode::SquareNode()
    : QGraphicsRectItem(0,0,200,100)
{
    QRectF rectOfProxy (0,0,40,20);
    QPen borderPen(Qt::black);
    borderPen.setWidth(2);
    QBrush blueBrush(Qt::blue);
    this->setPen(borderPen);
    this->setBrush(blueBrush);
    this->setFlag(QGraphicsRectItem::ItemIsMovable);
    this->setFlag(QGraphicsRectItem::ItemIsSelectable);
    this->setZValue(10);

    nodesColor *nodeColor = new nodesColor(this);
    nodeColor->setStyleSheet("background-color: rgba(255, 255, 255, 30); font-size: 10px;");
    nodeColor->setText("Change Color");
    QGraphicsProxyWidget *colorProxy = new QGraphicsProxyWidget;
    colorProxy->setWidget(nodeColor);
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

SquareNode::~SquareNode()
{
    for(int i = 0; i < lines.count(); i++)
        if(lines[i] != nullptr)
        {
            //delete lines[i];
            //lines[i] = nullptr;
        }
}

void SquareNode::addLine(QGraphicsLineItem *line)
{
    lines.push_back(line);
}
