#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);
    QPen mainNodeBorderPen(Qt::black);
    mainNodeBorderPen.setWidth(2);
    QBrush redBrush(Qt::red);
    mainNode = scene->addRect(0,0,200,100,mainNodeBorderPen,redBrush);
    mainNode->setFlag(QGraphicsRectItem::ItemIsSelectable);
    mainNode->setZValue(10);
    selectColor = new SelectColorButton(ui->centralwidget, mainNode);
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
    rectItem = scene->addRect(0,0,200,100,borderPen,blueBrush);
    rectItem->setFlag(QGraphicsRectItem::ItemIsMovable);
    rectItem->setFlag(QGraphicsRectItem::ItemIsSelectable);
    rectItem->setZValue(10);
}


void MainWindow::on_pushButton_2_clicked()
{

    if(scene->items().count() != 0)
    {
        if (scene->selectedItems().count() > 0)
        {
            QList <QGraphicsItem *> itemsList = scene->selectedItems();

            for(int x = 0; x < itemsList.count(); x++)
            {
                if (itemsList[x] == mainNode)
                {

                }
                else{ delete itemsList[x];}

            }
        }
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    if (scene->selectedItems().count() == 2)
    {
        QList <QGraphicsItem *> itemsList = scene->selectedItems();
        int startPointX = itemsList[0]->pos().x();
        int startPointY = itemsList[0]->pos().y();
        int endPointX = itemsList[1]->pos().x();
        int endPointY = itemsList[1]->pos().y();
        int dlugosc = abs(startPointX - endPointX);
        QPen borderPen(Qt::black);
        QBrush blackBrush(Qt::black);
        borderPen.setWidth(1);
        line = scene->addRect(startPointX,startPointY,dlugosc,2,borderPen,blackBrush);
    }

}

