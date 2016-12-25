#include "../head/Obus.h"
#include "../head/Jeu.h"

extern Jeu* J;

Obus::Obus(int t, double aH, double aV, QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent), type(t)
{
    angleH = aH;
    angleV = aV;

    QPixmap* imageObus;
    switch (type) {
    case 1: rayon = 1;  force = 2;
            imageObus = new QPixmap(":/obus1.png");
            *imageObus = imageObus->scaled(Y/16,Y/16, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            setPixmap(*imageObus);
            break;
    case 2: rayon = 5;  force = 5;
            imageObus = new QPixmap(":/obus2.png");
            *imageObus = imageObus->scaled(Y/16,Y/16, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            setPixmap(*imageObus);
            break;
    case 3: rayon = 9;  force = 10;
            imageObus = new QPixmap(":/obus3.png");
            *imageObus = imageObus->scaled(Y/16,Y/16, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            setPixmap(*imageObus);
            break;
    }
    setRotation(rotation()-aH);

    //Mouvement de l'obus
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(bouger()));
    timer->start(30);

}

void Obus::bouger(){

    /*
    QList<QGraphicsItem*> elementsTouches = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // increase the score
            game->score->increase();

            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete colliding_items[i];
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }
    }
    */
    //Continuer à avancer tq pas d'impact (selon l'angleH et l'angleV)
    setPos(x()+uniteDeplacement*cos(angleH*M_PI/180.0),y()-uniteDeplacement*sin(angleH*M_PI/180.0));


    //Detruire l'obus s'il sort du terrain
    if (pos().x() < 0 || pos().x() > Y){
        J->getTerrain()->removeItem(this);
        delete this;
    }
}


