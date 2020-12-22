#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cuadrado.h"
#include "tablero.h"
#include "QDebug"
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    :QGraphicsView(parent)
{

    gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0,0,1200,700);
    setFixedSize(1200,700);//valor del witgets
    //setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setScene(gameScene);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBackgroundBrush(brush);
    int tmp = width();
    std::cout<<tmp+"..- valor\n";
    piezaSeleccionada = NULL;
    turno = &turnoA;//representa el turno actual
    labelJaqueWhite = new QGraphicsTextItem();
    labelJaqueBlack = new QGraphicsTextItem();
    labelJaqueWhite->setZValue(1);
    labelJaqueBlack->setZValue(1);
    labelJaqueBlack->setDefaultTextColor(Qt::red);
    labelJaqueWhite->setDefaultTextColor(Qt::red);
    labelJaqueWhite->setFont(QFont("",12));
    labelJaqueBlack->setFont(QFont("",12));
    labelJaqueWhite->setPos(10,70);
    labelJaqueBlack->setPos(250+700+10,70);
    addScene(labelJaqueBlack);
    addScene(labelJaqueWhite);
}

MainWindow::~MainWindow()
{

}
void MainWindow::crearTablero()
{
    chess = new tablero();
    drawDeadHolder(0,0,QColor(215,215,215));//derecho
    drawDeadHolder(950,0,QColor(215,215,215));//izquierdo
    chess->dibujarCasillas(320,70);
    chess->addPieza();

}

void MainWindow::drawDeadHolder(int x, int y,QColor color)
{
    //proporciona un elemento rectangular que puede agregar a QGraphicsScene
    deadHolder = new QGraphicsRectItem(x,y,250,700);//x, y, ancho ,alto
    QBrush brush;// define el patrón de relleno de las formas dibujadas por QPainter
    brush.setStyle(Qt::SolidPattern);//estilo del pincel
    brush.setColor(color);
    deadHolder->setBrush(brush);
    addScene(deadHolder);

}
void MainWindow::addScene(QGraphicsItem *item)
{
    gameScene->addItem(item);
}

void MainWindow::dibujarBorde(){
    int auxForFil=352, auxForCol, tmp2=0, tmp3=70+25;
    std::string fil [] = {"A","B","C","D","E","F","G","H"};
    std::string col [] = {"1","2","3","4","5","6","7","8"};
    for (int i = 0; i<8 ; i++){
        //std::string aux=(fil[i]+"");
        QGraphicsTextItem *tmp = new QGraphicsTextItem();
        tmp->setZValue(1);
        tmp->setDefaultTextColor(Qt::white);
        tmp->setFont(QFont("",14));
        tmp->setPlainText(QString::fromLocal8Bit(fil[i].c_str()));
        tmp->setPos(auxForFil+tmp2,700-50);
        QGraphicsTextItem *tmp4 = new QGraphicsTextItem();
        tmp4->setZValue(1);
        tmp4->setDefaultTextColor(Qt::white);
        tmp4->setFont(QFont("",14));
        tmp4->setPlainText(QString::fromLocal8Bit(fil[i].c_str()));
        tmp4->setPos(auxForFil+tmp2,32);
        tmp2 += 70;
        addScene(tmp4);
        addScene(tmp);
    }
    for (int i = 0; i<8 ; i++){
        //std::string aux=(fil[i]+"");
        QGraphicsTextItem *tmp = new QGraphicsTextItem();
        tmp->setZValue(1);
        tmp->setDefaultTextColor(Qt::white);
        tmp->setFont(QFont("",14));
        tmp->setPlainText(QString::fromLocal8Bit(col[i].c_str()));
        tmp->setPos(250+35,auxForCol+tmp3);
        QGraphicsTextItem *tmp4 = new QGraphicsTextItem();
        tmp4->setZValue(1);
        tmp4->setDefaultTextColor(Qt::white);
        tmp4->setFont(QFont("",14));
        tmp4->setPlainText(QString::fromLocal8Bit(col[i].c_str()));
        tmp4->setPos(250-50+700,+auxForCol+tmp3);
        tmp3 += 70;
        addScene(tmp4);
        addScene(tmp);
    }
}
QString MainWindow::getText(){
    return texto;
}
void MainWindow::setText(QString text){
    texto=text;
}
bool MainWindow::verificarJaque(){
    QList<Coordenada>allMove;//movimientos de las fichas blancas
    QList<Coordenada>allMove2;//movimientos de fichas negras
    Coordenada coordenadaReyNegro(reyBlack->getCuadrado()->columna,reyBlack->getCuadrado()->fila);//Rey Negro
    Coordenada coordenadaReyBlanco(reyWhite->getCuadrado()->columna,reyWhite->getCuadrado()->fila);//Rey blanco

    for (int i = 0; i <chess->white.size();i++){
        if(chess->white.at(i)!=NULL){
            allMove=chess->white.at(i)->movimientos();
            for(int j = 0; j<allMove.size();j++){
                if(allMove.at(j)==coordenadaReyNegro){
                    labelJaqueBlack->setPlainText("JAQUE AL REY NEGRO");
                    return true;//poner en jaque al rey negro
                }
            }
        }

    }
    labelJaqueBlack->setPlainText("");
     for (int i = 0; i <chess->black.size();i++){
         if(chess->black.at(i)!=NULL){//actualizar la lista de negro y blanco
             allMove2=chess->black.at(i)->movimientos();
             for(int j = 0; j<allMove2.size();j++){
                 if(allMove2.at(j)==coordenadaReyBlanco){
                     labelJaqueWhite->setPlainText("JAQUE AL REY BLANCO");
                     return true;//poner en jaque al rey negro

                 }
             }
         }
     }
     labelJaqueWhite->setPlainText("");
    return false;
}

void MainWindow::PiezaEliminada(Pieza *piece){
    if(piece->getColor()=="BLACK"){
        piece->setPos(250+700+30,70+25+auxPiezaMuerta1);
        auxPiezaMuerta1 +=50;
    }else{
        piece->setPos(250-80,70+25+auxPiezaMuerta2);
        auxPiezaMuerta2 +=50;
    }
}


