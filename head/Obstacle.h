#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QGraphicsItem>
#include "../head/Definitions.h"
#include "../head/Point.h"

enum ELEMENTS {VIDE, TANK1, TANK2, TANK3, TANK4, ROCHER, ARBRE, EAU, CREVASSE};

class Obstacle : public QGraphicsPixmapItem
{
    private:
        ELEMENTS type;
        int resistance;
        Point position;

    public:
        Obstacle(ELEMENTS type, Point position, QGraphicsItem * parent=0);
};

#endif // OBSTACLE_H
