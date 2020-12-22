#ifndef PEON_H
#define PEON_H
#include "pieza.h"
#include "coordenada.h"
class Peon: public Pieza
{
public:
    Peon(QString team,QGraphicsItem *parent = 0);
    bool primerMov = true;
    void setFigura();
    QList<Coordenada> movimientos();
};

#endif // PEON_H
