#include "../head/Obstacle.h"

Obstacle::Obstacle(ELEMENTS t, Point pos, QGraphicsItem * parent): QGraphicsPixmapItem(parent)
{
    type = t;
    position = pos;
    QPixmap* imageObstacle;

    switch (type){
    case ROCHER:
        resistance = 7;
        imageObstacle = new QPixmap(":/rocher.png");
        *imageObstacle = imageObstacle->scaled(Y/8,Y/8, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        setPixmap(*imageObstacle);
        break;
    case ARBRE:
        resistance = 1;
        imageObstacle = new QPixmap(":/arbre.png");
        *imageObstacle = imageObstacle->scaled(Y/8,Y/8, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        setPixmap(*imageObstacle);
        break;
    case EAU:
        resistance = 100;
        imageObstacle = new QPixmap(":/eau.png");
        *imageObstacle = imageObstacle->scaled(Y/8,Y/8, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        setPixmap(*imageObstacle);
        break;
    case CREVASSE:
        resistance = -2;
        imageObstacle = new QPixmap(":/crevasse.png");
        *imageObstacle = imageObstacle->scaled(Y/8,Y/8, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        setPixmap(*imageObstacle);
        break;
    }

    setPos(pos.getX(),pos.getY());
}

void Obstacle::decrementeResistance(int forceObus){
    resistance-=forceObus;
}
int Obstacle::getResistance(){
    return resistance;
}
