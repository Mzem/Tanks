#include "../head/Obus.h"

Obus::Obus(int t) : type(t)
{
    if (type == 1){
        rayon = 10; //je mets valeurs au hasard mais unité à definir
        force = 2;
    }
    else if (type == 2){
        rayon = 50; //je mets valeurs au hasard mais unité à definir
        force = 5;
    }
    else if (type == 2){
        rayon = 90; //je mets valeurs au hasard mais unité à definir
        force = 10;
    }

    setRect(0,0,10,50); //Valeurs à changer

}
