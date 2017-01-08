#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QGraphicsItem>
#include "Definitions.h"
#include "Point.h"

enum ELEMENTS {VIDE, TANK1, TANK2, TANK3, TANK4, ROCHER, ARBRE, EAU};

class Obstacle : public QGraphicsPixmapItem
{
    public:
        Obstacle(ELEMENTS type, Point position, QGraphicsItem* parent=0);
        void decrementeResistance(int);
        int getResistance();

    private:
        ELEMENTS type;
        int resistance;
        Point position;
};

#endif // OBSTACLE_H
