#include "cuadrado.h"
#include <QDebug>
#include "mainwindow.h"
extern MainWindow *mainwindow;
cuadrado::cuadrado(QGraphicsItem *parent) :QGraphicsRectItem(parent)
{
     setRect(0,0,70,70);
     brush.setStyle(Qt::SolidPattern);
     setZValue(-1);
}

void cuadrado::setColor(QColor color)
{
    brush.setColor(color);
    setBrush(color);
}
void cuadrado::setOriginalColor(QColor value)
{
    originalColor = value;
    setColor(originalColor);
}
