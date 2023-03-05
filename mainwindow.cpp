#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
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
    SquareNode *xd = new SquareNode;
    scene->addItem(xd);
    squaresList.push_back(xd);
}


void MainWindow::connectLines()
{
    if (scene->selectedItems().count() == 2)
    {
        QList <SquareNode *> itemsList = graphicsItemToSquareNode(scene->selectedItems());
        QPen linePen(Qt::black);
        linePen.setWidth(3);

        int startPosX = itemsList[0]->x();
        int startPosY = itemsList[0]->y();
        int endPosX = itemsList[1]->x();
        int endPosY = itemsList[1]->y();

        QGraphicsLineItem *line = new QGraphicsLineItem(startPosX,startPosY,endPosX,endPosY);
        itemsList[0]->addLine(line);
        itemsList[1]->addLine(line);
        linesList.push_back(line);
        line->setPen(linePen);
        scene->addItem(line);
        itemsList[0]->setFlag(QGraphicsItem::ItemIsMovable, false);
        itemsList[1]->setFlag(QGraphicsItem::ItemIsMovable, false);
    }
}

void MainWindow::deleteNode(QList <QGraphicsItem *> itemsList)
{  
    for(int i = 0; i < itemsList.count(); i++)
    {
        for(int it = 0; it < squaresList.count(); it++)
        {
            if(itemsList[i] == squaresList[it])
            {
                deleteLines(squaresList[it]->lines);
                delete squaresList[it];
                squaresList.removeAt(it);
            }
        }
    }
}

void MainWindow::deleteLines(QList<QGraphicsLineItem *> lines)
{
    for(int i = 0; i < lines.count(); i++)
    {
        QGraphicsLineItem *line = lines[i];
        if(linesList.contains(line))
        {
            qDebug() << "contains";
            int lIndex = linesList.indexOf(line);
            delete linesList[lIndex];
            linesList.removeAt(lIndex);
        }
    }
}


void MainWindow::on_actionAdd_triggered()
{
    addNode();
}

void MainWindow::on_actionDelete_triggered()
{
    if(scene->items().count() != 0)
        deleteNode(scene->selectedItems());
}

void MainWindow::on_actionConnect_triggered()
{
    connectLines();
}

QList<SquareNode *> MainWindow::graphicsItemToSquareNode(QList<QGraphicsItem *> itemsList)
{
    QList<SquareNode *> nodes;

    for(int i = 0; i < itemsList.count(); i++)
    {
        for(int it = 0; it < squaresList.count(); it++)
        {
            if(itemsList[i] == squaresList[it])
            {
                nodes.push_back(squaresList[it]);
            }
        }
    }

    return nodes;
}

