#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveToFile); // Connecting save action tp saveToFileFunction()
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openFromFile); // Connecting save action tp openFromFile()

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
        ConnectLine *line = new ConnectLine(itemsList[0], itemsList[1]);

        itemsList[0]->setFlag(QGraphicsItem::ItemIsMovable, false);
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
                deleteLines(squaresList[it]);
                delete squaresList[it];
                squaresList.removeAt(it);
            }
        }
    }
}

void MainWindow::deleteLines(SquareNode * node)
{
    QList <ConnectLine *> tmpList = linesList;
    for(int i = 0; i < linesList.count(); i++)
    {
        if(linesList[i] != nullptr && (node == linesList[i]->firstNode || node == linesList[i]->secondNode))
        {
            delete linesList[i];
            linesList[i] = nullptr;
            linesList.removeAt(i);
            i = -1;
        }
    }

    //for(int i = 0; i < linesList.count(); i++)
    //{
    //    if(linesList[i] == nullptr)
    //    {
    //        linesList.removeAt(i);
    //        i = 0;
    //    }
    //}
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

void MainWindow::saveToFile()
{
    QString fileName = "jam.txt";

    QFile saveFile(fileName);
    if(saveFile.open(QIODevice::WriteOnly))
    {
        QTextStream outStream(&saveFile);

        for(int i = 0; i < squaresList.count(); i++)
        {
            outStream << QString::number(squaresList[i]->x()) + ' ';
            outStream << QString::number(squaresList[i]->y()) + ' ';
            outStream << squaresList[i]->brush().color().name() + '\n';
        }

        saveFile.close();
    }
}

void MainWindow::openFromFile()
{
    qDeleteAll(squaresList);
    squaresList.clear();
    qDeleteAll(linesList);
    linesList.clear();

    QString fileName = "jam.txt";

    QFile saveFile(fileName);
    if(saveFile.open(QIODevice::ReadOnly))
    {
        QTextStream outStream(&saveFile);

        while(!outStream.atEnd())
        {
            QStringList args = outStream.readLine().split(' ');
            qDebug() << args;
            qDebug() << args[0].toDouble() << " " << args[1].toDouble();
            SquareNode *newNode = new SquareNode(args[0].toDouble(), args[1].toDouble(), args[2]);
            scene->addItem(newNode);
            squaresList.append(newNode);
        }

        saveFile.close();
    }
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

