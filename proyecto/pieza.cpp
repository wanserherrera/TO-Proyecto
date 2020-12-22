#include "pieza.h"
#include "cuadrado.h"


Pieza::Pieza(QString team,QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    color = team;
}
Pieza::~Pieza(){
    //delete miCuadrado;
}

QString Pieza::getColor()
{
    return color;
}

void Pieza::setColor( QString _color)
{
    color = _color;
}
void Pieza::setCuadrado(cuadrado *cuadrado)
{

    miCuadrado = cuadrado;
}

void Pieza::setPos2(qreal a , qreal b){
    setPos(a,b);
}
cuadrado *Pieza::getCuadrado(){
    return miCuadrado;
}
