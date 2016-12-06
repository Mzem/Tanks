#ifndef JEU_H
#define JEU_H

#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QResizeEvent>
#include "../head/Tank.h"

using namespace std;


class Jeu : public QGraphicsView
{
    private:
        QGraphicsScene* scene;
        int nombreJoueurs;
        Tank* joueurs[2];   //Tab qui stocke les joueurs, à faire evoluer en ptr (tab dynamique)

    public:
        Jeu(int nombreJoueurs, QWidget* parent=0);
        void resizeEvent(QResizeEvent* event);


};

#endif // JEU_H
