#include "../head/Jeu.h"
#include <QBrush>


Jeu::Jeu(int nbJoueurs, QWidget *parent) : nombreJoueurs(nbJoueurs)
{
    //Creation de la scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,X,Y);
    setBackgroundBrush(QBrush(Qt::darkRed, Qt::Dense4Pattern));

    //Rendre la scene visible dans la vue (le jeu)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setMinimumSize(X,Y);

    //Creation des joueurs (tanks) et ajout à la scene
    for (int i = 0 ; i < nombreJoueurs ; i++)
    {
        joueurs[i] = new Tank(i+1);
        joueurs[i]->setFlag(QGraphicsItem::ItemIsFocusable);
        joueurs[i]->setFocus();
        scene->addItem(joueurs[i]);
    }

    show();

}

void Jeu::resizeEvent(QResizeEvent* event)
{
    cout << "Fenetre : " << event->size().width() <<"x"<< event->size().height() << endl;
    X=event->size().width();
    Y=event->size().height();

    //On adapte les tanks aux nouvelles dimensions de la fenetre
    static bool auLancement = true;

    if (!auLancement)
    {
        for (int i = 0 ; i < nombreJoueurs ; i++)
        {
            joueurs[i]->adapter(event->size(),event->oldSize());
        }
    }

    auLancement = false;
}
