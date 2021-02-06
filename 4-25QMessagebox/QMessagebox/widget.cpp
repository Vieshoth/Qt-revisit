#include "widget.h"
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton * button = new QPushButton(this);
    button->setText("Click Me");
    button->move(200, 200);
    connect(button, &QPushButton::clicked, [=](){
       /* QMessageBox message;
        message.setMinimumSize(300, 200);
        message.setWindowTitle("Message Title");
        message.setText("Something happened");
        message.setInformativeText("What do you want to do?");
        message.setIcon(QMessageBox::Critical);
        message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        message.setDefaultButton(QMessageBox::Cancel);
        int ret = message.exec();*/

//        int ret = QMessageBox::critical(this, "Message title", "Hi this is vieshoth", QMessageBox::Ok | QMessageBox::Cancel);

        int ret = QMessageBox::information(this, "Message title", "Hi this is vieshoth", QMessageBox::Ok | QMessageBox::Cancel);


        if (ret == QMessageBox::Ok){
            qDebug() << "Ok clicked";
        }
        else{
            qDebug() << "Cancel clicked";
        }
    });
}

Widget::~Widget()
{
}

