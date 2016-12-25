#ifndef MENUJEU_H
#define MENUJEU_H

#include <QGridLayout>
#include "../head/ButtonWidget.h"

class MenuJeu : public QWidget
{
    Q_OBJECT

    public:
        MenuJeu(QWidget* fenetre);
        QGridLayout* getLayout();

    private:
        QGridLayout* layout;
};

#endif // MENUJEU_H
