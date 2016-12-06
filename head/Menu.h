#ifndef DEF_MENU
#define DEF_MENU

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "../head/Tank.h"

class Menu : public QWidget
{
    public:
    Menu();

    private:
    QPushButton *b1;
    QPushButton *b2;
    QPushButton *b3;
    QPushButton *b4;
};

#endif
