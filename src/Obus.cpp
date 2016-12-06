#include "../head/Obus.h"

Obus::Obus(int t) : type(t)
{
    if (type == 1){
        rayon = 10;
        force = 2;
    }
    else if (type == 2){
        rayon = 50;
        force = 5;
    }
    else if (type == 3){
        rayon = 90;
        force = 10;
    }

    setRect(0,0,10,50);

}

/*
Point Obus::tirer(int angle) //Segment direction, int angle)
{
    Point destination(0,0);
    destination.X( (90-angle) * 3); //exemple de calcul, il faut suivre le segment
    destination.Y( (90-angle) * 3);
    cout << "Tir effectué";
    return destination;
}
*/
