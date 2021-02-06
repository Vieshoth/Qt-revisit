#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)));

    connect(ui->horizontalSlider, &QSlider::valueChanged, [=](){
        ui->progressBar->setValue(ui->horizontalSlider->value());
    });
    //connect()
}

Widget::~Widget()
{
    delete ui;
}

