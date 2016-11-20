#ifndef FENETRE_H
#define FENETRE_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QResizeEvent>
#include "../head/Tank.h"

#include <iostream>
using namespace std;

class Fenetre : public QGraphicsScene
{
    //Q_OBJECT
    private:
        QGraphicsView* vue;

    public:
        Fenetre();
        QGraphicsView* getVue();
        void resizeEvent(QResizeEvent * event);

};

#endif // FENETRE_H
