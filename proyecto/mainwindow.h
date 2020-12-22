#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMainWindow>
#include "tablero.h"
#include "cuadrado.h"
#include "pieza.h"
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
    void dibujarBorde();
    QString getText();
    bool verificarJaque();
    void setText(QString text);
    cuadrado *collection[8][8];
    QList <Pieza *> piezaViva;
    Pieza *piezaSeleccionada;
    Pieza *reyWhite;
    Pieza *reyBlack;
    QString *turno;
    QString turnoA = "WHITE";
    QString turnoB = "BLACK";
    tablero *chess;
    QGraphicsTextItem *labelJaqueWhite;
    QGraphicsTextItem *labelJaqueBlack;
    void PiezaEliminada(Pieza *piece);
    int auxPiezaMuerta1=0;
    int auxPiezaMuerta2=0;
private:
    QString texto;
    QGraphicsScene *gameScene;

    QGraphicsRectItem * deadHolder;//proporciona un elemento rectangular que puede trabajr con a QGraphicsScene

};
#endif // MAINWINDOW_H
