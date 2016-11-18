#include "../head/Fenetre.h"

//Dimensions de la fenetre
#define X 800
#define Y 600

Fenetre::Fenetre()
{
    // Creation d'une scene (fenetre)
    QGraphicsScene * scene = new QGraphicsScene(qreal(0),qreal(0),qreal(X),qreal(Y));

    // Creation des tanks
    Tank* T1 = new Tank();
    T1->setRect(0,0,100,100); // modif taille rectangle du tank

    // Ajout des tanks à la scene
    scene->addItem(T1);

    // Rendre le Tank "focusable" pour qu'il puisse bouger
    T1->setFlag(QGraphicsItem::ItemIsFocusable);
    T1->setFocus();

    // Creation d'une vue pour visualiser la fenetre
    QGraphicsView* vue = new QGraphicsView(scene);

    vue->show();

}
