#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    QPen borderPen(Qt::black);
    borderPen.setWidth(1);
    QBrush blueBrush(Qt::blue);
    QBrush redBrush(Qt::red);
    rectItem = scene->addRect(0,0,200,100,borderPen,blueBrush);
    rectItem->setFlag(QGraphicsRectItem::ItemIsMovable);
    rectItem->setFlag(QGraphicsRectItem::ItemIsSelectable);
}


void MainWindow::on_pushButton_2_clicked()
{
    if(scene->items().count() != 0)
    {
        scene->removeItem(rectItem);
    }
}

