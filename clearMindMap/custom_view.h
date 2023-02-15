#ifndef CUSTOM_VIEW_H
#define CUSTOM_VIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWheelEvent>
#include <QKeyEvent>
class Custom_View: public QGraphicsView
{
public:
    explicit Custom_View(QWidget *parent = nullptr);
    qreal panSpeed;
    qreal zoomDelta;
    void pan(QPointF delta);
    void zoom(float scaleFactor);
    void zoomIn();
    void zoomOut();
protected:
    virtual void wheelEvent(QWheelEvent *event) override;
    using QGraphicsView::QGraphicsView;
private:
    qreal _scale;
    bool _doMousePanning;
    bool _doKeyZoom;
};

#endif // CUSTOM_VIEW_H
