#ifndef CABALLO_H
#define CABALLO_H
#include "pieza.h"
#include "coordenada.h"

class caballo: public Pieza
{
public:
    caballo(QString team,QGraphicsItem *parent = 0);

    void setFigura();
    QList<Coordenada> movimientos();
};

#endif // CABALLO_H
