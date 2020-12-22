#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QDebug>
MainWindow *mainwindow;
int main(int argc, char *argv[])
{
    qDebug()<<"inició\n ";
    QApplication a(argc, argv);
    //qDebug()<<"entro\n ";
    mainwindow = new MainWindow();
    //qDebug()<<"empezó\n ";
    mainwindow->setFixedSize(1200, 710);//ancho alto
    mainwindow->show();
    mainwindow->crearTablero();
    mainwindow->dibujarBorde();
    return a.exec();
}
