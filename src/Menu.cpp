#include "../head/Menu.h"

Menu::Menu() : QWidget()
{
    setFixedSize(X,Y);
    setStyleSheet("background-image: url(:/bg.jpg)");

    int largeur = X/2;
    int hauteur = Y/20;

    QLabel* logo = new QLabel(this);
    logo->setPixmap(QPixmap(":/logo.png"));
    logo->setAlignment(Qt::AlignHCenter);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(logo);
    setLayout(layout);

    QPushButton* b1 = new QPushButton("1 JOUEUR", this);
    QPushButton* b2 = new QPushButton("2 JOUEURS", this);
    QPushButton* b3 = new QPushButton("3 JOUEURS", this);
    QPushButton* b4 = new QPushButton("4 JOUEURS", this);
    QPalette p;
    p.setColor(QPalette::ButtonText, QColor(Qt::white));

    b1->setCursor(Qt::PointingHandCursor);
    b1->setGeometry(X/2-largeur/2,Y/2-hauteur,largeur,hauteur);
    b1->setFont(QFont("Calibri", X/57));
    b1->setPalette(p);

    b2->setCursor(Qt::PointingHandCursor);
    b2->setGeometry(X/2-largeur/2,Y/2+hauteur,largeur,hauteur);
    b2->setFont(QFont("Calibri", X/57));
    b2->setPalette(p);

    b3->setCursor(Qt::PointingHandCursor);
    b3->setGeometry(X/2-largeur/2,Y/2+3*hauteur,largeur,hauteur);
    b3->setFont(QFont("Calibri", X/57));
    b3->setPalette(p);

    b4->setCursor(Qt::PointingHandCursor);
    b4->setGeometry(X/2-largeur/2,Y/2+5*hauteur,largeur,hauteur);
    b4->setFont(QFont("Calibri", X/57));
    b4->setPalette(p);

}
