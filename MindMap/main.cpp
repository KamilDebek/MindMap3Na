#include "mainwindow.h"

#include <QApplication>
#include <QWidget>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setStyleSheet("background-color: #393E46");
    w.showMaximized();
    return a.exec();
}
