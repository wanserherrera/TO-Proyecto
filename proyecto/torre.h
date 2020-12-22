#ifndef TORRE_H
#define TORRE_H
#include "pieza.h"
#include "coordenada.h"
class torre: public Pieza
{
public:
    torre(QString team,QGraphicsItem *parent = 0);
    void setFigura();
    QList<Coordenada> movimientos();
};

#endif // TORRE_H
