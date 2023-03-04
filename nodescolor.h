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
    nodesColor(QGraphicsScene *scene, QGraphicsRectItem * parent);
    QBrush backgroundBrush;
public slots:
    void changeNodeColor();
private:
    QGraphicsScene *mainScene;
    QColor color;

    QGraphicsRectItem *node;

};

#endif // NODESCOLOR_H
