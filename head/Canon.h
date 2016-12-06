#ifndef CANON_H
#define CANON_H


class Canon
{
    private:
        int angleH;    //0 - 360
        int angleV;    //0 - 90

    public:
        Canon();
        int getAngleH();
        int getAngleV();
        void rotationH(int);
        void rotationV(int);
};

#endif // CANON_H
