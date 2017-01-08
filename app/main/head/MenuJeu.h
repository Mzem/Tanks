#ifndef MENUJEU_H
#define MENUJEU_H

#include <QGridLayout>
#include "ButtonWidget.h"

class MenuJeu : public QWidget
{
    Q_OBJECT

    public:
        MenuJeu(QWidget* fenetre, QWidget *parent=0);
        ~MenuJeu();
        QGridLayout* getLayout();

    private:
        QGridLayout* layout;
};

#endif // MENUJEU_H
