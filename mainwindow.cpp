#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cuadrado.h"
#include "tablero.h"
#include "QDebug"
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    :QGraphicsView(parent)
{
    qDebug()<<"entró al constructor\n";
    gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0,-50,1400,1000);
    setFixedSize(1400,900);//valor del witgets
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setScene(gameScene);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBackgroundBrush(brush);
    int tmp = width();
    qDebug()<<QString::number(tmp)+" valor del ancho\n";
    std::cout<<tmp+"..- valor\n";

}

MainWindow::~MainWindow()
{

}
void MainWindow::crearTablero()
{
    chess = new tablero();
    drawDeadHolder(0,50,QColor(255,255,255));//derecho
    drawDeadHolder(900,50,QColor(255,255,255));//izquierdo
    chess->dibujarCasillas(width()/2-400,50);

}

void MainWindow::drawDeadHolder(int x, int y,QColor color)
{
    //proporciona un elemento rectangular que puede agregar a QGraphicsScene
    deadHolder = new QGraphicsRectItem(x,y,300,850);//x, y, ancho ,alto
    QBrush brush;// define el patrón de relleno de las formas dibujadas por QPainter
    brush.setStyle(Qt::SolidPattern);//estilo del pincel
    brush.setColor(color);
    deadHolder->setBrush(brush);
    addScene(deadHolder);
}
void MainWindow::addScene(QGraphicsItem *item)
{
    gameScene->addItem(item);
}
