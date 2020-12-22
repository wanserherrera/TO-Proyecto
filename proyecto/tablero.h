#ifndef TABLERO_H
#define TABLERO_H
#include <QGraphicsRectItem>
#include "pieza.h"

class tablero
{
public:
    tablero();
    void dibujarBorde();
    void crearTablero(int x, int y);
    void dibujarCasillas(int x,int y);
    void addPieza();
    void setUpBlack();
    void setUpWhite();
    QList <Pieza *> white;
    QList <Pieza *> black;
    QList <Pieza *> whiteD;
    QList <Pieza *> blackD;
};

#endif // TABLERO_H
