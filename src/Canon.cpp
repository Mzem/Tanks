#include "../head/Canon.h"

Canon::Canon(DIRECTION dir, QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    angleV = 0;
    switch(dir){
        case DROITE :   angleH = 180;   break;
        case GAUCHE :   angleH = 0;     break;
        case HAUT :     angleH = 90;    break;
        case BAS :      angleH = 270;   break;
   }
}

int Canon::getAngleH(){
    return angleH;
}

int Canon::getAngleV(){
    return angleV;
}

void Canon::rotationH(int angle)
{
    angleH = (angleH + angle) % 360;
}

void Canon::rotationV(int angle)
{
    angleV = (angleV + angle) % 360;
}
