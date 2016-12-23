#ifndef CANON_H
#define CANON_H

//Gestion du canon et son angle de tir, son déplacement est analogue au tank puisque c'est son parent

#include <QGraphicsItem>

enum DIRECTION {HAUT,BAS,DROITE,GAUCHE};

class Canon : public QGraphicsPixmapItem
{
    public:
        Canon(DIRECTION, QGraphicsItem *parent);
        int getAngleH();
        int getAngleV();
        void rotationH(int);
        void rotationV(int);

    private:
        int angleH;    //0 - 360
        int angleV;    //0 - 90
};

#endif // CANON_H
