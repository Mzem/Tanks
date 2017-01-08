#ifndef CANON_H
#define CANON_H

//Gestion du canon et son angle de tir, son déplacement est analogue au tank puisque c'est son parent

#include <QGraphicsItem>

enum DIRECTION {HAUT,BAS,DROITE,GAUCHE};

class Canon : public QGraphicsPixmapItem
{
    public:
        Canon(DIRECTION, QGraphicsItem *parent=0);
        double getAngleH();
        double getAngleV();
        void setAngleH(double);
        void setAngleV(double);
        double getAngleHAbsolu();
        double getAngleVAbsolu();
        void setAngleHAbsolu(double);
        void setAngleVAbsolu(double);

    private:
        double angleH;          //celui de la rotation
        double angleV;          //1.X, X entre 0 et 9 inclus, X*10 représente l'angleVAbsolu
        double angleHAbsolu;    //0 - 360
        double angleVAbsolu;    //0 - 90

};

#endif // CANON_H
