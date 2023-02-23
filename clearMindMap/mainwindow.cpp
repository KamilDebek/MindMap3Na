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
    QGraphicsTextItem *mainText = new QGraphicsTextItem("temat",mainNode);
    mainText->setTextInteractionFlags(Qt::TextEditable);
    mainText->setPos(20,10);
    mainText->setScale(2);
    if (mainText->toPlainText().length() > 10) {
        QFont font = mainText->font();
        font.setPointSize(10);
        mainText->setFont(font);
    }
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
    QGraphicsTextItem *nodeText = new QGraphicsTextItem("zagadnienie",rectItem);
    nodeText->setTextInteractionFlags(Qt::TextEditable);
    nodeText->setTextWidth(80);
    nodeText->setPos(20,30);
    nodeText->setScale(2);
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
        QGraphicsLineItem *line = new QGraphicsLineItem(itemsList[0]->pos().x(),itemsList[0]->pos().y(),itemsList[1]->pos().x(),itemsList[1]->pos().y());
        rectItem->setFlag(QGraphicsRectItem::ItemIsMovable, false);
        scene->addItem(line);
        line->setFlag(QGraphicsItem::ItemIsSelectable);
    }

}

