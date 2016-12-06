#include <QApplication>
#include "../head/Jeu.h"
#include "../head/Menu.h"

Jeu* J;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //Menu M;
    //M.show();

    J = new Jeu(2); //2 à modifier pour gérer un nombre personnalisé de joueurs

    J->show();

    return app.exec();
}
