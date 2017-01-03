#ifndef JEU_H
#define JEU_H

//Classe principale qui crée le terrain et y ajoute les elements du jeu

#include <QGraphicsView>
#include <QGraphicsProxyWidget>
#include <QLabel>
#include <QGroupBox>
#include <QLCDNumber>
#include <QMessageBox>
#include "MenuJeu.h"
#include "Tank.h"

class Jeu : public QGraphicsView
{
    Q_OBJECT

    public:
        Jeu(int nombreJoueurs, QWidget* parent=0);
        ~Jeu();
        Terrain* getTerrain();
        Tank* getTankCourant();
        void setJoueurMort(int);
        bool estMort(int);

    public slots:
        void tourDeJeu();
        void tourDeJeuIA();
        void waitTir();
        void messageFin();

    signals:
        void jeuFini();

    private:
        int nombreJoueurs;
        vector<int> joueursMorts;
        Terrain* terrain;
        Tank** tanks;
        MenuJeu* menu;
        ButtonWidget* tirObus1;
        ButtonWidget* tirObus2;
        ButtonWidget* tirObus3;
};

#endif // JEU_H
