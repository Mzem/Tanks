#ifndef BUTTONWIDGET_H
#define BUTTONWIDGET_H

//Classe de bouttons permettant d'avoir des informations spécifiques sur le boutton cliqué

#include <QStringList>
#include <QPushButton>
#include <QSignalMapper>
#include <QVBoxLayout>
#include "../head/Definitions.h"

class ButtonWidget : public QWidget
{
    Q_OBJECT

    public:
        ButtonWidget(QStringList texts, QColor, QWidget *parent = 0);

    signals:
        void clicked(const QString &text);

    private:
        QSignalMapper *signalMapper;
};

#endif // BUTTONWIDGET_H
