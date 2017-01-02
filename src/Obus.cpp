#include "../head/Obus.h"
#include "../head/Jeu.h"

extern Jeu* J;

Obus::Obus(int type, double aH, double aV, QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
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

    //Equation parabolique qui calcule la distance de l'impact à partir de la source (le tank)
    //en fonction de l'angle vertical du canon
    distanceImpact = -0.148*aV*aV + 10.0*aV + 300;
    //Initialisation du compteur de la position actuelle de l'obus
    compteurPosObus = 0;

    //Mouvement de l'obus
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(bouger()));
    timer->start(10);
}

void Obus::bouger()
{
    //Si l'obus a atteint le point d'impact
    if(compteurPosObus >= distanceImpact)
    {
        //Création de la crevasse représentant l'impact
        //tailleCase/8 : une case corréspond à un élément or pour les obus on condière des cases plus petites
        //On multiplie donc le nombre de cases par 8
        QGraphicsEllipseItem* crevasse = new QGraphicsEllipseItem(x()-(tailleCase/8)*rayon,y()-(tailleCase/8)*rayon,(tailleCase/4)*rayon,(tailleCase/4)*rayon);
        crevasse->setBrush(QBrush(QColor(170,130,70)));
        J->getTerrain()->addItem(crevasse);

        //On récupère la liste des items qui entrent en collision avec la crevasse
        QList<QGraphicsItem*> elementsTouches = crevasse->collidingItems();

        //Si la crevasse touche un objet, on traite l'impact
        for (int i = 0, n = elementsTouches.size(); i < n; ++i)
        {
            //Si c'est un tank
            if (typeid(*(elementsTouches[i])) == typeid(Tank))
            {
                cout << "Tank touche" << endl;
                (dynamic_cast<Tank*>(elementsTouches[i]))->decrementeResistance(force);
                if ( (dynamic_cast<Tank*>(elementsTouches[i]))->getResistance() <= 0 ){
                    J->getTerrain()->removeItem(elementsTouches[i]);
                    J->setJoueurMort((dynamic_cast<Tank*>(elementsTouches[i]))->getNumJoueur());
                    switch ((dynamic_cast<Tank*>(elementsTouches[i]))->getNumJoueur()) {
                        case 1: J->getTerrain()->vider(TANK1);  break;
                        case 2: J->getTerrain()->vider(TANK2);  break;
                        case 3: J->getTerrain()->vider(TANK3);  break;
                        case 4: J->getTerrain()->vider(TANK4);  break;
                    }
                    delete elementsTouches[i];
                } else {
                    //Pour que les tanks touchés restent au dessus de la crevasse
                    J->getTerrain()->removeItem(elementsTouches[i]);
                    J->getTerrain()->addItem(elementsTouches[i]);
                }
            }
            //Si c'est un obstacle
            if (typeid(*(elementsTouches[i])) == typeid(Obstacle))
            {
                cout << "Obstacle touche" << endl;
                (dynamic_cast<Obstacle*>(elementsTouches[i]))->decrementeResistance(force);
                if ( (dynamic_cast<Obstacle*>(elementsTouches[i]))->getResistance() <= 0 ){
                    J->getTerrain()->updateCases(Point(elementsTouches[i]->pos().x()+tailleCase/2,elementsTouches[i]->pos().y()+tailleCase/2),VIDE);
                    J->getTerrain()->removeItem(elementsTouches[i]);
                    delete elementsTouches[i];
                } else {
                    //Pour que les obstacles touchés restent au dessus de la crevasse
                    J->getTerrain()->removeItem(elementsTouches[i]);
                    J->getTerrain()->addItem(elementsTouches[i]);
                }
            }
        }
        //Destruction de l'obus et sortie
        J->getTerrain()->removeItem(this);
        delete this;
        return; //Car l'obus n'existe plus
    }

    //Continuer à avancer tq pas d'impact (selon l'angleH et l'angleV)
    //Et incrémenter le compteur de la position de l'obus
    setPos(x()+uniteDeplacement*cos(angleH*M_PI/180.0),y()-uniteDeplacement*sin(angleH*M_PI/180.0));
    compteurPosObus+= uniteDeplacement;

    //Detruire l'obus s'il sort du terrain
    if (pos().x() < 0 || pos().x() >= Y){
        J->getTerrain()->removeItem(this);
        delete this;
    }
}
