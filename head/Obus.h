#ifndef OBUS_H
#define OBUS_H

#include <QGraphicsItem>
#include <QTimer>
#include "../head/Definitions.h"
#include "../head/Point.h"

class Obus : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        Obus(int type, int angleH, int angleV, QGraphicsItem * parent=0);

    public slots:
        void bouger();

    private:
        int type;
        int force;
        int rayon;

};

#endif // OBUS_H
