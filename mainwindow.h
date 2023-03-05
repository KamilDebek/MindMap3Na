#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <QFileDialog>
#include <QFile>
#include <QImageWriter>

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

private slots:
    void saveToFile();
    void openFromFile();
    void toPngFile();

private:
    Ui::MainWindow *ui;
    QString lastPath;
};
#endif // MAINWINDOW_H
