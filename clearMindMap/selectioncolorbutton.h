#ifndef SELECTIONCOLORBUTTON_H
#define SELECTIONCOLORBUTTON_H


#include <QPushButton>
#include <QColor>
#include <mainwindow.h>
#include <QGraphicsRectItem>
class SelectColorButton : public QPushButton
{
    Q_OBJECT
public:
    SelectColorButton( QWidget* parent , QGraphicsRectItem * mainNode);
    bool changed = false;
    void setColor( const QColor& color );
    const QColor& getColor() const;
    QGraphicsRectItem *colorItem = 0;
public slots:
    void updateColor();
    void changeColor();

private:
    QColor color;
};

#endif // SELECTIONCOLORBUTTON_H
