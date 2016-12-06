#include "../head/Tank.h"

int X = 800;
int Y = 600;

int pgcd(int a, int b)
{
    if (a == b) return a;
    if (a > b)  return pgcd(a-b,b);
                return pgcd(a,b-a);
}

int calculUnite()
{
    cout << X << "x" << Y << endl;
    if (pgcd(X,Y)%2 == 0)
        return pgcd(X,Y)/2;
    if (pgcd(X,Y)%3 == 0)
        return pgcd(X,Y)/3;
    else return pgcd(X,Y);
}

Tank::Tank(int indiceJoueur, QGraphicsItem *parent) : QGraphicsPixmapItem(parent), O1(1), O2(2), O3(3)
{
    //Insertion de l'image du tank
    QPixmap imageTank(":/tank1.png");
    imageTank = imageTank.scaled(X/7,Y/7, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    setPixmap(imageTank);

    //Positionnement du tank
    int rayonTank = boundingRect().width()/2;
    setTransformOriginPoint(rayonTank,rayonTank);

    switch (indiceJoueur)
    {
        case 1 :
            setRotation(rotation()+180);
            direction = DROITE;
            setPos(X/100,Y/2 - rayonTank);
            break;
        case 2 :
            direction = GAUCHE;
            setPos(X- X/100 - rayonTank*2,Y/2 - rayonTank);
            break;
    }

}

Point Tank::getPosition()
{
    Point pos(x(),y());
    return pos;
}

void Tank::keyPressEvent(QKeyEvent *event)
{
    int uniteDeplacement = X/140;

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
        else if (getPosition().getX()-uniteDeplacement >= 0)
            setPos(x()-uniteDeplacement,y());
        direction = GAUCHE;
    }
    else if (event->key() == Qt::Key_Right){
        if (direction == HAUT)
            setRotation(rotation()+90);
        else if (direction == BAS)
            setRotation(rotation()-90);
        else if (direction == GAUCHE)
            setRotation(rotation()+180);
        else if (getPosition().getX()+2*rayonTank+uniteDeplacement <= X)
            setPos(x()+uniteDeplacement,y());
        direction = DROITE;
    }
    else if (event->key() == Qt::Key_Up){
        if (direction == DROITE)
            setRotation(rotation()-90);
        else if (direction == BAS)
            setRotation(rotation()+180);
        else if (direction == GAUCHE)
            setRotation(rotation()+90);
        else if (getPosition().getY()-uniteDeplacement >= 0)
            setPos(x(),y()-uniteDeplacement);
        direction = HAUT;
    }
    else if (event->key() == Qt::Key_Down){
        if (direction == HAUT)
            setRotation(rotation()+180);
        else if (direction == DROITE)
            setRotation(rotation()+90);
        else if (direction == GAUCHE)
            setRotation(rotation()-90);
        else if (getPosition().getY()+2*rayonTank-uniteDeplacement <= Y)
            setPos(x(),y()+uniteDeplacement);
        direction = BAS;
    }
    /*
    else if (event->key() == Qt::Key_Space){
        // creation obus
        Obus* ob = new Obus();
        ob->setPos(x(),y());
        scene()->addItem(ob);

        O3.tirer(20);
    }
    */
}

void Tank::adapter(QSize nouvelleTaille, QSize ancienneTaille)
{
    setPixmap(pixmap().scaled(nouvelleTaille.width()/7,nouvelleTaille.height()/7, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    setPos(nouvelleTaille.width()*x()/ancienneTaille.width(),nouvelleTaille.height()*y()/ancienneTaille.height());
}
