#ifndef ALFIL_H
#define ALFIL_H
#include "pieza.h"
#include "coordenada.h"
class alfil: public Pieza
{
public:
    alfil(QString team,QGraphicsItem *parent = 0);
    void setFigura();
    QList<Coordenada> movimientos();
};

#endif // ALFIL_H
