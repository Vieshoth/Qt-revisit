#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //String Notation
    /*
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(changeText()));
    */
    //Function Notation using regular slots
    //connect(ui->pushButton, &QPushButton::clicked, this, &Widget::changeText);

    //Function Notation using lambdas
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        ui->label->setText("This is lambda function");
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeText()
{
    qDebug() << "change text called";
    ui->label->setText("pushbutton clicked");
}

