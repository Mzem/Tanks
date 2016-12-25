#ifndef JEU_H
#define JEU_H

//Classe principale qui crée le terrain et y ajoute les elements du jeu

#include <QGraphicsView>
#include <QResizeEvent>
#include <QGraphicsProxyWidget>
#include <QLabel>
#include <QGroupBox>
#include <QRadioButton>
#include <QLCDNumber>
#include "../head/MenuJeu.h"
#include "../head/Tank.h"

class Jeu : public QGraphicsView
{
    Q_OBJECT

    public:
        Jeu(int nombreJoueurs, QWidget* parent=0);
        void tourDeJeu(int);
        Terrain* getTerrain();
        void resizeEvent(QResizeEvent* event);

    public slots:
        void changerFocus(QString);

    private:
        int nombreJoueurs;
        Terrain* terrain;
        MenuJeu* menu;
        Tank** tanks;
};

#endif // JEU_H
