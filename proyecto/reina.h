#ifndef REINA_H
#define REINA_H
#include "pieza.h"
#include "coordenada.h"
class reina: public Pieza
{
public:
    reina(QString team,QGraphicsItem *parent = 0);

    void setFigura();
    QList<Coordenada> movimientos();
};

#endif // REINA_H
