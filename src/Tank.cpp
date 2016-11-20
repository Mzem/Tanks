#include "../head/Tank.h"

Tank::Tank(int largeurFenetre, int hauteurFenetre)
 : champ(largeurFenetre,hauteurFenetre)
{
    direction = GAUCHE;
}

//L'image du tank doit etre un carré, afin d'eviter les problemes pour tourner qd il se trouve dans un coin
void Tank::keyPressEvent(QKeyEvent *event)
{
    int uniteDeplacement = champ.getX()/140;
    int rayonTank = boundingRect().width()/2;

    setTransformOriginPoint(rayonTank,rayonTank);
    cout << getPosition().getX() << ", " <<getPosition().getY() << endl;

    if (event->key() == Qt::Key_Left){
        if (direction == HAUT)
            setRotation(rotation()-90);
        else if (direction == BAS)
            setRotation(rotation()+90);
        else if (direction == DROITE)
            setRotation(rotation()+180);
        direction = GAUCHE;
        setPos(x()-uniteDeplacement,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (direction == HAUT)
            setRotation(rotation()+90);
        else if (direction == BAS)
            setRotation(rotation()-90);
        else if (direction == GAUCHE)
            setRotation(rotation()+180);
        direction = DROITE;
        setPos(x()+uniteDeplacement,y());
    }
    else if (event->key() == Qt::Key_Up){
        if (direction == DROITE)
            setRotation(rotation()-90);
        else if (direction == BAS)
            setRotation(rotation()+180);
        else if (direction == GAUCHE)
            setRotation(rotation()+90);
        direction = HAUT;
        setPos(x(),y()-uniteDeplacement);
    }
    else if (event->key() == Qt::Key_Down){
        if (direction == HAUT)
            setRotation(rotation()+180);
        else if (direction == DROITE)
            setRotation(rotation()+90);
        else if (direction == GAUCHE)
            setRotation(rotation()-90);
        direction = BAS;
        setPos(x(),y()+uniteDeplacement);
    }
    /*
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Obus* ob = new Obus();
        ob->setPos(x(),y());
        scene()->addItem(ob);
    }
    */
}

Point Tank::getPosition()
{
    Point pos(x(),y());
    return pos;
}
