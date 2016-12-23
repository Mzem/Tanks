#ifndef TANK_H
#define TANK_H

//Création d'un tank (joueur), déplacement et tir

#include <QGraphicsItem>
#include <QKeyEvent>
#include "../head/Terrain.h"
#include "../head/Canon.h"
#include "../head/Obus.h"

extern const int uniteDeplacement;

class Tank : public QGraphicsPixmapItem
{
    public:
        Tank(int numJoueur, Terrain*, QGraphicsItem * parent=0);
        //Position centrale du tank
        Point getPosition();
        int getRayon();
        void keyPressEvent(QKeyEvent* event);
        //Adapte le tank a la la taille de la fenetre
        void adapter(QSize nouvelleTaille, QSize ancienneTaille);

    private:
        int numJoueur;
        //Pointe vers le terrain du jeu pour pouvoir le modifier
        Terrain* terrain;
        DIRECTION direction;
        Canon canon;
        int nbObus1;
        int nbObus2;
        int nbObus3;
};

#endif // TANK_H
