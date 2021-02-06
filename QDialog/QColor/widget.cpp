#include "widget.h"
#include "ui_widget.h"
#include <QColorDialog>
#include <QDebug>
#include <QPalette>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setAutoFillBackground(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_textPushButton_clicked()
{

}

void Widget::on_fontPushButton_clicked()
{

}

void Widget::on_backGndButton_clicked()
{
    QPalette palette = ui->label->palette();
    QColor color = palette.color(QPalette::WindowText);
    QColor chosenColor = QColorDialog::getColor(color,this,"Choose text color");

    if(chosenColor.isValid())
    {
        palette.setColor(QPalette::WindowText, chosenColor);
        ui->label->setPalette(palette);
        qDebug() << "User choose a valid color";
    }
    else{
        qDebug() << "User choose a invalid color";
    }




}
