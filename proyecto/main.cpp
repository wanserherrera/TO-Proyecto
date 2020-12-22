#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QDebug>
MainWindow *mainwindow;//ajedres
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainwindow = new MainWindow();
    mainwindow->setFixedSize(1200, 710);//ancho alto
    mainwindow->show();
    mainwindow->crearTablero();
    mainwindow->dibujarBorde();
    return a.exec();
}
