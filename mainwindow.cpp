#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    lines = 0;
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    QRectF rectOfProxy (0,0,40,20);
    ui->graphicsView->setScene(scene);
    QPen mainNodeBorderPen(Qt::black);
    mainNodeBorderPen.setWidth(2);
    QBrush redBrush(Qt::red);
    mainNode = scene->addRect(0,0,200,100,mainNodeBorderPen,redBrush);
    mainNode->setFlag(QGraphicsRectItem::ItemIsSelectable);
    mainNode->setZValue(10);
    nodesColor *nodeColor = new nodesColor(scene, mainNode);
    nodeColor->setStyleSheet("background-color: rgba(255, 255, 255, 30); font-size: 10px;");
    nodeColor->setText("Change Color");
    QGraphicsProxyWidget *colorProxy = new QGraphicsProxyWidget;
    colorProxy->setWidget(nodeColor);
    scene->addItem(colorProxy);
    colorProxy->setZValue(25);
    colorProxy->setParentItem(mainNode);
    colorProxy->setGeometry(rectOfProxy);
    colorProxy->setPos(125,0);
    QLineEdit *text = new QLineEdit;
    text->setStyleSheet("background-color: rgba(255, 255, 255, 30); border: 1px solid black; border-radius: 5px;");
    QGraphicsProxyWidget *lineEditProxy = new QGraphicsProxyWidget;
    lineEditProxy->setWidget(text);
    lineEditProxy->setParentItem(mainNode);
    lineEditProxy->setPos(0,45);
    text->setAlignment(Qt::AlignCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addNode()
{

    QRectF rectOfProxy (0,0,40,20);
    QPen borderPen(Qt::black);
    borderPen.setWidth(2);
    QBrush blueBrush(Qt::blue);
    rectItem = scene->addRect(0,0,200,100,borderPen,blueBrush);
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
    text->setAlignment(Qt::AlignCenter);
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
        if (scene->selectedItems().count() > 0)
        {
            QList <QGraphicsItem *> itemsList = scene->selectedItems();
            QGraphicsLineItem *newLine;
            for(int x = 0; x < itemsList.count(); x++)
            {
                if (itemsList[x] != mainNode)
                {
                    for (int l = 0; l < lines - 1; l++)
                    {
                        newLine = linesList[l];

                        if (newLine->line().p1() == itemsList[x]->pos() || newLine->line().p2() == itemsList[x]->pos())
                        {

                            delete linesList[l];
                            lines -= 1;
                            qDebug() << lines;
                            linesList.removeAt(l);
                        }


                    }
                    delete itemsList[x];
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

