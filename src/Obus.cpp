#include "../head/Obus.h"
#include "../head/Jeu.h"

extern Jeu* J;

Obus::Obus(int t, int aH, int aV, QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent), type(t)
{
    if (type == 1){
        rayon = 1;
        force = 2;
        setPixmap(QPixmap(":/obus1.png"));
    }
    else if (type == 2){
        rayon = 5;
        force = 5;
        setPixmap(QPixmap(":/obus2.png"));
    }
    else if (type == 3){
        rayon = 9;
        force = 10;
        setPixmap(QPixmap(":/obus3.png"));
    }

    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(bouger()));

    timer->start(50);

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
    //Continuer à avancer tq pas d'impact
    setPos(x()-10,y());
    //Detruire l'obus s'il sort du terrain
    if (pos().x() <= 0 || pos().x() >= Y){
        J->getTerrain()->removeItem(this);
        delete this;
    }
}


