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
    void newWindow();
    void openFromFile();
    void saveAs();
    void saveToFile();    
    void exportImage(QString format);

private:
    Ui::MainWindow *ui;
    QString projectPath;
    QString lastPath;
};
#endif // MAINWINDOW_H
