#include "torre.h"
#include <QDebug>
#include "coordenada.h"
torre::torre(QString team,QGraphicsItem *parent):Pieza(team,parent)
{
    setFigura();
}
void torre::setFigura(){

    if(color == "WHITE"){
        this->setPixmap(QPixmap("://images/png_48/torre1.png"));

    }else
        setPixmap(QPixmap("://images/png_48/torre.png"));
}
QList<Coordenada> torre::movimientos(){
    bool arriba = true;
    bool abajo = true;
    bool derecha = true;
    bool izquierda = true;
    QList<Coordenada> opciones;
    qDebug()<<"MOVER TORRE";
    int i = 1;
    while(i<8){
        if(arriba  && this->getCuadrado()->fila+i< 8){
            if(this->getCuadrado()->getVecino(this->getCuadrado()->fila+i,this->getCuadrado()->columna) == NULL){
                opciones.append(Coordenada(this->getCuadrado()->columna,this->getCuadrado()->fila+i));
            }else{
                if(getCuadrado()->getVecino(getCuadrado()->fila+i,getCuadrado()->columna)->getColor() == getColor())
                    arriba=false;
                else{
                    opciones.append(Coordenada(getCuadrado()->columna,getCuadrado()->fila+i));
                    arriba=false;
                }

            }
        }if(abajo  && this->getCuadrado()->fila-i >=0){
            if(getCuadrado()->getVecino(getCuadrado()->fila-i,getCuadrado()->columna)==NULL )
                opciones.append(Coordenada(getCuadrado()->columna,getCuadrado()->fila-i));
            else{
                if(getCuadrado()->getVecino(getCuadrado()->fila-i,getCuadrado()->columna)->getColor() == getColor()){
                    abajo=false;
                 }else{
                    opciones.append(Coordenada(getCuadrado()->columna,getCuadrado()->fila-i));
                    abajo=false;
                }

            }
        }if(derecha && getCuadrado()->columna+i<8){
            if(getCuadrado()->getVecino(getCuadrado()->fila,getCuadrado()->columna+i)==NULL){
                opciones.append(Coordenada(getCuadrado()->columna+i,getCuadrado()->fila));
            }else{
                if(getCuadrado()->getVecino(getCuadrado()->fila,getCuadrado()->columna+i)->getColor() == getColor()){
                    derecha=false;
                 }else{
                    opciones.append(Coordenada(getCuadrado()->columna+i,getCuadrado()->fila));
                    derecha=false;
                }

            }
        }
        if(izquierda  && getCuadrado()->columna-i>=0){
                    if(getCuadrado()->getVecino(getCuadrado()->fila,getCuadrado()->columna-i)==NULL)
                        opciones.append(Coordenada(getCuadrado()->columna-i,getCuadrado()->fila));
                    else{
                        if(getCuadrado()->getVecino(getCuadrado()->fila,getCuadrado()->columna-i)->getColor() == getColor()){
                            izquierda=false;
                         }else{
                            opciones.append(Coordenada(getCuadrado()->columna-i,getCuadrado()->fila));
                            izquierda=false;
                        }
                    }
                }
       i++;
    }
    return opciones;
}
//problemas en el else, varificar cuando se sale de la pantalla
