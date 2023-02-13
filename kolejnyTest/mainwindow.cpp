#include "mainwindow.h"
#include "customslots.h"
#include <QGraphicsRectItem>
#include <QObject>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    CustomSlots *widgets = new CustomSlots;
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,280,240);
    view = new QGraphicsView(scene);
    setCentralWidget(view);
    QPushButton *addButton = new QPushButton("ADD",view);
    QRectF rect(0,0,80,40);
    DraggableRectItem* dItem = new DraggableRectItem;
    scene->addItem(dItem);
    dItem->setRect(rect);
    dItem->setPos(30,100);
    dItem->setBrush(QBrush(QColor("#ffa07a")));
    QObject::connect(addButton, &QPushButton::clicked, widgets, &CustomSlots::addNew());
}
