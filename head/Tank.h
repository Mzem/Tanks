#ifndef TANK_H
#define TANK_H

#include <iostream>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QSize>
#include <QGraphicsWidget>
#include "../head/Point.h"
#include "../head/Obus.h"

using namespace std;

//Dimensions initiales de la fenetre, definies ici car le tank en a besoin (et jeu inclut tank)
extern int X;
extern int Y;

enum DIRECTION {HAUT,BAS,DROITE,GAUCHE};


class Tank: public QGraphicsPixmapItem
{
    private:
        DIRECTION direction;
        Obus O1;
        Obus O2;
        Obus O3;


    public:
        Tank(int indiceJoueur, QGraphicsItem * parent=0);
        Point getPosition();                    //Retoune la position en hautGauche du tank
        void keyPressEvent(QKeyEvent* event);
        void adapter(QSize nouvelleTaille, QSize ancienneTaille); //adapte le tank a la fenetre

};

#endif // TANK_H
