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
    mainwindow->setFixedSize(1350, 900);
    mainwindow->show();
    mainwindow->crearTablero();
    return a.exec();
}
