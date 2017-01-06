#include <QtTest/QtTest>
#include "../head/Point.h"
#include "../head/Canon.h"
#include "../head/Obstacle.h"

// pour executer les tests :
//cd tests/
//qmake testtank.pro
//make
//../bin/tests

//j'ai fait pour Point et Canon

class TestTank: public QObject
{
    Q_OBJECT
private slots:
    void getX();
    void setX();
    void getY();
    void setY();
    void getAngleH();
    void setAngleH();
    void getAngleV();
    void setAngleV();
    void getResistance();
    void decrementeResistance();
};

// Tests pour point
void TestTank::getX() { 
    Point p(0, 1);
    QCOMPARE(p.getX(), 0);
}
void TestTank::setX() {
    Point p(0, 0);
    p.setX(1);
    QCOMPARE(p.getX(), 1);
}
void TestTank::getY() {
    Point p(1, 0);
    QCOMPARE(p.getY(), 0);
}
void TestTank::setY() {
    Point p(0, 0);
    p.setY(1);
    QCOMPARE(p.getY(), 1);
}
// Tests pour Canon
void TestTank::getAngleH() { 
    Canon c(HAUT);
    QCOMPARE(c.getAngleH(), 0.0);
}
void TestTank::setAngleH() { 
    Canon c(HAUT);
    c.setAngleH(1.0);
    QCOMPARE(1.0, 1.0);
}
void TestTank::getAngleV() { 
    Canon c(HAUT);
    QCOMPARE(c.getAngleV(), 1.0);
}
void TestTank::setAngleV() { 
    Canon c(HAUT);
    c.setAngleV(1.0);
    QCOMPARE(1.0, 1.0);
}
// Tests pour Obstacle
void TestTank::getResistance() { 
    Obstacle o(ARBRE,Point(0,0),0);
    QCOMPARE(o.getResistance(), 1);
}
void TestTank::decrementeResistance() { 
    Obstacle o(ROCHER,Point(0,0),0);
    o.decrementeResistance(4);
    QCOMPARE(o.getResistance(), 3);
}


QTEST_MAIN(TestTank)
#include "testtank.moc"
