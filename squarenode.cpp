#include "squarenode.h"

SquareNode::SquareNode(qreal posX, qreal posY, QColor color)
    : QGraphicsRectItem(0,  0, 200, 100)
{
    QPen borderPen(Qt::transparent);
    borderPen.setWidth(2);
    QBrush blueBrush(color);
    this->setPen(borderPen);
    this->setBrush(blueBrush);
    this->setFlag(QGraphicsRectItem::ItemIsMovable);
    this->setFlag(QGraphicsRectItem::ItemIsSelectable);
    this->setFlag(QGraphicsRectItem::ItemIsFocusable);
    this->setZValue(1);
    this->setPos(posX, posY);

    nodeColor = new nodesColor(this);
    nodeColor->setGeometry(0, 0, 30, 30);
    nodeColor->setStyleSheet("background-color: rgba(255, 255, 255, 30); border: 2px solid black; border-radius: 15px;");
    //nodeColor->setText("Change Color");
    nodeColor->setIconSize(QSize(29, 29));
    nodeColor->setIcon(QIcon(QPixmap("assets/Color.png")));
    nodeColor->hide();
    colorProxy = new QGraphicsProxyWidget;
    colorProxy->setWidget(nodeColor);
    colorProxy->setParentItem(this);
    colorProxy->setZValue(2);
    colorProxy->setPos(205, 0);

    lineEdit = new QLineEdit;
    lineEdit->setStyleSheet("background-color: rgba(255, 255, 255, 0); border: 1px;");
    lineEdit->setAlignment(Qt::AlignCenter);
    QFont tmpFont = lineEdit->font();
    tmpFont.setPointSize(12);
    lineEdit->setFont(tmpFont);
    QGraphicsProxyWidget *lineEditProxy = new QGraphicsProxyWidget;
    lineEditProxy->setWidget(lineEdit);
    lineEditProxy->setParentItem(this);
    lineEditProxy->setPos(0, 30);
    lineEditProxy->setPreferredSize(180, 30);
    lineEditProxy->setContentsMargins(10,0,10,0);
}

void SquareNode::focusInEvent(QFocusEvent *event)
{
    nodeColor->show();
}

void SquareNode::focusOutEvent(QFocusEvent *event)
{
    if(this->focusItem() != colorProxy)
    {
        nodeColor->hide();
    }
}

