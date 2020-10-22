#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMainWindow>
#include "tablero.h"
#include "cuadrado.h"
QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

class MainWindow :public QGraphicsView
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void crearTablero();
    void drawDeadHolder(int x, int y,QColor color);
    void addScene(QGraphicsItem *item);

    cuadrado *collection[9][9];

private:
    QGraphicsScene *gameScene;
    tablero *chess;
    QGraphicsRectItem * deadHolder;//proporciona un elemento rectangular que puede trabajr con a QGraphicsScene

};
#endif // MAINWINDOW_H
