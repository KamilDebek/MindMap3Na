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
                delete itemsList[x];
            }
        }
    }
}

