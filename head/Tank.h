#ifndef TANK_H
#define TANK_H

//Création d'un tank (joueur), déplacement et tir

#include <QKeyEvent>
#include "../head/Terrain.h"
#include "../head/Canon.h"
#include "../head/Obus.h"

class Tank : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        Tank(int numJoueur, Terrain*, QGraphicsItem * parent=0);
        void decrementeResistance(int);
        int getResistance();
        int getNumJoueur();
        //Position centrale du tank
        Point getPosition();
        int getRayon();
        Canon* getCanon();
        int getCapacite();
        int getNbObus1();
        int getNbObus2();
        int getNbObus3();
        void keyPressEvent(QKeyEvent* event);
        //Adapte le tank a la la taille de la fenetre
        void adapter(QSize nouvelleTaille, QSize ancienneTaille);

    public slots:
        void tirer(QString);

    signals:
        void capaciteChanged(int);

    private:
        int numJoueur;
        int resistance;
        //Pointe vers le terrain du jeu pour pouvoir le modifier
        Terrain* terrain;
        DIRECTION direction;
        Canon* canon;
        int capaciteDeplacement;
        int nbObus1;
        int nbObus2;
        int nbObus3;
};

#endif // TANK_H
