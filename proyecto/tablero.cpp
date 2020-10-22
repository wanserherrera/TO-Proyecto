#include "tablero.h"


#include "cuadrado.h"
#include "mainwindow.h"
extern MainWindow *mainwindow;
tablero::tablero()
{

}
void tablero::dibujarCasillas(int x,int y)
{
    int SHIFT = 70;//tamaño del cuadrado en el tablero
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++)
        {
            cuadrado *casilla = new cuadrado();
            mainwindow->collection[i][j] = casilla;
            casilla->fila = i;
            casilla->columna = j;
            casilla->setPos(x+SHIFT*j,y+SHIFT*i);
            if(i==0||i==8||j==0||j==8){
                casilla->setOriginalColor(QColor(255,255,255));
            }
            else if((i+j)%2==0){
                casilla->setOriginalColor(QColor(222,196,156));
            }else
                casilla->setOriginalColor(QColor(147,92,62));
            mainwindow->addScene(casilla);




        }
    }

}
