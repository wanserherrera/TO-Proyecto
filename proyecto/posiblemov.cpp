#include "posiblemov.h"

PosibleMov::PosibleMov(int b,QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    a=b;
    setFigura();
}
void PosibleMov::setFigura(){
     this->setPixmap(QPixmap("://images/png_48/opciones2.png"));
}

PosibleMov::~PosibleMov(){
}
