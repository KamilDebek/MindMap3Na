#include "selectioncolorbutton.h"

#include <QColorDialog>

SelectColorButton::SelectColorButton( QWidget* parent, QGraphicsRectItem *mainNode)
    : QPushButton(parent)
{
    colorItem = mainNode;
    connect( this, SIGNAL(clicked()), this, SLOT(changeColor()) );
}

void SelectColorButton::updateColor()
{
    setStyleSheet( "background-color: " + color.name() );
}

void SelectColorButton::changeColor()
{
    QColor newColor = QColorDialog::getColor(color, parentWidget());
    if ( newColor != color )
    {
        colorItem->setBrush(newColor);
        setColor( newColor );

    }

}

void SelectColorButton::setColor( const QColor& color )
{
    this->color = color;
    updateColor();
}

const QColor& SelectColorButton::getColor() const
{
    return color;
}
