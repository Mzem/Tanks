#ifndef TERRAIN_H
#define TERRAIN_H

//Classe qui renseigne sur les cases du terrain et les elements qui s'y trouvent

#include <QGraphicsScene>
#include <QGraphicsItem>
#include "../head/Obstacle.h"

class Terrain : public QGraphicsScene
{
    public:
        Terrain(QWidget *parent=0);
        //Met l'element dans la case correspondante (rayonTank = 0 : c'est pas un tank)
        void updateCases(Point coordElement, ELEMENTS elem, int rayonTank=0);
        void vider(ELEMENTS elem);
        void affiche();
        ELEMENTS getCases(int, int);
        void impact(Point);

    private:
        //8 cases : le terrain est un carré de coté Y et le tank est un carré de coté Y/8
        ELEMENTS cases[8][8];
};

#endif // TERRAIN_H
