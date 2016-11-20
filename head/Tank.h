#ifndef TANK_H
#define TANK_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "../head/Point.h"

#include <iostream>
using namespace std;

enum DIRECTION {HAUT,BAS,DROITE,GAUCHE};

class Tank: public QGraphicsPixmapItem
{
    private:
        //Pas la peine de stocker la position du tank, on l'a grace a la methode getPosition()
        Point champ;            //champ de la fenetre dans lequel le tank peut se deplacer
        DIRECTION direction;

        int pointsDeVie;
        int capaciteDepl;   //capacite de deplacement par tour, depend de la nature du terrain, vaut X/10
                            //c'est un const normalement

        //Canon canon;

        //Un objet pour stocker les obus et leur nombre

    public:
        Tank(int largeurFenetre, int hauteurFenetre);
        void keyPressEvent(QKeyEvent * event);
        Point getPosition();    //Retoune la position centrale du tank
};

#endif // TANK_H
