#include "../head/MenuJeu.h"

MenuJeu::MenuJeu() : QWidget()
{
    setGeometry(0,0,X-Y,Y);
    QGridLayout *layout = new QGridLayout;

    ButtonWidget* quit = new ButtonWidget(QStringList("QUITTER"),QColor(Qt::black));

    layout->addWidget(quit,1,1);

    setLayout(layout);

    QObject::connect(quit, SIGNAL(clicked(QString)), this, SLOT(quitter()));
}

void MenuJeu::quitter()
{
    hide();
}
