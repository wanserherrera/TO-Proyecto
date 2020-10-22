#ifndef CUADRADO_H
#define CUADRADO_H
#include <QGraphicsRectItem>
#include <QBrush>




class cuadrado:public QGraphicsRectItem
{
public:
    cuadrado(QGraphicsItem *parent=0) ;

    void setColor(QColor color);
    void setOriginalColor(QColor value);


    int fila;
    int columna;
private:
    QColor color;
    QString color_nombre;
    QBrush brush;
    QColor originalColor;
};

#endif // CUADRADO_H
