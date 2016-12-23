#ifndef MENUJEU_H
#define MENUJEU_H

#include <QGridLayout>
#include "../head/ButtonWidget.h"

class MenuJeu : public QWidget
{
    Q_OBJECT

    public:
        MenuJeu();

    public slots:
        void quitter();
};

#endif // MENUJEU_H
