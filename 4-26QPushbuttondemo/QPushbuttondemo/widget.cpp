#include "widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QFont buttonFont("Times", 10, QFont::Bold);
    QPushButton * button = new QPushButton("Button1", this) ;
    button->setFont(buttonFont);
    button->setMinimumSize(200,100);

    connect(button, &QPushButton::clicked, [=](){

        qDebug() << "QPushbutton clicked";
    });


    QPushButton * button1 = new QPushButton("Button1", this) ;
    button1->setFont(buttonFont);
    button1->setMinimumSize(200,100);
    button1->move(300, 0);

    connect(button1, &QPushButton::pressed, [=](){

        qDebug() << "QPushbutton pressed";
    });
    connect(button1, &QPushButton::released, [=](){

        qDebug() << "QPushbutton released";
    });

}

Widget::~Widget()
{
}

