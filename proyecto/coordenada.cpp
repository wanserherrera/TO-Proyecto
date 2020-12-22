#include "coordenada.h"
#include <QDebug>
Coordenada::Coordenada(int a, int b)
{
   col = a;
   fil = b;
   //qDebug()<<"Las coodenadas nuevas son: "+QString::number(fil)+"/"+QString::number(col);
}
