#ifndef CUSTOMVIEW_H
#define CUSTOMVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWheelEvent>

#include "squarenode.h"
#include "connectline.h"

class CustomView: public QGraphicsView
{
    Q_OBJECT
public:
    explicit CustomView(QWidget *parent = nullptr);
    qreal zoomDelta;
    QGraphicsScene *scene;


    void zoom(float scaleFactor);
    void zoomIn();
    void zoomOut();

    void addNode(qreal x = 0, qreal y = 0, QColor color = "#fbd157", QString nText = "");
    void newNode();
    void addLine(SquareNode* fNode, SquareNode* sNode);
    void connectLines();
    void deleteNode();
    void deleteLines(SquareNode * node);
    void refreshLines();

    void clearScene();

    QList<SquareNode *> squares();
    QList<ConnectLine *> lines();

protected:
    virtual void wheelEvent(QWheelEvent *event) override;

private:
    QList <SquareNode *> squaresList;
    QList <ConnectLine *> linesList;
    qreal _scale;
    QList<SquareNode*> graphicsItemToSquareNode(QList <QGraphicsItem *> itemsList);
};

#endif // CUSTOMVIEW_H
