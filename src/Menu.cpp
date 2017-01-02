#include "../head/Menu.h"

Jeu* J;

Menu::Menu() : QWidget()
{
    setFixedSize(X,Y);
    setStyleSheet("background-image: url(:/bg.jpg); ");
    QGridLayout *layout = new QGridLayout;

    //Ajout du logo
    QLabel* logo = new QLabel(this);
    logo->setPixmap(QPixmap(":/logo.png"));
    logo->setAlignment(Qt::AlignHCenter);
    layout->addWidget(logo,0,1);

    //Ajout des boutons
    QStringList texts;
    texts.append("1 JOUEUR");
    texts.append("2 JOUEURS");
    texts.append("3 JOUEURS");
    texts.append("4 JOUEURS");
    boutons = new ButtonWidget(texts, QColor(Qt::white), this);
    layout->addWidget(boutons,1,1);

    setLayout(layout);

    //Utilisation de la classe ButtonWidget pour permettre de passer le texte du bouton en parametre au slot
    QObject::connect(boutons, SIGNAL(clicked(QString)), this, SLOT(lancerJeu(QString)));

}

void Menu::lancerJeu(QString nbJoueurs)
{
    int nbJr = nbJoueurs[0].digitValue();
        J = new Jeu(nbJr,this);
    J->show();
}

void Menu::quitterJeu(){
    J->hide();
}

void Menu::paintEvent(QPaintEvent *pe){
  QStyleOption o;
  o.initFrom(this);
  QPainter p(this);
  style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
}

Menu::~Menu(){
    delete boutons;
}
