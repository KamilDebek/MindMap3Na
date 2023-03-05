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
    connect(ui->graphicsView->scene(), &QGraphicsScene::changed, this, &MainWindow::refreshLines);
    connect(ui->actionTo_png, &QAction::triggered, this, &MainWindow::toPngFile);
    // Creating first node by function, not like before
    addNode();
    lastPath = QDir::rootPath();
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

        //itemsList[0]->setFlag(QGraphicsItem::ItemIsMovable, false);
        //itemsList[1]->setFlag(QGraphicsItem::ItemIsMovable, false);
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
    for(int i = 0; i < linesList.count(); i++)
    {
        if(linesList[i] != nullptr && (node == linesList[i]->firstNode || node == linesList[i]->secondNode))
        {
            delete linesList[i];
            linesList.removeAt(i);
            i = -1;
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

void MainWindow::saveToFile()
{
    QString fileName = QFileDialog::getExistingDirectory(this,
                                                        tr("Select Directory"),
                                                        lastPath);
    lastPath = fileName;

    QFile saveFile(fileName + "/jam.txt");
    if(saveFile.open(QIODevice::WriteOnly))
    {
        QTextStream outStream(&saveFile);

        for(int i = 0; i < squaresList.count(); i++)
        {
            outStream << "Node ";
            outStream << QString::number(squaresList[i]->x()) + ' ';
            outStream << QString::number(squaresList[i]->y()) + ' ';
            outStream << squaresList[i]->brush().color().name() + '\n';
        }

        for(int i = 0; i < linesList.count(); i++)
        {
            outStream << "Line ";
            outStream << QString::number(squaresList.indexOf(linesList[i]->firstNode)) + ' ';
            outStream << QString::number(squaresList.indexOf(linesList[i]->secondNode)) + '\n';
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

    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"),
                                                    lastPath,
                                                    tr("Save file (*.txt)"));
    lastPath = fileName;

    QFile saveFile(fileName);
    if(saveFile.open(QIODevice::ReadOnly))
    {
        QTextStream outStream(&saveFile);

        while(!outStream.atEnd())
        {
            QStringList args = outStream.readLine().split(' ');

            if(args[0] == "Node")
            {
                SquareNode *newNode = new SquareNode(args[1].toDouble(), args[2].toDouble(), args[3]);
                scene->addItem(newNode);
                squaresList.append(newNode);
            }
            else if(args[0] == "Line")
            {
                ConnectLine *line = new ConnectLine(squaresList[args[1].toInt()], squaresList[args[2].toInt()]);

                //squaresList[args[1].toInt()]->setFlag(QGraphicsItem::ItemIsMovable, false);
                //squaresList[args[2].toInt()]->setFlag(QGraphicsItem::ItemIsMovable, false);
                linesList.push_back(line);

                scene->addItem(line);
            }

        }

        saveFile.close();
    }
}

void MainWindow::toPngFile()
{
    QString fileName = QFileDialog::getExistingDirectory(this,
                                                        tr("Select Directory"),
                                                        lastPath);
    lastPath = fileName;

    QGraphicsScene *scene = ui->graphicsView->scene();
    fileName += "/scene.png"; // the output filename
    QImage image(scene->sceneRect().size().toSize(), QImage::Format_ARGB32);
    image.fill(Qt::white); // fill with transparent background
    QPainter painter(&image);
    scene->render(&painter);
    QImageWriter writer(fileName, "png");
    writer.write(image);
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

void MainWindow::refreshLines()
{
    for(int i = 0; i < linesList.count(); i++)
    {
        linesList[i]->refresh();
    }
}

