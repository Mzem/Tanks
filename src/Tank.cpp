#include "../head/Tank.h"

//Unité de déplacement de 5 pixels au minimum car Y vaut 600 au minimum
const int uniteDeplacement = Y/120;

Tank::Tank(int num, Terrain* t, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), canon(direction, this), nbObus1(10), nbObus2(3), nbObus3(2)
{
    numJoueur = num;
    terrain = t;

    //Insertion de l'image du tank et du canon
    QPixmap imageTank(":/tank1.png");
    QPixmap imageCanon(":/canon1.png");
    imageTank = imageTank.scaled(Y/8,Y/8, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    setPixmap(imageTank);
    imageCanon = imageCanon.scaled(Y/8,Y/8, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    canon.setPixmap(imageCanon);

    //Positionnement du tank et du canon
    setTransformOriginPoint(getRayon(),getRayon());
    canon.setTransformOriginPoint(canon.boundingRect().width()/3,canon.boundingRect().height());
    canon.setX(x()-getRayon()/4);

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
}

Point Tank::getPosition(){
    Point pos(x(),y());
    return pos;
}

int Tank::getRayon(){
    return boundingRect().height()/2;
}

void Tank::keyPressEvent(QKeyEvent *event)
{
    setTransformOriginPoint(getRayon(),getRayon());

    if (event->key() == Qt::Key_Left){
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
            setPos(x(),y()+uniteDeplacement);
        direction = BAS;
    }
    else if (event->key() == Qt::Key_Space){
        //Creation obus
        Obus* ob = new Obus(1,canon.getAngleH(), canon.getAngleV());
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

void Tank::adapter(QSize nouvelleTaille, QSize ancienneTaille)
{
    setPixmap(pixmap().scaled(nouvelleTaille.width()/7,nouvelleTaille.height()/7, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    setPos(nouvelleTaille.width()*x()/ancienneTaille.width(),nouvelleTaille.height()*y()/ancienneTaille.height());
}
