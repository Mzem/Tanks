#ifndef TANK_H
#define TANK_H

//Création d'un tank (joueur), déplacement et tir

#include <QKeyEvent>
#include "Terrain.h"
#include "Canon.h"
#include "Obus.h"

class Tank : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        Tank(int numJoueur, Terrain*, QGraphicsItem * parent=0);
        ~Tank();
        int getNumJoueur();
        int getResistance();
        //Position en haut à gauche du tank
        Point getPosition();
        int getRayon();
        Canon* getCanon();
        int getCapacite();
        int getNbObus1();
        int getNbObus2();
        int getNbObus3();
        void decrementeResistance(int);
        void keyPressEvent(QKeyEvent* event);
        void setIA();
        int getIA();
        //Retourne vrai si le tank traverse actuellement une crevasse
        bool traverseCrevasse();

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
        int IA;
};

#endif // TANK_H
