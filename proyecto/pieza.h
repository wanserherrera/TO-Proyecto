/**
  *@file pieza.h
  * @version 1.0
  * @author Luis Aliaga y Wanser Herrera
  * @tittle pieza_functions
  *
  */
#ifndef PIEZA_H
#define PIEZA_H
#include "coordenada.h"
#include <QGraphicsPixmapItem>
#include "cuadrado.h"
#include <QGraphicsSceneMouseEvent>
class cuadrado;
class Pieza :public QGraphicsPixmapItem
{
public:
    Pieza(QString team = "",QGraphicsItem *parent = 0);
    ~Pieza();
    void setCuadrado(cuadrado *cuadrado);
    cuadrado *getCuadrado();
    virtual void setFigura()=0;
    virtual QList<Coordenada> movimientos()=0;
    QString getColor();
    void setColor( QString _color);
    void setPos2(qreal a , qreal b);
    QString ficha;
protected:
    QString color;
    cuadrado *miCuadrado;
};

#endif // PIEZA_H
