#include <QApplication>
#include "../head/Menu.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //Le jeu est lancé par le slot lancerJeu() lors d'un clic sur un bouton du menu
    Menu M;
    M.show();

    return app.exec();
}
