#include "cuadrado.h"
#include <QDebug>
#include "mainwindow.h"
#include "tablero.h"
#include "pieza.h"
#include "peon.h"
#include "torre.h"
#include "alfil.h"
#include "reina.h"
#include "caballo.h"
#include <string>
#include "posiblemov.h"
#include "./ui_elejirficha.h"
#include "elejirficha.h"
extern MainWindow *mainwindow;

cuadrado::cuadrado(QGraphicsItem *parent) :QGraphicsRectItem(parent)
{
     setRect(0,0,70,70);
     brush.setStyle(Qt::SolidPattern);
     setZValue(-1);
     setColorP("NONE");
     estaOcupado(false);
     piezaa =  NULL;
     item = NULL;
     estado = false;
     mainwindow->setText("asdasd");
     eleccion = new QString("asd");

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

void cuadrado::setText(std::string _texto){
    texto = _texto;
}

void cuadrado::ubicacion(Pieza *piece){

    if(piece->ficha == "peon" && (fila == 0 || fila == 7)){
        elejirficha guiR;
        guiR.setModal(true);
        guiR.setEleccion(eleccion);
        guiR.exec();
        if(mainwindow->piezaSeleccionada->getColor()=="WHITE"){
            //Pieza *tmp = piezaa;
            Pieza *a =piece;
            if(*eleccion == "torre"){
                piece = new torre("WHITE");
            }else if(*eleccion =="reina"){
                piece = new reina("WHITE");
            }else if(*eleccion=="alfil"){
                piece = new alfil("WHITE");
            }else if(*eleccion =="caballo"){
                piece = new caballo("WHITE");
            }
            mainwindow->addScene(piece);
            mainwindow->chess->white.append(piece);
            mainwindow->chess->white.removeOne(a);
            delete(a);//eliminar la pieza victimada----------
        }else {
            //Pieza *tmp = piezaa;
            Pieza *a =piece;
            if(*eleccion == "torre"){
                piece = new torre("BLACK");
            }else if(*eleccion =="reina"){
                piece = new reina("BLACK");
            }else if(*eleccion=="alfil"){
                piece = new alfil("BLACK");
            }else if(*eleccion =="caballo"){
                piece = new caballo("BLACK");
            }
            mainwindow->addScene(piece);
            mainwindow->chess->black.append(piece);
            mainwindow->chess->black.removeOne(a);
            delete(a);//eliminar la pieza victimada----------
        }

    }


    //qDebug()<<piece->pixmap().width()/2;
    piece->setPos(x()+35 -piece->pixmap().width()/2  ,y()+30- piece->pixmap().width()/2 );//evaluar
    //piece->setPos(x()+50 -piece->pixmap().width()/2  ,y()+50- piece->pixmap().width()/2 );//evaluar
    piece->setCuadrado(this);
    estaOcupado(true,piece);
    piezaa = piece;
    estado = true;
}


void cuadrado::ubicacion2(PosibleMov *itemm){


    qDebug()<<itemm->pixmap().width()/2;
        itemm->setPos(x()+35 -itemm->pixmap().width()/2  ,y()+30- itemm->pixmap().width()/2 );//evaluar
        item = itemm;

    //piece->setPos(x()+50 -piece->pixmap().width()/2  ,y()+50- piece->pixmap().width()/2 );//evaluar

}

void cuadrado::estaOcupado(bool value, Pieza *piece)
{
    ocupado = value;
    if(value)
        setColorP(piece->getColor());
    else
        setColorP("NONE");
}
void cuadrado::setColorP(QString value)
{
    piezaColor = value;
}
Pieza *cuadrado::getVecino(int fil, int col){
    if(col<8 && col>=0 && fil>=0 && fil<8){
        return mainwindow->collection[fil][col]->piezaa;
    }else
        return NULL;//dar opcion de movimiento
}
void cuadrado::mousePressEvent(QGraphicsSceneMouseEvent *event){
    int columnaB, filaB;


    if((piezaa != NULL && mainwindow->turno == piezaa->getColor())|| item != NULL){//validar que el cuadrado tenga una pieza

        qDebug()<<(mainwindow->piezaSeleccionada == NULL);

        if(mainwindow->piezaSeleccionada == NULL){//en caso sea la primera vez que
            clearBoxes();
            qDebug()<<"ENTRO funciton: "  ;
            QList<Coordenada> opciones;
            if(estado){//verificar si existe ficha en el cuadrado clickeado
                mainwindow->piezaSeleccionada = piezaa;
                opciones = piezaa->movimientos();
                for(int i = 0; i < opciones.size(); ++i){//mostrar las opciones de mov
                  columnaB = opciones.at(i).col;
                  filaB = opciones.at(i).fil;
                  cuadrado *box =mainwindow->collection[filaB][columnaB];
                  if (box->item == NULL){//si el cuadrado no tiene ya alguna figura de opcion de movimiento
                      //primero se verifica que el cuadrado no tenga ningun item, luego si
                      MarcarCuadrado(box,filaB,columnaB);
                  }
                }
              }
            }else{
                if(item !=NULL){//validar el movimiento de la pieza por los items
                    if(piezaa !=NULL){
                        Matar();
                    }else
                        MoverFicha();
                }else{
                    clearBoxes();
                    if(piezaa !=NULL){//si clickea a una nueva pieza o no
                        mainwindow->piezaSeleccionada = NULL;
                        mousePressEvent(event);
                        return;
                    }else{
                        return;
                    }
                }
            }

    }


}
bool cuadrado::isEmpty(){
    return estado;
}

void cuadrado::clearBoxes(){
    for (int i = 0; i < 8 ; i++){
        for (int j = 0; j < 8 ; j++){
            PosibleMov *tempPosible = mainwindow->collection[i][j]->item;
            if(mainwindow->collection[i][j]->item != NULL){
                mainwindow->collection[i][j]->item = NULL;
                delete (tempPosible);
            }
        }
    }
}
void cuadrado::MarcarCuadrado(cuadrado *box, int filaB, int columnaB){
    if((box->piezaa != NULL && box->piezaa->getColor()==mainwindow->turno)){//si marca a un compañero se omite
        return;
    }
    qDebug()<<QString::number(filaB) + " - "+ QString::number(columnaB);
    PosibleMov *option = new PosibleMov(1);
    box->ubicacion2(option);
    mainwindow->addScene(option);
}
void cuadrado::Matar(){

    Pieza *a =mainwindow->collection[fila][columna]->piezaa;
    if(a->getColor()=="WHITE")
        mainwindow->chess->white.removeOne(a);
    else
        mainwindow->chess->black.removeOne(a);
    for(int i = 0;i<mainwindow->chess->black.size();i++)
        qDebug()<<mainwindow->chess->black.at(i)->ficha;
    mainwindow->collection[fila][columna]->piezaa = mainwindow->piezaSeleccionada;
    delete(a);//eliminar la pieza victimada----------
    //formatear los valores del cuadrado atacado
    mainwindow->piezaSeleccionada->getCuadrado()->estado = false;
    mainwindow->piezaSeleccionada->getCuadrado()->piezaa = NULL;
    //ubicar pieza victimaria
    //piezaa = mainwindow->piezaSeleccionada;
    mainwindow->collection[fila][columna]->ubicacion(piezaa);
    mainwindow->piezaSeleccionada = NULL;
    clearBoxes();
    //blanquear l¡el cuadrado de la pieza quee està matando
    if(piezaa->getColor() == "WHITE"){
        mainwindow->turno = &mainwindow->turnoB;
    }else{
        mainwindow->turno = &mainwindow->turnoA;
    }
    if(mainwindow->verificarJaque())
        qDebug()<<"Estas en jaque prro";
}
void cuadrado::MoverFicha(){
    cuadrado *boxTmp = mainwindow->piezaSeleccionada->getCuadrado();//de que cuadrado viene la pieza
    piezaa = mainwindow->piezaSeleccionada;
    mainwindow->collection[fila][columna]->ubicacion(piezaa);//actualizar la ubicacion de la
    //mainwindow->addScene(piezaa);
    boxTmp->estado = false;//se obtiene la dir del anterior cuadrado, y se le restablecen los valores
    boxTmp->piezaa=nullptr;//----------------

    PosibleMov *tempPosible = mainwindow->collection[fila][columna]->item;//borrar la marqua asignada antes
    mainwindow->collection[fila][columna]->item = nullptr;//------------
    clearBoxes();
    delete(tempPosible);
    mainwindow->piezaSeleccionada = nullptr;//------------
    if(piezaa->getColor() == "WHITE"){
        mainwindow->turno = &mainwindow->turnoB;
    }else{
        mainwindow->turno = &mainwindow->turnoA;
    }
    if(mainwindow->verificarJaque()){
        qDebug()<<"Estas en jaque";

    }
}
Pieza* cuadrado::cambiarPeon(){

}

//mainwindow->collection[filaB][columnaB];
//lo siguiente es validar que si juega negro, toca ahora a blanco
//lo siguiente validar si el casillero al que se movio es enemigo, amigo o vacio
