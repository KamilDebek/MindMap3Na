#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <QGraphicsLineItem>
#include <QLineF>

#include "nodescolor.h"
#include "squarenode.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class SelectColorButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void addNode();
    void deleteNode(QList <QGraphicsItem *> itemsList);
    void deleteLines(QList<QGraphicsLineItem*> lines);
    void connectLines();

private slots:

    void on_actionAdd_triggered();
    void on_actionDelete_triggered();
    void on_actionConnect_triggered();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QList <SquareNode *> squaresList;
    QList <QGraphicsLineItem *> linesList;

    QList<SquareNode*> graphicsItemToSquareNode(QList <QGraphicsItem *> itemsList);

};
#endif // MAINWINDOW_H
