#ifndef NODESCOLOR_H
#define NODESCOLOR_H

#include <QPushButton>
#include <QGraphicsScene>
#include <QBrush>
#include <QPen>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QLineEdit>

class nodesColor: public QPushButton
{
    Q_OBJECT
public:
    nodesColor(QGraphicsRectItem * parent);
    QBrush backgroundBrush;
public slots:
    void changeNodeColor();
private:
    //QGraphicsScene *mainScene;
    QColor color;
    QGraphicsRectItem *par;
    QGraphicsRectItem *node;

};

#endif // NODESCOLOR_H
