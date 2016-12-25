#ifndef DEF_MENU
#define DEF_MENU

//Classe qui definit le menu d'acceuil et qui lance le jeu en fonction du bouton cliqué

#include <QLabel>
#include <QGridLayout>
#include <QPaintEvent>
#include <QStyleOption>
#include "../head/ButtonWidget.h"
#include "../head/Jeu.h"

class Menu : public QWidget
{
    Q_OBJECT

    public:
        Menu();

    public slots:
        void lancerJeu(QString nbJoueurs);
        void quitterJeu();

    private:
        ButtonWidget *boutons;
        void paintEvent(QPaintEvent *pe);   //Pour pouvoir ajuster l'image de fond
};

#endif
