#include "custom_view.h"

Custom_View::Custom_View(QWidget *parent) : QGraphicsView(parent)
{
    zoomDelta = 0.1;
    _scale = 1.0;
    panSpeed = 4;
}

//void Custom_View::pan(QPointF delta)
//{
//    delta *= _scale;
//    delta *= panSpeed;
//    setTransformationAnchor(AnchorUnderMouse);
//}

void Custom_View::zoom(float scaleFactor)
{
    scale(scaleFactor, scaleFactor);
    _scale *= scaleFactor;
}

void Custom_View::zoomIn()
{
    zoom(1 + zoomDelta);
}

void Custom_View::zoomOut()
{
    zoom (1 - zoomDelta);
}


void Custom_View::wheelEvent(QWheelEvent *event)
{
    QPoint scrollAmount = event->angleDelta();

    // Apply zoom.
    scrollAmount.y() > 0 ? zoomIn() : zoomOut();
}
