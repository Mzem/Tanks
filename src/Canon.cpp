#include "../head/Canon.h"

#include <iostream>
using namespace std;

Canon::Canon(DIRECTION dir, QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    angleV = 0;
    switch(dir){
        case DROITE :   angleH = 0;     break;
        case GAUCHE :   angleH = 180;   break;
        case HAUT :     angleH = 90;    break;
        case BAS :      angleH = 270;   break;
   }
}

double Canon::getAngleH(){
    return angleH;
}
double Canon::getAngleV(){
    return angleV;
}
void Canon::setAngleH(double a){
    angleH = a;
}
void Canon::setAngleV(double a){
    angleV = a;
}

void Canon::keyPressEvent(QKeyEvent *event)
{
    cout << "here" << endl;
}
