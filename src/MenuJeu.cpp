#include "../head/MenuJeu.h"

MenuJeu::MenuJeu(QWidget* fenetre, QWidget *parent) : QWidget(parent)
{
    setGeometry(0,0,X-Y,Y);
    layout = new QGridLayout;

    ButtonWidget* quit = new ButtonWidget(QStringList("QUITTER"),QColor(Qt::black));

    layout->addWidget(quit,2,0);

    setLayout(layout);

    QObject::connect(quit, SIGNAL(clicked(QString)), fenetre, SLOT(quitterJeu()));
}

QGridLayout* MenuJeu::getLayout(){
    return layout;
}

MenuJeu::~MenuJeu(){
    delete layout;
}
