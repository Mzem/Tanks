#ifndef TANK_H
#define TANK_H

#include <QGraphicsRectItem>

class Tank: public QGraphicsRectItem
{
    private:
        //Point hautG;       //position en haut a gauche du tank
        int pointsDeVie;
        int capaciteDepl;   //capacite de deplacement par tour, depend de la nature du terrain, vaut X/10
                            //c'est un const normalement

        //Canon canon;

        //Un objet pour stocker les obus et leur nombre



    public:
        void keyPressEvent(QKeyEvent * event);
};

#endif // TANK_H
