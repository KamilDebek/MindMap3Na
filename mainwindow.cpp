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
    SquareNode *newItem = new SquareNode;
    scene->addItem(newItem);
    squaresList.push_back(newItem);
}


void MainWindow::connectLines()
{
    if (scene->selectedItems().count() == 2)
    {
        QList <SquareNode *> itemsList = graphicsItemToSquareNode(scene->selectedItems());

        QGraphicsLineItem *line = new QGraphicsLineItem(QLineF(itemsList[0]->pos(),itemsList[1]->pos()));
        QPen linePen(Qt::black);
        linePen.setWidth(3);
        line->setPen(linePen);

        itemsList[0]->addLine(line);
        itemsList[0]->setFlag(QGraphicsItem::ItemIsMovable, false);
        itemsList[1]->addLine(line);
        itemsList[1]->setFlag(QGraphicsItem::ItemIsMovable, false);
        linesList.push_back(line);

        scene->addItem(line);
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

