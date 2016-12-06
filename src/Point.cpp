#include "../head/Point.h"

Point::Point() : x(0), y(0) {}

Point::Point(int a, int b) : x(a), y(b) {}

int Point::getX() {return x;}

int Point::getY() {return y;}

void Point::setX(int a) {x = a;}

void Point::setY(int b) {y = b;}
