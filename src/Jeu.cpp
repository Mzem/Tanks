#include "../head/Jeu.h"

Jeu::Jeu(int nbJoueurs, QWidget *parent) : nombreJoueurs(nbJoueurs)
{
    //Creation du terrain (scene)
    terrain = new Terrain(parent);
    terrain->setSceneRect(0,0,X,Y);

    //Ajout du menu à droite
    MenuJeu* menu = new MenuJeu();
    QGraphicsProxyWidget* menuProxyWidget = terrain->addWidget(menu);
    menuProxyWidget->setPos(Y,0);   //On fait en sorte que le terrain fasse un carré de coté Y = X-(X-Y)

    //Creation des joueurs (tanks) et ajout au terrain (scene)
    tanks = new Tank*[nbJoueurs];    //Tableau de tank*
    for (int i = 0 ; i < nbJoueurs ; i++)
    {
        tanks[i] = new Tank(i+1,terrain);
        tanks[i]->setFlag(QGraphicsItem::ItemIsFocusable);
        tanks[i]->setFocus();
        terrain->addItem(tanks[i]);
        switch (i){
            case 0 : terrain->updateCases(tanks[i]->getPosition(),TANK1,tanks[i]->getRayon()); break;
            case 1 : terrain->updateCases(tanks[i]->getPosition(),TANK2,tanks[i]->getRayon()); break;
            case 2 : terrain->updateCases(tanks[i]->getPosition(),TANK3,tanks[i]->getRayon()); break;
            case 3 : terrain->updateCases(tanks[i]->getPosition(),TANK4,tanks[i]->getRayon()); break;
        }
    }

    //Ajout des obstacles
    for (int i = 0 ; i<8 ; i+=3)
        for (int j = i%2 ; j<8 ; j+=3)
            if
            (   terrain->getCases(i,j)==VIDE)
            /*  Tu peux utiliser ces condition pour générer un truc intelligent
            &&  (i==0 || terrain->getCases(i-1,j)==VIDE)
            &&  (i==7 || terrain->getCases(i+1,j)==VIDE)
            &&  (j==0 || terrain->getCases(i,j-1)==VIDE)
            &&  (j==7 || terrain->getCases(i,j+1)==VIDE)
            */
            {
                if(i==j){
                    terrain->addItem(new Obstacle(ARBRE,Point(i*tailleCase,Y-tailleCase-j*tailleCase)));
                    terrain->updateCases(Point(i*tailleCase,Y-tailleCase-j*tailleCase),ARBRE);
                } else {
                terrain->addItem(new Obstacle(ROCHER,Point(i*tailleCase,Y-tailleCase-j*tailleCase)));
                terrain->updateCases(Point(i*tailleCase,Y-tailleCase-j*tailleCase),ROCHER);
                }
            }


    //Rendre la scene (le terrain) visible dans la vue (le jeu)
    setScene(terrain);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setBackgroundBrush(QBrush(Qt::darkRed, Qt::Dense4Pattern)); //arriere plan
    setMinimumSize(X,Y);
}

Terrain* Jeu::getTerrain(){
    return terrain;
}

void Jeu::resizeEvent(QResizeEvent* event)
{
    cout << "Fenetre : " << event->size().width() <<"x"<< event->size().height() << endl;
    /*
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
    */
}
