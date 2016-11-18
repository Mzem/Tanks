#include <QApplication>
#include "../head/Fenetre.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    Fenetre* F = new Fenetre();



    return app.exec();
}
