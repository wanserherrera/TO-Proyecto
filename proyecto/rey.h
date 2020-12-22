#ifndef REY_H
#define REY_H
#include "pieza.h"
#include "coordenada.h"
class rey: public Pieza
{
public:
    rey(QString team,QGraphicsItem *parent = 0);

    void setFigura();
    QList<Coordenada> movimientos();
};

#endif // REY_H
