#include "../head/Jeu.h"
#include "../head/Menu.h"
#include <stdlib.h>
#include <time.h>

static int aQuiLeTour = 0;

Jeu::Jeu(int nbJoueurs, QWidget *parent) : nombreJoueurs(nbJoueurs)
{
    setParent(parent);
    aQuiLeTour = 0;

    //Creation du terrain (scene)
    terrain = new Terrain(parent);
    terrain->setSceneRect(0,0,X,Y);
    
    if(nombreJoueurs == 1) nbJoueurs++;

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
    
    if(nombreJoueurs == 1) {
		nombreJoueurs++;
		tanks[1]->setIA();
		cout<<"je suis une IA"<<endl;
	}

    //Ajout des obstacles
    srand(time(NULL));
    for (int i = 0 ; i<8 ; i++)
        for (int j = 0 ; j<8 ; j++)
            if ( terrain->getCases(i,j)==VIDE )
            {
                int alea = rand()%10;
                if (alea < 2){
                    terrain->addItem(new Obstacle(ARBRE,Point(i*tailleCase,j*tailleCase)));
                    terrain->updateCases(Point(i*tailleCase,j*tailleCase),ARBRE);
                } else if (alea <4){
                    terrain->addItem(new Obstacle(ROCHER,Point(i*tailleCase,j*tailleCase)));
                    terrain->updateCases(Point(i*tailleCase,j*tailleCase),ROCHER);
                } else if (alea <5){
                    terrain->addItem(new Obstacle(EAU,Point(i*tailleCase,j*tailleCase)));
                    terrain->updateCases(Point(i*tailleCase,j*tailleCase),EAU);
                }
            }

    //Rendre la scene (le terrain) visible dans la vue (le jeu)
    setScene(terrain);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setCursor(Qt::ForbiddenCursor);
    setBackgroundBrush(QPixmap(":/terrain.jpg")); //arriere plan
    setFixedSize(X,Y);

    QObject::connect(this, SIGNAL(jeuFini()), this, SLOT(messageFin()));

    tourDeJeu();
}

void Jeu::tourDeJeu()
{
    while (estMort(aQuiLeTour+1))
        aQuiLeTour=(aQuiLeTour+1)%nombreJoueurs;
    
    if(tanks[aQuiLeTour]->getIA() == 1) cout<<"je suis une IA"<<endl;

    //On retire et rajoute le tank pour qu'il s'affiche en dessus des autres elements du terrain
    terrain->removeItem(tanks[aQuiLeTour]);
    terrain->addItem(tanks[aQuiLeTour]);
    tanks[aQuiLeTour]->setFocus();
    terrain->update();

    //Couleur du menu selon le joueur
    QPalette p;
    switch (aQuiLeTour) {
    case 0: p.setColor(QPalette::WindowText, QColor(100,180,50));
            break;
    case 1: p.setColor(QPalette::WindowText, QColor(160,130,60));
            break;
    case 2: p.setColor(QPalette::WindowText, QColor(255,122,5));
            break;
    case 3: p.setColor(QPalette::WindowText, QColor(255,247,5));
            break;
    }

    //Création du menu à droite pour le joueur courant
    menu = new MenuJeu(this->parentWidget());
    QGraphicsProxyWidget* menuProxyWidget = terrain->addWidget(menu);
    menuProxyWidget->setPos(Y,0);   //On fait en sorte que le terrain fasse un carré de coté Y = X-(X-Y)

    //Affichage de "à qui est le tour"
    QGroupBox* textTour = new QGroupBox(QString("Tour du tank n°")+QString::number(aQuiLeTour+1),menu);
    textTour->setAlignment(Qt::AlignHCenter);
    textTour->setFont(QFont("arial",16));
    textTour->setPalette(p);

    //Affichage de l'état du tank
    QGroupBox* textCapacite = new QGroupBox("Capacité du tank");
    textCapacite->setAlignment(Qt::AlignHCenter);
    textCapacite->setFont(QFont("arial",10));
    //Affichage en temps reel de la capacité
    QLCDNumber* capacite = new QLCDNumber(this);
    capacite->setSegmentStyle(QLCDNumber::Flat);
    capacite->display(tanks[aQuiLeTour]->getCapacite());
    QObject::connect(tanks[aQuiLeTour], SIGNAL(capaciteChanged(int)), capacite, SLOT(display(int)));
    //Ajout à la vbox
    QVBoxLayout* vboxCapacite = new QVBoxLayout;
    vboxCapacite->addWidget(capacite);
    textCapacite->setLayout(vboxCapacite);
    //Affichage de la résistance
    QGroupBox* textResist = new QGroupBox("Resistance du tank");
    textResist->setAlignment(Qt::AlignHCenter);
    textResist->setFont(QFont("arial",10));
    QLCDNumber* resist = new QLCDNumber(this);
    resist->setSegmentStyle(QLCDNumber::Flat);
    resist->display(tanks[aQuiLeTour]->getResistance());
    //Ajout à la vbox
    QVBoxLayout* vboxResist = new QVBoxLayout;
    vboxResist->addWidget(resist);
    textResist->setLayout(vboxResist);

    //Positionnement canon et tir
    QGroupBox* textCanon = new QGroupBox("Choix de l'obus et tir");
    textCanon->setAlignment(Qt::AlignHCenter);
    textCanon->setFont(QFont("arial",10));
    //Obus 1
    QLabel* o1 = new QLabel(QString("Obus 1 : Rayon 1, Force 2"));
    QLCDNumber* o1Restants = new QLCDNumber(this);
    o1Restants->setSegmentStyle(QLCDNumber::Flat);
    o1Restants->display(tanks[aQuiLeTour]->getNbObus1());
    o1->setFont(QFont("arial",7));
    tirObus1 = new ButtonWidget(QStringList("O1 - TIRER"),QColor(Qt::black));
    if (tanks[aQuiLeTour]->getNbObus1()>0){
        QObject::connect(tirObus1, SIGNAL(clicked(QString)), tanks[aQuiLeTour], SLOT(tirer(QString)));
        QObject::connect(tirObus1, SIGNAL(clicked(QString)), this, SLOT(waitTir()));
    } else
        tirObus1->setDisabled(true);
    //Obus 2
    QLabel* o2 = new QLabel(QString("Obus 2 : Rayon 5, Force 5"));
    QLCDNumber* o2Restants = new QLCDNumber(this);
    o2Restants->setSegmentStyle(QLCDNumber::Flat);
    o2Restants->display(tanks[aQuiLeTour]->getNbObus2());
    o2->setFont(QFont("arial",7));
    tirObus2 = new ButtonWidget(QStringList("O2 - TIRER"),QColor(Qt::black));
    if (tanks[aQuiLeTour]->getNbObus2()>0){
        QObject::connect(tirObus2, SIGNAL(clicked(QString)), tanks[aQuiLeTour], SLOT(tirer(QString)));
        QObject::connect(tirObus2, SIGNAL(clicked(QString)), this, SLOT(waitTir()));
    } else
        tirObus2->setDisabled(true);
    //Obus 3
    QLabel* o3 = new QLabel(QString("Obus 3 : Rayon 9, Force 10"));
    QLCDNumber* o3Restants = new QLCDNumber(this);
    o3Restants->setSegmentStyle(QLCDNumber::Flat);
    o3Restants->display(tanks[aQuiLeTour]->getNbObus3());
    o3->setFont(QFont("arial",7));
    tirObus3 = new ButtonWidget(QStringList("O3 - TIRER"),QColor(Qt::black));
    if (tanks[aQuiLeTour]->getNbObus3()>0){
        QObject::connect(tirObus3, SIGNAL(clicked(QString)), tanks[aQuiLeTour], SLOT(tirer(QString)));
        QObject::connect(tirObus3, SIGNAL(clicked(QString)), this, SLOT(waitTir()));
    } else
        tirObus3->setDisabled(true);
    //Ajout à la vbox
    QVBoxLayout* vboxObus = new QVBoxLayout;
    vboxObus->addWidget(o1);
    vboxObus->addWidget(o1Restants);
    vboxObus->addWidget(tirObus1);
    vboxObus->addWidget(o2);
    vboxObus->addWidget(o2Restants);
    vboxObus->addWidget(tirObus2);
    vboxObus->addWidget(o3);
    vboxObus->addWidget(o3Restants);
    vboxObus->addWidget(tirObus3);
    textCanon->setLayout(vboxObus);

    //Vbox Menu à droite global d'un tour
    QVBoxLayout* vboxTour = new QVBoxLayout;
    vboxTour->addWidget(textCapacite);
    vboxTour->addWidget(textResist);
    vboxTour->addWidget(textCanon);
    textTour->setLayout(vboxTour);
    textTour->setMaximumWidth(X-Y-18);
    menu->getLayout()->addWidget(textTour,1,0);

    //Passage au prochain joueur (s'il n'est pas mort)
    int prochain = (aQuiLeTour+1)%nombreJoueurs;

    while (estMort(prochain+1))     //le num de joueur est augmenté de 1 (tour 0 pour le joueur 1)
        prochain = (prochain+1)%nombreJoueurs;

    if (prochain == aQuiLeTour)
        emit jeuFini();
    else
        aQuiLeTour = prochain;
}

void Jeu::waitTir(){
    tirObus1->setDisabled(true);
    tirObus2->setDisabled(true);
    tirObus3->setDisabled(true);
    QTimer::singleShot(1500,this,SLOT(tourDeJeu()));
}
void Jeu::messageFin(){
    QMessageBox::information(this,"Fin de la partie",(QString("<html><font color='white'>Le joueur n° </font></html>")+QString::number(aQuiLeTour+1)+QString("<html><font color='white'> a remporté la partie</font></html>")),"QUITTER");
    (dynamic_cast<Menu*>(parentWidget()))->quitterJeu();
    delete tanks[aQuiLeTour];
}
Terrain* Jeu::getTerrain(){
    return terrain;
}
Tank* Jeu::getTankCourant(){
    if (aQuiLeTour == 0)
        return tanks[nombreJoueurs-1];
    return tanks[aQuiLeTour-1];
}
void Jeu::setJoueurMort(int numJoueur){
    joueursMorts.push_back(numJoueur);
}
bool Jeu::estMort(int numJoueur){
    for (unsigned int i = 0 ; i<joueursMorts.size() ; i++)
        if (joueursMorts[i] == numJoueur)
            return true;
    return false;
}

Jeu::~Jeu()
{
    delete tanks;
    delete terrain;
    delete menu;
    delete tirObus1;
    delete tirObus2;
    delete tirObus3;
}
