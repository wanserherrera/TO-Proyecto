/**
  *@file cuadrado.h
  * @version 1.0
  * @author Luis Aliaga y Wanser Herrera
  * @tittle pieza_functions
  * @brief clase que maneja los cuadrados del todo el tablero
  */
#ifndef CUADRADO_H
#define CUADRADO_H
#include <QGraphicsRectItem>
#include <QBrush>
#include <string>
#include "pieza.h"
#include "posiblemov.h"

class Pieza;
class cuadrado:public QGraphicsRectItem
{
public:
    cuadrado(QGraphicsItem *parent=0) ;
    void ubicacion(Pieza *piece);
    void ubicacion2(PosibleMov *itemm);
    /**
     * @brief setColor Establece el color del cuadrado del tablero
     * @param color El color propiamente dicho del tablero
     */
    void setColor(QColor color);
    /**
     * @brief setOriginalColor
     * @param value
     */
    void setOriginalColor(QColor value);
    /**
     * @brief setText
     * @param _texto
     */
    void setText(std::string _texto);
    Pieza *getVecino(int fil, int col);
    void MarcarCuadrado(cuadrado *box, int filaB, int columnaB);
    void estaOcupado(bool value, Pieza *piece=0);
    void setColorP(QString value);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void clearBoxes();
    void MoverFicha();
    void Matar();
    void sacarDeLista(Pieza *a);
    bool isEmpty();
    Pieza* cambiarPeon();
    int fila;
    int columna;
    Pieza *piezaa;
    PosibleMov *item;
    QString *eleccion;
    bool estado;// si esta en verdadero quiere decir ocupado, si esta en falso es porque esta libre
private:
    QString piezaColor;
    bool ocupado;
    std::string texto;
    QColor color;
    QString color_nombre;
    QBrush brush;
    QColor originalColor;

};

#endif // CUADRADO_H
