#ifndef JEU_H
#define JEU_H

//Classe principale qui crée le terrain et y ajoute les elements du jeu

#include <QGraphicsView>
#include <QResizeEvent>
#include <QGraphicsProxyWidget>
#include "../head/MenuJeu.h"
#include "../head/Tank.h"

class Jeu : public QGraphicsView
{
    Q_OBJECT

    public:
        Jeu(int nombreJoueurs, QWidget* parent=0);
        void resizeEvent(QResizeEvent* event);
        Terrain* getTerrain();

    private:
        int nombreJoueurs;
        Terrain* terrain;
        Tank** tanks;
};

#endif // JEU_H
