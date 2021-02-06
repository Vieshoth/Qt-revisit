#include "widget.h"
#include "ui_widget.h"
#include <QPalette>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPalette palette = ui->label->palette();

    palette.setColor(QPalette::Window, Qt::blue);
    palette.setColor(QPalette::WindowText, Qt::green);

    ui->label->setPalette(palette);
}

Widget::~Widget()
{
    delete ui;
}

