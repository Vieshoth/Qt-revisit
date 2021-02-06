#include "widget.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QLabel * firstNameLabel = new QLabel("First name", this);
    firstNameLabel->setMinimumSize(70,50);
    firstNameLabel->move(10, 10);

    QLineEdit * firstNameLineEdit = new QLineEdit(this);
    firstNameLineEdit->setMinimumSize(200,50);
    firstNameLineEdit->move(100, 10);
    firstNameLineEdit->setText("Enter your first name");

    QLabel * lastNameLabel = new QLabel("Last name", this);
    lastNameLabel->setMinimumSize(70,50);
    lastNameLabel->move(10, 70);

    QLineEdit * lastNameLineEdit = new QLineEdit(this);
    lastNameLineEdit->setMinimumSize(200,50);
    lastNameLineEdit->move(100, 70);
    lastNameLineEdit->setPlaceholderText("Enter the last name");

    QLabel * cityLabel = new QLabel("City", this);
    cityLabel->setMinimumSize(70,50);
    cityLabel->move(10, 130);

    QLineEdit * cityLineEdit = new QLineEdit(this);
    cityLineEdit->setMinimumSize(200,50);
    cityLineEdit->move(100, 130);

    QFont buttonFont("Time", 20, QFont::Bold);
    QPushButton * button = new QPushButton("Grab data", this);
    button->setFont(buttonFont);
    button->move(80, 190);

    connect(button, &QPushButton::clicked, [=](){
        QString firstName = firstNameLineEdit->text();
        QString lastName = lastNameLineEdit->text();
        QString city = cityLineEdit->text();

        if(!firstName.isEmpty() && !lastName.isEmpty() && !city.isEmpty())
        {
            qDebug() << firstName ;
            qDebug() << lastName ;
            qDebug() << city ;
        }
        else{
            qDebug() << "One of the field is empty";
        }
    });

//    connect(firstNameLineEdit, &QLineEdit::cursorPositionChanged, [=](){
//        qDebug() << firstNameLineEdit->cursorPosition();
//    });

    connect(firstNameLineEdit, &QLineEdit::editingFinished, [=](){
        qDebug() << "Editing finished";
    });

}

Widget::~Widget()
{
}

