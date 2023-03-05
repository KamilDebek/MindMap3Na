#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    lines = 0;
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    // Creating first node by function, not like before
    addNode();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addNode()
{
    /*QRectF rectOfProxy (0,0,40,20);
    QPen borderPen(Qt::black);
    borderPen.setWidth(2);
    QBrush blueBrush(Qt::blue);
    QGraphicsRectItem *rectItem = new QGraphicsRectItem(0,0,200,100);
    rectItem->setPen(borderPen);
    rectItem->setBrush(blueBrush);
    scene->addItem(rectItem);
    rectItem->setFlag(QGraphicsRectItem::ItemIsMovable);
    rectItem->setFlag(QGraphicsRectItem::ItemIsSelectable);
    rectItem->setZValue(10);
    QGraphicsProxyWidget *colorProxy = new QGraphicsProxyWidget;
    nodesColor *nodeColor = new nodesColor(scene, rectItem);
    nodeColor->setStyleSheet("background-color: rgba(255, 255, 255, 30); font-size: 10px;");
    nodeColor->setText("Change Color");
    colorProxy->setWidget(nodeColor);
    scene->addItem(colorProxy);
    colorProxy->setParentItem(rectItem);
    colorProxy->setZValue(25);
    colorProxy->setGeometry(rectOfProxy);
    colorProxy->setPos(125,0);
    QLineEdit *text = new QLineEdit;
    text->setStyleSheet("background-color: rgba(255, 255, 255, 30); border: 1px solid black; border-radius: 5px;");
    QGraphicsProxyWidget *lineEditProxy = new QGraphicsProxyWidget;
    lineEditProxy->setWidget(text);
    lineEditProxy->setParentItem(rectItem);
    lineEditProxy->setPos(0,30);
    lineEditProxy->setPreferredSize(180,30);
    lineEditProxy->setContentsMargins(10,0,10,0);
    text->setAlignment(Qt::AlignCenter);*/
    SquareNode *xd = new SquareNode;
    scene->addItem(xd);
    squaresList.push_back(xd);
}



void MainWindow::connectLines()
{
    if (scene->selectedItems().count() == 2)
    {
        QList <QGraphicsItem *> itemsList = scene->selectedItems();
        QPen linePen(Qt::black);
        linePen.setWidth(3);
        int startPosX = itemsList[0]->x();
        int startPosY = itemsList[0]->y();
        int endPosX = itemsList[1]->x();
        int endPosY = itemsList[1]->y();
        line = new QGraphicsLineItem(startPosX,startPosY,endPosX,endPosY);
        line->setPen(linePen);
        scene->addItem(line);
        itemsList[0]->setFlag(QGraphicsItem::ItemIsMovable, false);
        itemsList[1]->setFlag(QGraphicsItem::ItemIsMovable, false);
        lines += 1;
        linesList.push_back(line);

    }
}
void MainWindow::deleteNode()
{
    if(scene->items().count() != 0)
    {
        QList <QGraphicsItem *> itemsList = scene->selectedItems();
        QGraphicsLineItem *newLine;

        for(int i = 0; i < itemsList.count(); i++)
        {
            for(int it = 0; it < squaresList.count(); it++)
            {
                if(itemsList[i] == squaresList[it])
                {
                    delete squaresList[it];
                    //delete itemsList[it];
                    squaresList.removeAt(it);
                }
            }
        }
    }
}
void MainWindow::on_actionAdd_triggered()
{
    addNode();
}


void MainWindow::on_actionDelete_triggered()
{
    deleteNode();
}


void MainWindow::on_actionConnect_triggered()
{
    connectLines();
}

