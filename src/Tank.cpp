#include "../head/Tank.h"

//Unité de déplacement de 5 pixels au minimum car Y vaut 600 au minimum
const int uniteDeplacement = Y/120;

Tank::Tank(int num, Terrain* t, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), nbObus1(10), nbObus2(3), nbObus3(2)
{
    capaciteDeplacement = Y/2;
    resistance = 20;
    numJoueur = num;
    terrain = t;

    //Insertion de l'image du tank et du canon
    QPixmap* imageTank;
    QPixmap* imageCanon;

    switch (numJoueur){
        case 1 :
            imageTank = new QPixmap(":/tank1.png");
            imageCanon = new QPixmap(":/canon1.png");
            *imageTank = imageTank->scaled(Y/8,Y/8, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            setPixmap(*imageTank);
            *imageCanon = imageCanon->scaled(Y/8,Y/8, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            setRotation(rotation()+180);
            direction = DROITE;
            setPos(Y/120,Y/2 - (getRayon() - (getRayon()%5)));
            break;
        case 2 :
            imageTank = new QPixmap(":/tank2.png");
            imageCanon = new QPixmap(":/canon2.png");
            *imageTank = imageTank->scaled(Y/8,Y/8, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            setPixmap(*imageTank);
            *imageCanon = imageCanon->scaled(Y/8,Y/8, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            direction = GAUCHE;
            setPos(Y - Y/120 - (getRayon() - (getRayon()%5))*2, Y/2 - (getRayon() - (getRayon()%5)));
            break;
        case 3 :
            imageTank = new QPixmap(":/tank3.png");
            imageCanon = new QPixmap(":/canon3.png");
            *imageTank = imageTank->scaled(Y/8,Y/8, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            setPixmap(*imageTank);
            *imageCanon = imageCanon->scaled(Y/8,Y/8, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            setRotation(rotation()+90);
            direction = HAUT;
            setPos(Y/2 - (getRayon() - (getRayon()%5)),Y - Y/120 - (getRayon() - (getRayon()%5))*2);
            break;
        case 4 :
            imageTank = new QPixmap(":/tank4.png");
            imageCanon = new QPixmap(":/canon4.png");
            *imageTank = imageTank->scaled(Y/8,Y/8, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            setPixmap(*imageTank);
            *imageCanon = imageCanon->scaled(Y/8,Y/8, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            setRotation(rotation()-90);
            direction = BAS;
            setPos(Y/2 - (getRayon() - (getRayon()%5)),Y/120);
            break;
    }
    setTransformOriginPoint(getRayon(),getRayon());

    //Création du canon
    canon = new Canon(direction, this);
    canon->setFlag(QGraphicsItem::ItemIsFocusable);
    canon->setPixmap(*imageCanon);
    canon->setX(canon->x()-getRayon()/4);
}

void Tank::keyPressEvent(QKeyEvent *event)
{
    setTransformOriginPoint(getRayon(),getRayon());

    if (event->key() == Qt::Key_Left && capaciteDeplacement>0){
        if (direction == HAUT){
            setRotation(rotation()-90);
            canon->setAngleHAbsolu(canon->getAngleHAbsolu()+90);
        }
        else if (direction == BAS){
            setRotation(rotation()+90);
            canon->setAngleHAbsolu(canon->getAngleHAbsolu()-90);
        }
        else if (direction == DROITE){
            setRotation(rotation()+180);
            canon->setAngleHAbsolu(canon->getAngleHAbsolu()-180);
        }
        else if
        (getPosition().getX()-uniteDeplacement >= 0
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
    }
    else if (event->key() == Qt::Key_Right && capaciteDeplacement>0){
        if (direction == HAUT){
            setRotation(rotation()+90);
            canon->setAngleHAbsolu(canon->getAngleHAbsolu()-90);
        }
        else if (direction == BAS){
            setRotation(rotation()-90);
            canon->setAngleHAbsolu(canon->getAngleHAbsolu()+90);
        }
        else if (direction == GAUCHE){
            setRotation(rotation()+180);
            canon->setAngleHAbsolu(canon->getAngleHAbsolu()+180);
        }
        else if (getPosition().getX()+2*getRayon()+uniteDeplacement <= Y
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
    }
    else if (event->key() == Qt::Key_Up && capaciteDeplacement>0){
        if (direction == DROITE){
            setRotation(rotation()-90);
            canon->setAngleHAbsolu(canon->getAngleHAbsolu()+90);
        }
        else if (direction == BAS){
            setRotation(rotation()+180);
            canon->setAngleHAbsolu(canon->getAngleHAbsolu()-180);
        }
        else if (direction == GAUCHE){
            setRotation(rotation()+90);
            canon->setAngleHAbsolu(canon->getAngleHAbsolu()-90);
        }
        else if (getPosition().getY()-uniteDeplacement >= 0
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
    }
    else if (event->key() == Qt::Key_Down && capaciteDeplacement>0){
        if (direction == HAUT){
            setRotation(rotation()+180);
            canon->setAngleHAbsolu(canon->getAngleHAbsolu()-180);
        }
        else if (direction == DROITE){
            setRotation(rotation()+90);
            canon->setAngleHAbsolu(canon->getAngleHAbsolu()-90);
        }
        else if (direction == GAUCHE){
            setRotation(rotation()-90);
            canon->setAngleHAbsolu(canon->getAngleHAbsolu()+90);
        }
        else if (getPosition().getY()+2*getRayon()+uniteDeplacement <= Y
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
    }

    //On supprimer le tank courant du terrain puis on insrit sa nouvelle position
    switch (numJoueur) {
        case 1: terrain->vider(TANK1); terrain->updateCases(getPosition(),TANK1,getRayon()); break;
        case 2: terrain->vider(TANK2); terrain->updateCases(getPosition(),TANK2,getRayon()); break;
        case 3: terrain->vider(TANK3); terrain->updateCases(getPosition(),TANK3,getRayon()); break;
        case 4: terrain->vider(TANK4); terrain->updateCases(getPosition(),TANK4,getRayon()); break;
    }

    cout << getPosition().getX() << ", " << getPosition().getY() << endl;

    //##################### Mouvement du canon
    canon->setTransformOriginPoint(getRayon()+getRayon()/4+10,getRayon()+1);
    if (event->key() == Qt::Key_Q){
        canon->setRotation(canon->getAngleH()-1);
        canon->setAngleH(canon->getAngleH()-1);
        canon->setAngleHAbsolu(canon->getAngleHAbsolu()+1);
    }
    if (event->key() == Qt::Key_D){
        canon->setRotation(canon->getAngleH()+1);
        canon->setAngleH(canon->getAngleH()+1);
        canon->setAngleHAbsolu(canon->getAngleHAbsolu()-1);
    }
    if (event->key() == Qt::Key_Z && canon->getAngleVAbsolu() <= 80){
        canon->setAngleV(canon->getAngleV()+0.1);
        canon->setAngleVAbsolu(canon->getAngleVAbsolu()+10);
        canon->setScale(canon->getAngleV());
    }
    if (event->key() == Qt::Key_S && canon->getAngleVAbsolu() >= 10){
        canon->setAngleV(canon->getAngleV()-0.1);
        canon->setAngleVAbsolu(canon->getAngleVAbsolu()-10);
        canon->setScale(canon->getAngleV());
    }
    cout << "AngleVAbsolu " << canon->getAngleVAbsolu() << endl;
}

void Tank::tirer(QString typeObus){
    int type = typeObus[1].digitValue();
    switch (type) {
        case 1: nbObus1--; break;
        case 2: nbObus2--; break;
        case 3: nbObus3--; break;
    }
    Obus* ob = new Obus(type,canon->getAngleHAbsolu(), canon->getAngleVAbsolu());
    //JE TE LAISSE AJUSTER LE POINT D'ORIGINE DE L'OBUS
    ob->setPos(x()+getRayon()-uniteDeplacement,y()+getRayon()-uniteDeplacement);
    terrain->addItem(ob);
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
void Tank::decrementeResistance(int forceObus){
    resistance-=forceObus;
}
int Tank::getResistance(){
    return resistance;
}
int Tank::getNumJoueur(){
    return numJoueur;
}

void Tank::adapter(QSize nouvelleTaille, QSize ancienneTaille)
{
    setPixmap(pixmap().scaled(nouvelleTaille.width()/7,nouvelleTaille.height()/7, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    setPos(nouvelleTaille.width()*x()/ancienneTaille.width(),nouvelleTaille.height()*y()/ancienneTaille.height());
}
