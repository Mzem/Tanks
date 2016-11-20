#include "../head/Fenetre.h"

//Dimensions initiales de la fenetre
#define X 600
#define Y 400

Fenetre::Fenetre()
{
    Tank* T1 = new Tank(X,Y);

    QPixmap imageTank(":/tank1.png");   //Utilisation d'un fichier .qrc
    imageTank = imageTank.scaled(X/7,Y/7, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    T1->setPixmap(imageTank);

    this->addItem(T1);

    T1->setFlag(QGraphicsItem::ItemIsFocusable);
    T1->setFocus(); //Rendre le Tank "focusable" pour qu'il puisse bouger

    // Creation d'une vue pour visualiser la fenetre
    vue = new QGraphicsView(this);
    vue->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vue->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vue->resize(X,Y);
    vue->setBackgroundBrush(QBrush(Qt::darkRed, Qt::Dense4Pattern));

}

QGraphicsView* Fenetre::getVue()
{
    return vue;
}

void Fenetre::resizeEvent(QResizeEvent * event)
{
    cout << "HERE" << endl;
}
