#include "../head/Canon.h"

#include <iostream>
using namespace std;

Canon::Canon(DIRECTION dir, QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    angleV = 1.0;
    angleH = 0;
    angleVAbsolu = 0;
    switch(dir){
        case DROITE :   angleHAbsolu = 0;     break;
        case GAUCHE :   angleHAbsolu = 180;   break;
        case HAUT :     angleHAbsolu = 90;    break;
        case BAS :      angleHAbsolu = 270;   break;
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
double Canon::getAngleHAbsolu(){
    return angleHAbsolu;
}
double Canon::getAngleVAbsolu(){
    return angleVAbsolu;
}
void Canon::setAngleHAbsolu(double a){
    angleHAbsolu = a;
}
void Canon::setAngleVAbsolu(double a){
    angleVAbsolu = a;
}
