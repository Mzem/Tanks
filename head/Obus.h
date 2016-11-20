#ifndef OBUS_H
#define OBUS_H

#include <QGraphicsEllipseItem>
#include <QObject>

class Obus : public QObject, public QGraphicsEllipseItem
{
    private:
        int type;
        int rayon;
        int force;

    public:
        Obus(int type); //en fonction du type, met les valeurs de rayon et force

};

#endif // OBUS_H
