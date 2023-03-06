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
    this->setFlag(QGraphicsRectItem::ItemIsFocusable);
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

    lineEdit = new QLineEdit;
    lineEdit->setStyleSheet("background-color: rgba(255, 255, 255, 30); border: 1px solid black; border-radius: 5px;");
    lineEdit->setAlignment(Qt::AlignCenter);
    QGraphicsProxyWidget *lineEditProxy = new QGraphicsProxyWidget;
    lineEditProxy->setWidget(lineEdit);
    lineEditProxy->setParentItem(this);
    lineEditProxy->setPos(0, 30);
    lineEditProxy->setPreferredSize(180, 30);
    lineEditProxy->setContentsMargins(10,0,10,0);
    lineEdit->hide();
}

void SquareNode::focusInEvent(QFocusEvent *event)
{
    lineEdit->show();
}

void SquareNode::focusOutEvent(QFocusEvent *event)
{
    if (focusItem != lineEdit) lineEdit->hide();
}

