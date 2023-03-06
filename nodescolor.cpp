#include "nodescolor.h"

#include <QColorDialog>
nodesColor::nodesColor(QGraphicsRectItem *parent)
{   
    connect( this, SIGNAL(clicked()), this, SLOT(changeNodeColor()) );
    //mainScene = scene;
    backgroundBrush.setColor(QColor(255,241,220));
    node = parent;
}

void nodesColor::changeNodeColor()
{
    QColor newColor = QColorDialog::getColor(color, parentWidget());

    if (newColor != color)
    {
       backgroundBrush.setColor(newColor);
       node->setBrush(newColor);
    }
}
