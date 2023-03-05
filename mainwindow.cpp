#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionAdd, &QAction::triggered, ui->graphicsView, &CustomView::newNode); // Connecting save action tp openFromFile()
    connect(ui->actionDelete, &QAction::triggered, ui->graphicsView, &CustomView::deleteNode);
    connect(ui->actionConnect, &QAction::triggered, ui->graphicsView, &CustomView::connectLines);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveToFile); // Connecting save action tp saveToFileFunction()
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openFromFile); // Connecting save action tp openFromFile()
    connect(ui->actionTo_png, &QAction::triggered, this, &MainWindow::toPngFile);

    connect(ui->graphicsView->scene, &QGraphicsScene::changed, ui->graphicsView, &CustomView::refreshLines);


    lastPath = QDir::rootPath();
}

MainWindow::~MainWindow()
{
    delete ui;
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
        QList <SquareNode *> squares = ui->graphicsView->squares();
        QList <ConnectLine *> lines = ui->graphicsView->lines();

        for(int i = 0; i < squares.count(); i++)
        {
            outStream << "Node ";
            outStream << QString::number(squares[i]->x()) + ' ';
            outStream << QString::number(squares[i]->y()) + ' ';
            outStream << squares[i]->brush().color().name() + ' ';
            outStream << squares[i]->lineEdit->text() + '\n';
        }

        for(int i = 0; i < lines.count(); i++)
        {
            outStream << "Line ";
            outStream << QString::number(squares.indexOf(lines[i]->firstNode)) + ' ';
            outStream << QString::number(squares.indexOf(lines[i]->secondNode)) + '\n';
        }

        saveFile.close();
    }
}

void MainWindow::openFromFile()
{


    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"),
                                                    lastPath,
                                                    tr("Save file (*.txt)"));
    if(fileName != "")
    {
        ui->graphicsView->clearScene();
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
                    ui->graphicsView->addNode(args[1].toDouble(), args[2].toDouble(), args[3], args[4]);
                }
                else if(args[0] == "Line")
                {
                    ui->graphicsView->addLine(ui->graphicsView->squares()[args[1].toInt()], ui->graphicsView->squares()[args[2].toInt()]);
                }
            }

            saveFile.close();
        }
    }
}

void MainWindow::toPngFile()
{
    QString fileName = QFileDialog::getExistingDirectory(this,
                                                        tr("Select Directory"),
                                                        lastPath);
    lastPath = fileName;

    QGraphicsScene *scene = ui->graphicsView->scene;
    fileName += "/scene.png";
    QImage image(scene->sceneRect().size().toSize(), QImage::Format_ARGB32);
    image.fill(Qt::white);
    QPainter painter(&image);
    scene->render(&painter);
    QImageWriter writer(fileName, "png");
    writer.write(image);
}

