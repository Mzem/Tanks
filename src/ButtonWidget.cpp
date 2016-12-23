#include "../head/ButtonWidget.h"

ButtonWidget::ButtonWidget(QStringList texts, QColor coul, QWidget *parent) : QWidget(parent)
{
    signalMapper = new QSignalMapper(this);

    QVBoxLayout *layout = new QVBoxLayout;
    QPalette p;
    p.setColor(QPalette::ButtonText, coul);

    for (int i = 0; i < texts.size(); ++i)
    {
        QPushButton *button = new QPushButton(texts[i], parent);
        button->setFont(QFont("Calibri", X/57));
        button->setCursor(Qt::PointingHandCursor);
        button->setPalette(p);

        connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(button, texts[i]);

        layout->addWidget(button);
    }

    connect(signalMapper, SIGNAL(mapped(const QString &)),this, SIGNAL(clicked(const QString &)));

    setLayout(layout);
}
