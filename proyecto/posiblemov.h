#ifndef POSIBLEMOV_H
#define POSIBLEMOV_H
#include "coordenada.h"
#include <QGraphicsPixmapItem>
class PosibleMov:public QGraphicsPixmapItem
{
public:
    PosibleMov(int b,QGraphicsItem *parent = 0);
    ~PosibleMov();

    void setFigura();
    int a;

};

#endif // POSIBLEMOV_H
