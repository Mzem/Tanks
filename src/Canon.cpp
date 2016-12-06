#include "../head/Canon.h"

Canon::Canon()
{
    angleH = 0;
    angleV = 0;
}

int Canon::getAngleH()
{
    return angleH;
}

int Canon::getAngleV()
{
    return angleV;
}

void Canon::rotationH(int angle)
{
    angleH = (angleH + angle) % 360;
}

void Canon::rotationV(int angle)
{
    angleV = (angleV + angle) % 360;
}
