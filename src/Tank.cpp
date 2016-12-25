#include "../head/Tank.h"

//Unité de déplacement de 5 pixels au minimum car Y vaut 600 au minimum
const int uniteDeplacement = Y/120;

Tank::Tank(int num, Terrain* t, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), nbObus1(10), nbObus2(3), nbObus3(2)
{
    capaciteDeplacement = Y/10;
    numJoueur = num;
    terrain = t;

    //Insertion de l'image du tank et du canon
    QPixmap imageTank(":/tank1.png");
    QPixmap imageCanon(":/canon1.png");
    imageTank = imageTank.scaled(Y/8,Y/8, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    setPixmap(imageTank);
    imageCanon = imageCanon.scaled(Y/8,Y/8, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    switch (numJoueur){
        case 1 :
            setRotation(rotation()+180);
            direction = DROITE;
            setPos(Y/120,Y/2 - getRayon());
            break;
        case 2 :
            direction = GAUCHE;
            setPos(Y - Y/120 - getRayon()*2,Y/2 - getRayon());
            break;
    }

    canon = new Canon(direction, this);
    canon->setFlag(QGraphicsItem::ItemIsFocusable);
    canon->setPixmap(imageCanon);

    //Positionnement du tank et du canon
    setTransformOriginPoint(getRayon(),getRayon());
    canon->setTransformOriginPoint(canon->boundingRect().width()/3,canon->boundingRect().height());
    canon->setX(canon->x()-getRayon()/4);
}

void Tank::keyPressEvent(QKeyEvent *event)
{
    setTransformOriginPoint(getRayon(),getRayon());

    if (event->key() == Qt::Key_Left && capaciteDeplacement>0){
        if (direction == HAUT)
            setRotation(rotation()-90);
        else if (direction == BAS)
            setRotation(rotation()+90);
        else if (direction == DROITE)
            setRotation(rotation()+180);
        else if
        (getPosition().getX()-uniteDeplacement > 0
        && (
            terrain->getCases((getPosition().getX()-uniteDeplacement)/tailleCase,getPosition().getY()/tailleCase) == VIDE
            || (numJoueur == 1 &&
            terrain->getCases((getPosition().getX()-uniteDeplacement)/tailleCase,getPosition().getY()/tailleCase) == TANK1
            ) || (numJoueur == 2 &&
            terrain->getCases((getPosition().getX()-uniteDeplacement)/tailleCase,getPosition().getY()/tailleCase) == TANK2
            ) || (numJoueur == 3 &&
            terrain->getCases((getPosition().getX()-uniteDeplacement)/tailleCase,getPosition().getY()/tailleCase) == TANK3
            ) || (numJoueur == 4 &&
            terrain->getCases((getPosition().getX()-uniteDeplacement)/tailleCase,getPosition().getY()/tailleCase) == TANK4
            )
        ) && (
            terrain->getCases((getPosition().getX()-uniteDeplacement)/tailleCase,(getPosition().getY()+2*getRayon())/tailleCase) == VIDE
            || (numJoueur == 1 &&
            terrain->getCases((getPosition().getX()-uniteDeplacement)/tailleCase,(getPosition().getY()+2*getRayon())/tailleCase) == TANK1
            ) || (numJoueur == 2 &&
            terrain->getCases((getPosition().getX()-uniteDeplacement)/tailleCase,(getPosition().getY()+2*getRayon())/tailleCase) == TANK2
            ) || (numJoueur == 3 &&
            terrain->getCases((getPosition().getX()-uniteDeplacement)/tailleCase,(getPosition().getY()+2*getRayon())/tailleCase) == TANK3
            ) || (numJoueur == 4 &&
            terrain->getCases((getPosition().getX()-uniteDeplacement)/tailleCase,(getPosition().getY()+2*getRayon())/tailleCase) == TANK4
            )
        ) )
        {
            setPos(x()-uniteDeplacement,y());
            capaciteDeplacement--;
            emit capaciteChanged(capaciteDeplacement);
        }
        direction = GAUCHE;
        canon->setAngleH(180);
    }
    else if (event->key() == Qt::Key_Right && capaciteDeplacement>0){
        if (direction == HAUT)
            setRotation(rotation()+90);
        else if (direction == BAS)
            setRotation(rotation()-90);
        else if (direction == GAUCHE)
            setRotation(rotation()+180);
        else if (getPosition().getX()+2*getRayon()+uniteDeplacement < Y
        && (
            terrain->getCases((getPosition().getX()+2*getRayon()+uniteDeplacement)/tailleCase,getPosition().getY()/tailleCase) == VIDE
            || (numJoueur == 1 &&
            terrain->getCases((getPosition().getX()+2*getRayon()+uniteDeplacement)/tailleCase,getPosition().getY()/tailleCase) == TANK1
            ) || (numJoueur == 2 &&
            terrain->getCases((getPosition().getX()+2*getRayon()+uniteDeplacement)/tailleCase,getPosition().getY()/tailleCase) == TANK2
            ) || (numJoueur == 3 &&
            terrain->getCases((getPosition().getX()+2*getRayon()+uniteDeplacement)/tailleCase,getPosition().getY()/tailleCase) == TANK3
            ) || (numJoueur == 4 &&
            terrain->getCases((getPosition().getX()+2*getRayon()+uniteDeplacement)/tailleCase,getPosition().getY()/tailleCase) == TANK4
            )
        ) && (
            terrain->getCases((getPosition().getX()+2*getRayon()+uniteDeplacement)/tailleCase,(getPosition().getY()+2*getRayon())/tailleCase) == VIDE
            || (numJoueur == 1 &&
            terrain->getCases((getPosition().getX()+2*getRayon()+uniteDeplacement)/tailleCase,(getPosition().getY()+2*getRayon())/tailleCase) == TANK1
            ) || (numJoueur == 2 &&
            terrain->getCases((getPosition().getX()+2*getRayon()+uniteDeplacement)/tailleCase,(getPosition().getY()+2*getRayon())/tailleCase) == TANK2
            ) || (numJoueur == 3 &&
            terrain->getCases((getPosition().getX()+2*getRayon()+uniteDeplacement)/tailleCase,(getPosition().getY()+2*getRayon())/tailleCase) == TANK3
            ) || (numJoueur == 4 &&
            terrain->getCases((getPosition().getX()+2*getRayon()+uniteDeplacement)/tailleCase,(getPosition().getY()+2*getRayon())/tailleCase) == TANK4
            )
        ) )
        {
            setPos(x()+uniteDeplacement,y());
            capaciteDeplacement--;
            emit capaciteChanged(capaciteDeplacement);
        }
        direction = DROITE;
        canon->setAngleH(0);
    }
    else if (event->key() == Qt::Key_Up && capaciteDeplacement>0){
        if (direction == DROITE)
            setRotation(rotation()-90);
        else if (direction == BAS)
            setRotation(rotation()+180);
        else if (direction == GAUCHE)
            setRotation(rotation()+90);
        else if (getPosition().getY()-uniteDeplacement > 0
        && (
            terrain->getCases(getPosition().getX()/tailleCase,(getPosition().getY()-uniteDeplacement)/tailleCase) == VIDE
            || (numJoueur == 1 &&
            terrain->getCases(getPosition().getX()/tailleCase,(getPosition().getY()-uniteDeplacement)/tailleCase) == TANK1
            ) || (numJoueur == 2 &&
            terrain->getCases(getPosition().getX()/tailleCase,(getPosition().getY()-uniteDeplacement)/tailleCase) == TANK2
            ) || (numJoueur == 3 &&
            terrain->getCases(getPosition().getX()/tailleCase,(getPosition().getY()-uniteDeplacement)/tailleCase) == TANK3
            ) || (numJoueur == 4 &&
            terrain->getCases(getPosition().getX()/tailleCase,(getPosition().getY()-uniteDeplacement)/tailleCase) == TANK4
            )
        ) && (
            terrain->getCases((getPosition().getX()+2*getRayon())/tailleCase,(getPosition().getY()-uniteDeplacement)/tailleCase) == VIDE
            || (numJoueur == 1 &&
            terrain->getCases((getPosition().getX()+2*getRayon())/tailleCase,(getPosition().getY()-uniteDeplacement)/tailleCase) == TANK1
            ) || (numJoueur == 2 &&
            terrain->getCases((getPosition().getX()+2*getRayon())/tailleCase,(getPosition().getY()-uniteDeplacement)/tailleCase) == TANK2
            ) || (numJoueur == 3 &&
            terrain->getCases((getPosition().getX()+2*getRayon())/tailleCase,(getPosition().getY()-uniteDeplacement)/tailleCase) == TANK3
            ) || (numJoueur == 4 &&
            terrain->getCases((getPosition().getX()+2*getRayon())/tailleCase,(getPosition().getY()-uniteDeplacement)/tailleCase) == TANK4
            )
        ) )
        {
            setPos(x(),y()-uniteDeplacement);
            capaciteDeplacement--;
            emit capaciteChanged(capaciteDeplacement);
        }
        direction = HAUT;
        canon->setAngleH(90);
    }
    else if (event->key() == Qt::Key_Down && capaciteDeplacement>0){
        if (direction == HAUT)
            setRotation(rotation()+180);
        else if (direction == DROITE)
            setRotation(rotation()+90);
        else if (direction == GAUCHE)
            setRotation(rotation()-90);
        else if (getPosition().getY()+2*getRayon()+uniteDeplacement < Y-2
        && (
            terrain->getCases(getPosition().getX()/tailleCase,(getPosition().getY()+2*getRayon()+uniteDeplacement)/tailleCase) == VIDE
            || (numJoueur == 1 &&
            terrain->getCases(getPosition().getX()/tailleCase,(getPosition().getY()+2*getRayon()+uniteDeplacement)/tailleCase) == TANK1
            ) || (numJoueur == 2 &&
            terrain->getCases(getPosition().getX()/tailleCase,(getPosition().getY()+2*getRayon()+uniteDeplacement)/tailleCase) == TANK2
            ) || (numJoueur == 3 &&
            terrain->getCases(getPosition().getX()/tailleCase,(getPosition().getY()+2*getRayon()+uniteDeplacement)/tailleCase) == TANK3
            ) || (numJoueur == 4 &&
            terrain->getCases(getPosition().getX()/tailleCase,(getPosition().getY()+2*getRayon()+uniteDeplacement)/tailleCase) == TANK4
            )
        ) && (
            terrain->getCases((getPosition().getX()+2*getRayon())/tailleCase,(getPosition().getY()+2*getRayon()+uniteDeplacement)/tailleCase) == VIDE
            || (numJoueur == 1 &&
            terrain->getCases((getPosition().getX()+2*getRayon())/tailleCase,(getPosition().getY()+2*getRayon()+uniteDeplacement)/tailleCase) == TANK1
            ) || (numJoueur == 2 &&
            terrain->getCases((getPosition().getX()+2*getRayon())/tailleCase,(getPosition().getY()+2*getRayon()+uniteDeplacement)/tailleCase) == TANK2
            ) || (numJoueur == 3 &&
            terrain->getCases((getPosition().getX()+2*getRayon())/tailleCase,(getPosition().getY()+2*getRayon()+uniteDeplacement)/tailleCase) == TANK3
            ) || (numJoueur == 4 &&
            terrain->getCases((getPosition().getX()+2*getRayon())/tailleCase,(getPosition().getY()+2*getRayon()+uniteDeplacement)/tailleCase) == TANK4
            )
        ) )
        {
            setPos(x(),y()+uniteDeplacement);
            capaciteDeplacement--;
            emit capaciteChanged(capaciteDeplacement);
        }
        direction = BAS;
        canon->setAngleH(270);
    }
    else if (event->key() == Qt::Key_Space){
        //Creation obus
        Obus* ob = new Obus(3,canon->getAngleH(), canon->getAngleV());
        ob->setPos(x(),y());
        terrain->addItem(ob);
    }

    //On supprimer le tank courant du terrain puis on insrit sa nouvelle position
    switch (numJoueur) {
        case 1: terrain->vider(TANK1); terrain->updateCases(getPosition(),TANK1,getRayon()); break;
        case 2: terrain->vider(TANK2); terrain->updateCases(getPosition(),TANK2,getRayon()); break;
        case 3: terrain->vider(TANK3); terrain->updateCases(getPosition(),TANK3,getRayon()); break;
        case 4: terrain->vider(TANK4); terrain->updateCases(getPosition(),TANK4,getRayon()); break;
    }

    cout << getPosition().getX() << ", " << getPosition().getY() << endl;
    //terrain->affiche();
}

Point Tank::getPosition(){
    Point pos(x(),y());
    return pos;
}
int Tank::getRayon(){
    return boundingRect().height()/2;
}
Canon* Tank::getCanon(){
    return canon;
}
int Tank::getCapacite(){
    return capaciteDeplacement;
}
int Tank::getNbObus1(){
    return nbObus1;
}
int Tank::getNbObus2(){
    return nbObus2;
}
int Tank::getNbObus3(){
    return nbObus3;
}

void Tank::adapter(QSize nouvelleTaille, QSize ancienneTaille)
{
    setPixmap(pixmap().scaled(nouvelleTaille.width()/7,nouvelleTaille.height()/7, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    setPos(nouvelleTaille.width()*x()/ancienneTaille.width(),nouvelleTaille.height()*y()/ancienneTaille.height());
}
