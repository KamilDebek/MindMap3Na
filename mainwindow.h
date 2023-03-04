#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QtCore>
#include <QtGui>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QWheelEvent>
#include <QList>
#include <QMenu>
#include <QAction>
#include <QGraphicsTextItem>
#include <math.h>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QTabWidget>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QGraphicsLineItem>
#include <QFormLayout>
#include <vector>

#include "nodescolor.h"

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
    void deleteNode();
    void connectLines();
private slots:

    void on_actionAdd_triggered();
    void on_actionDelete_triggered();
    void on_actionConnect_triggered();

private:
    std::vector <int> linesVector;
    int lines = 0;
    QList <QGraphicsLineItem *> linesList;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    //QGraphicsRectItem *rectItem; Moved to addNode() function because
    // there is unnecessary
    QGraphicsRectItem *mainNode;
    QGraphicsLineItem *line;

};
#endif // MAINWINDOW_H
