#include <QApplication>
#include "../head/Fenetre.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    Fenetre* F = new Fenetre();

    F->getVue()->show();

    return app.exec();
}
