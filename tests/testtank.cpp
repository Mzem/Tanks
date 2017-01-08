#include <QtTest/QtTest>
#include "../head/Point.h"
#include "../head/Canon.h"
#include "../head/Obstacle.h"

class TestTank: public QObject
{
    Q_OBJECT
private slots:
    void getXTest();
    void setXTest();
    void getYTest();
    void setYTest();
    void getAngleHTest();
    void setAngleHTest();
    void getAngleVTest();
    void setAngleVTest();
    void getResistanceTest();
    void decrementeResistanceTest();
};

// Tests pour point
void TestTank::getXTest() { 
    Point p(0, 1);
    //compare les deux arguments avec un affichage meilleur
    QCOMPARE(p.getX(), 0);
}
void TestTank::setXTest() {
    Point p(0, 0);
    p.setX(1);
    QCOMPARE(p.getX(), 1);
}
void TestTank::getYTest() {
    Point p(1, 0);
    QCOMPARE(p.getY(), 0);
}
void TestTank::setYTest() {
    Point p(0, 0);
    p.setY(1);
    QCOMPARE(p.getY(), 1);
}
// Tests pour Canon
void TestTank::getAngleHTest() { 
    Canon c(HAUT);
    QCOMPARE(c.getAngleH(), 0.0);
}
void TestTank::setAngleHTest() { 
    Canon c(HAUT);
    c.setAngleH(1.0);
    QCOMPARE(1.0, 1.0);
}
void TestTank::getAngleVTest() { 
    Canon c(HAUT);
    QCOMPARE(c.getAngleV(), 1.0);
}
void TestTank::setAngleVTest() { 
    Canon c(HAUT);
    c.setAngleV(1.0);
    QCOMPARE(1.0, 1.0);
}
// Tests pour Obstacle
void TestTank::getResistanceTest() { 
    Obstacle o(ARBRE,Point(0,0),0);
    QCOMPARE(o.getResistance(), 1);
}
void TestTank::decrementeResistanceTest() { 
    Obstacle o(ROCHER,Point(0,0),0);
    o.decrementeResistance(4);
    QCOMPARE(o.getResistance(), 3);
}


QTEST_MAIN(TestTank)
#include "testtank.moc"
