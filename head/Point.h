#ifndef POINT_H
#define POINT_H


class Point
{
    private:
        int x;
        int y;

    public:
        Point();
        Point(int,int);
        int getX();
        int getY();
        void setX(int);
        void setY(int);
};

#endif // POINT_H
