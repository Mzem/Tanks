#include "../head/Obus.h"
#include "../head/Jeu.h"

extern Jeu* J;

Obus::Obus(int t, double aH, double aV, QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent), type(t)
{
    angleH = aH;
    angleV = aV;

    QPixmap imageObus(":/obus.png");
    switch (type) {
    case 1: rayon = 1;  force = 2;
            imageObus = imageObus.scaled(Y/20,Y/20, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            setPixmap(imageObus);
            break;
    case 2: rayon = 5;  force = 5;
            imageObus = imageObus.scaled(Y/16,Y/16, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            setPixmap(imageObus);
            break;
    case 3: rayon = 9;  force = 10;
            imageObus = imageObus.scaled(Y/12,Y/12, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            setPixmap(imageObus);
            break;
    }
    setRotation(rotation()-aH);

    //Mouvement de l'obus
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(bouger()));
    timer->start(10);

}

void Obus::bouger(){

    //On récupère la liste des items qui entrent en collision avec l'obus
    QList<QGraphicsItem*> elementsTouches = collidingItems();

    //Si on touche un objet, on traite l'impact et on détruit l'obus
    for (int i = 0, n = elementsTouches.size(); i < n; ++i)
    {
        //Si c'est un tank et c'est pas lui meme
        if (typeid(*(elementsTouches[i])) == typeid(Tank) && (dynamic_cast<Tank*>(elementsTouches[i])) != J->getTankCourant())
        {
            cout << "Tank touché" << endl;
            (dynamic_cast<Tank*>(elementsTouches[i]))->decrementeResistance(force);
            if ( (dynamic_cast<Tank*>(elementsTouches[i]))->getResistance() <= 0 ){
                J->getTerrain()->removeItem(elementsTouches[i]);
                J->setJoueurMort((dynamic_cast<Tank*>(elementsTouches[i]))->getNumJoueur());
                delete elementsTouches[i];
            }
            //Destruction de l'obus
            J->getTerrain()->removeItem(this);
            delete this;
            return; //Car l'obus n'existe plus
        }
        if (typeid(*(elementsTouches[i])) == typeid(Obstacle))
        {
            cout << "Obstacle touché" << endl;
            (dynamic_cast<Obstacle*>(elementsTouches[i]))->decrementeResistance(force);
            if ( (dynamic_cast<Obstacle*>(elementsTouches[i]))->getResistance() <= 0 ){
                J->getTerrain()->removeItem(elementsTouches[i]);
                delete elementsTouches[i];
            }
            //Destruction de l'obus
            J->getTerrain()->removeItem(this);
            delete this;
            return; //Car l'obus n'existe plus

            return;

        }
    }

    //Continuer à avancer tq pas d'impact (selon l'angleH et l'angleV)
    setPos(x()+uniteDeplacement*cos(angleH*M_PI/180.0),y()-uniteDeplacement*sin(angleH*M_PI/180.0));

    //Detruire l'obus s'il sort du terrain
    if (pos().x() < 0 || pos().x() >= Y){
        J->getTerrain()->removeItem(this);
        delete this;
    }
}


