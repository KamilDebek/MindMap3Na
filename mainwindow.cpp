#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Zakładka File
    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::newWindow);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openFromFile);
    connect(ui->actionSave_as, &QAction::triggered, this, &MainWindow::saveAs);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveToFile);
    connect(ui->actionPNG, &QAction::triggered, this, [=](){ exportImage("png"); });
    // Zakładka Edit
    connect(ui->actionAdd, &QAction::triggered, ui->graphicsView, &CustomView::newNode); // Connecting save action tp openFromFile()
    connect(ui->actionDelete, &QAction::triggered, ui->graphicsView, &CustomView::deleteNode);
    connect(ui->actionConnect, &QAction::triggered, ui->graphicsView, &CustomView::connectLines);

    // Refreshing lines
    connect(ui->graphicsView->scene, &QGraphicsScene::changed, ui->graphicsView, &CustomView::refreshLines);

    projectPath = "";
    lastPath = QDir::rootPath();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newWindow()
{
    MainWindow *newWin = new MainWindow();
    newWin->showMaximized();
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

bool MainWindow::saveAs()
{

    QString fileName = QFileDialog::getSaveFileName(this,
                                                        tr("Select Directory"),
                                                        lastPath);
    if (fileName == "") return 0;
    projectPath = fileName;
    lastPath = fileName;

    saveToFile();
    return 1;
}

void MainWindow::saveToFile()
{
    if(projectPath == "")
        if (saveAs() == 0) return;

    QFile saveFile(projectPath);
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


void MainWindow::exportImage(QString format)
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
    QImageWriter writer(fileName, format.toLatin1());
    writer.write(image);
}

