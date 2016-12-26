#include "../head/Terrain.h"

//Le terrain est un carré de coté Y, le tank est un carré de coté Y/8, une case a la taille d'un tank
const int tailleCase = Y/8;

Terrain::Terrain(QWidget* parent) : QGraphicsScene(parent)
{
    //Initialisation des cases à VIDE
    for (int i = 0 ; i<8 ; i++)
        for (int j = 0 ; j<8 ; j++)
            cases[i][j] = VIDE;
}

void Terrain::updateCases(Point coordElement, ELEMENTS elem, int rayonTank)
{
    int i, j;

    if (elem == TANK1 || elem == TANK2 || elem == TANK3 || elem == TANK4)
    {
        i = (coordElement.getX())/tailleCase;
        j = (coordElement.getY())/tailleCase;
        cases[i][j] = elem;
        j = (coordElement.getY()+2*rayonTank)/tailleCase;
        cases[i][j] = elem;
        i = (coordElement.getX()+2*rayonTank)/tailleCase;
        cases[i][j] = elem;
        j = (coordElement.getY())/tailleCase;
        cases[i][j] = elem;
    }
    else
        cases[(coordElement.getX())/tailleCase][(coordElement.getY())/tailleCase] = elem;
}

void Terrain::vider(ELEMENTS elem)
{
    for (int i = 0 ; i<8 ; i++)
        for (int j = 0 ; j<8 ; j++)
            if (cases[i][j] == elem)
                cases[i][j] = VIDE;
}

void Terrain::impact(Point ptImpact){
    //modif cases
}

ELEMENTS Terrain::getCases(int i, int j)
{
    return cases[i][j];
}

//[debug] Affichage des cases du terrain et leur contenu
void Terrain::affiche(){
    for (int i = 0 ; i<8 ; i++){
        addLine(i*tailleCase,0,i*tailleCase,Y);
        addLine(0,i*tailleCase,Y,i*tailleCase);
    }
    QGraphicsTextItem* txt;
    for (int i = 0 ; i<8 ; i++)
        for (int j = 0 ; j<8 ; j++){
            switch (cases[i][j]){
                case VIDE : txt = addText("V");
                            txt->setPos(i*tailleCase+tailleCase/2,j*tailleCase+tailleCase/2);
                            break;
                case TANK1 : txt = addText("T1");
                            txt->setPos(i*tailleCase+tailleCase/2,j*tailleCase+tailleCase/2);
                            break;
                case TANK2 : txt = addText("T2");
                            txt->setPos(i*tailleCase+tailleCase/2,j*tailleCase+tailleCase/2);
                            break;
                case TANK3 : txt = addText("T3");
                            txt->setPos(i*tailleCase+tailleCase/2,j*tailleCase+tailleCase/2);
                            break;
                case TANK4 : txt = addText("T4");
                            txt->setPos(i*tailleCase+tailleCase/2,j*tailleCase+tailleCase/2);
                            break;
                case ROCHER : txt = addText("R");
                            txt->setPos(i*tailleCase+tailleCase/2,j*tailleCase+tailleCase/2);
                            break;
                case ARBRE : txt = addText("A");
                            txt->setPos(i*tailleCase+tailleCase/2,j*tailleCase+tailleCase/2);
                            break;
                case CREVASSE : txt = addText("C");
                            txt->setPos(i*tailleCase+tailleCase/2,j*tailleCase+tailleCase/2);
                            break;
                default : txt = addText("ERR");
                            txt->setPos(i*tailleCase+tailleCase/2,j*tailleCase+tailleCase/2);
                            break;
            }
        }
}
