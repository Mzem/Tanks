#include "../head/Jeu.h"

static int aQuiLeTour = 0;

Jeu::Jeu(int nbJoueurs, QWidget *parent) : nombreJoueurs(nbJoueurs)
{
    //Creation du terrain (scene)
    terrain = new Terrain(parent);
    terrain->setSceneRect(0,0,X,Y);

    //Ajout du menu à droite
    menu = new MenuJeu(parent);
    QGraphicsProxyWidget* menuProxyWidget = terrain->addWidget(menu);
    menuProxyWidget->setPos(Y,0);   //On fait en sorte que le terrain fasse un carré de coté Y = X-(X-Y)

    //Creation des joueurs (tanks) et ajout au terrain (scene)
    tanks = new Tank*[nbJoueurs];    //Tableau de tank*
    for (int i = 0 ; i < nbJoueurs ; i++)
    {
        tanks[i] = new Tank(i+1,terrain);
        tanks[i]->setFlag(QGraphicsItem::ItemIsFocusable);
        terrain->addItem(tanks[i]);
        switch (i){
            case 0 : terrain->updateCases(tanks[i]->getPosition(),TANK1,tanks[i]->getRayon()); break;
            case 1 : terrain->updateCases(tanks[i]->getPosition(),TANK2,tanks[i]->getRayon()); break;
            case 2 : terrain->updateCases(tanks[i]->getPosition(),TANK3,tanks[i]->getRayon()); break;
            case 3 : terrain->updateCases(tanks[i]->getPosition(),TANK4,tanks[i]->getRayon()); break;
        }
    }

    //Ajout des obstacles
    for (int i = 0 ; i<15 ; i+=4)
        for (int j = 1 ; j<15 ; j+=4)
            if
				((terrain->getCases(i,j)==VIDE)&&(terrain->getCases(i+1,j-1)==VIDE)&&
				(terrain->getCases(i,j-1)==VIDE)&&(terrain->getCases(i+1,j)==VIDE))
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
                    terrain->updateCases(Point((i+1)*tailleCase,Y-tailleCase-j*tailleCase),ARBRE);
                    terrain->updateCases(Point((i+1)*tailleCase,Y-tailleCase-(j-1)*tailleCase),ARBRE);
                    terrain->updateCases(Point(i*tailleCase,Y-tailleCase-(j-1)*tailleCase),ARBRE);
                } else {
					terrain->addItem(new Obstacle(ROCHER,Point(i*tailleCase,Y-tailleCase-j*tailleCase)));
					terrain->updateCases(Point(i*tailleCase,Y-tailleCase-j*tailleCase),ROCHER);
                    terrain->updateCases(Point((i+1)*tailleCase,Y-tailleCase-j*tailleCase),ROCHER);
                    terrain->updateCases(Point((i+1)*tailleCase,Y-tailleCase-(j-1)*tailleCase),ROCHER);
                    terrain->updateCases(Point(i*tailleCase,Y-tailleCase-(j-1)*tailleCase),ROCHER);
                }
            }

    //Rendre la scene (le terrain) visible dans la vue (le jeu)
    setScene(terrain);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setBackgroundBrush(QBrush(Qt::darkRed, Qt::Dense4Pattern)); //arriere plan
    setMinimumSize(X,Y);

    tanks[0]->setFocus();

    //tq il reste 1 tank en jeu
    //while(1)
        tourDeJeu(nbJoueurs);
}

void Jeu::tourDeJeu(int nbJoueurs)
{
    aQuiLeTour = aQuiLeTour%nbJoueurs;

    QPalette p;

    switch (aQuiLeTour)
    {
        case 0: QGroupBox* textTour = new QGroupBox("Tour du tank n°1",menu);
                textTour->setAlignment(Qt::AlignHCenter);
                textTour->setFont(QFont("arial",16));
                p.setColor(QPalette::WindowText, QColor(100,180,50));
                textTour->setPalette(p);

                //Deplacement du tank
                QGroupBox* textDeplace = new QGroupBox("Deplacement du tank");
                textDeplace->setAlignment(Qt::AlignHCenter);
                textDeplace->setFont(QFont("arial",10));

                //Affichage en temps reel de la capacité
                QLCDNumber* capacite= new QLCDNumber(this);
                capacite->setSegmentStyle(QLCDNumber::Flat);
                capacite->display(tanks[aQuiLeTour]->getCapacite());
                capacite->update();
                QObject::connect(tanks[aQuiLeTour], SIGNAL(capaciteChanged(int)), capacite, SLOT(display(int)));

                //Bouton validation
                ButtonWidget* validerDeplace = new ButtonWidget(QStringList("1. OK"),QColor(Qt::black));
                QObject::connect(validerDeplace, SIGNAL(clicked(QString)), this, SLOT(changerFocus(QString)));

                QVBoxLayout* vboxDeplace = new QVBoxLayout;
                vboxDeplace->addWidget(capacite);
                vboxDeplace->addWidget(validerDeplace);
                textDeplace->setLayout(vboxDeplace);

                //Choix de l'obus
                QGroupBox* textObus = new QGroupBox("Choix obus");
                textObus->setAlignment(Qt::AlignHCenter);
                textObus->setFont(QFont("arial",10));
                QRadioButton* o1 = new QRadioButton(QString("Obus 1 :\n        Rayon 1, Force 2\n        ")
                                                    +QString::number(tanks[aQuiLeTour]->getNbObus1())
                                                    +QString(" restants"));
                QRadioButton* o2 = new QRadioButton(QString("Obus 2 :\n        Rayon 5, Force 5\n        ")
                                                    +QString::number(tanks[aQuiLeTour]->getNbObus2())
                                                    +QString(" restants"));
                QRadioButton* o3 = new QRadioButton(QString("Obus 3 :\n        Rayon 9, Force 10\n        ")
                                                    +QString::number(tanks[aQuiLeTour]->getNbObus3())
                                                    +QString(" restants"));
                o1->setFont(QFont("arial",7));
                o2->setFont(QFont("arial",7));
                o3->setFont(QFont("arial",7));
                o1->setChecked(true);

                //Bouton de validation
                ButtonWidget* validerObus = new ButtonWidget(QStringList("2. OK"),QColor(Qt::black));
                QObject::connect(validerObus, SIGNAL(clicked(QString)), this, SLOT(changerFocus(QString)));

                QVBoxLayout* vboxObus = new QVBoxLayout;
                vboxObus->addWidget(o1);
                vboxObus->addWidget(o2);
                vboxObus->addWidget(o3);
                vboxObus->addWidget(validerObus);
                textObus->setLayout(vboxObus);

                //Positionnement du canon
                QGroupBox* textCanon = new QGroupBox("Positionnement du canon");
                textCanon->setAlignment(Qt::AlignHCenter);
                textCanon->setFont(QFont("arial",10));

                //Bouton de validation
                ButtonWidget* validerCanon = new ButtonWidget(QStringList("3. OK"),QColor(Qt::black));
                QObject::connect(validerCanon, SIGNAL(clicked(QString)), this, SLOT(changerFocus(QString)));

                QVBoxLayout* vboxCanon = new QVBoxLayout;
                vboxCanon->addWidget(validerCanon);
                textCanon->setLayout(vboxCanon);

                //Menu global d'un tour
                QVBoxLayout* vboxTour = new QVBoxLayout;
                vboxTour->addWidget(textDeplace);
                vboxTour->addWidget(textObus);
                vboxTour->addWidget(textCanon);
                textTour->setLayout(vboxTour);
                textTour->setMaximumWidth(X-Y-18);
                menu->getLayout()->addWidget(textTour,1,0);

                break;
    }

}

void Jeu::changerFocus(QString typeFocus)
{
    int type = typeFocus[0].digitValue();
    cout << "change" << type << endl;
    switch (type) {
    case 2: tanks[aQuiLeTour]->getCanon()->setFocus();
            break;
    case 3: tanks[aQuiLeTour+1]->setFocus();
            break;
    }

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
