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
        double angleH;    //0 - 360
        double angleV;    //0 - 90
        double angleHAbsolu;
        double angleVAbsolu;

};

#endif // CANON_H
