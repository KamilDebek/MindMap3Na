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
#include "selectioncolorbutton.h"
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
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    SelectColorButton *selectColor;
    QGraphicsRectItem *rectItem;
    QGraphicsRectItem *mainNode;
};
#endif // MAINWINDOW_H
