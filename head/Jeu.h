#ifndef JEU_H
#define JEU_H

//Classe principale qui crée le terrain et y ajoute les elements du jeu

#include <QGraphicsView>
#include <QResizeEvent>
#include <QGraphicsProxyWidget>
#include <QLabel>
#include <QGroupBox>
#include <QLCDNumber>
#include <QMessageBox>
#include "../head/MenuJeu.h"
#include "../head/Tank.h"

class Jeu : public QGraphicsView
{
    Q_OBJECT

    public:
        Jeu(int nombreJoueurs, QWidget* parent=0);
        Terrain* getTerrain();
        Tank* getTankCourant();
        void setJoueurMort(int);
        bool estMort(int);
        void resizeEvent(QResizeEvent* event);

    public slots:
        void tourDeJeu();
        void wait();
        void message();

    signals:
        void fini();

    private:
        int nombreJoueurs;
        vector<int> joueursMorts;
        Terrain* terrain;
        MenuJeu* menu;
        Tank** tanks;
};

#endif // JEU_H
