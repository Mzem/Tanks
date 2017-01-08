#ifndef OBUS_H
#define OBUS_H

#include <QGraphicsItem>
#include <QTimer>
#include <typeinfo>
#include "Definitions.h"
#include "Point.h"

class Obus : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        Obus(int type, double angleH, double angleV, QGraphicsItem * parent=0);

    public slots:
        void bouger();

    private:
        int force;
        int rayon;
        //Il s'agit des angles absolus en degré
        double angleH;
        double angleV;
        //Distance de l'impact de l'obus depuis la source (le tank)
        int distanceImpact;
        //Compteur indiquant la position actuelle de l'obus par rapport à la distance de l'impact
        int compteurPosObus;

};

#endif // OBUS_H
