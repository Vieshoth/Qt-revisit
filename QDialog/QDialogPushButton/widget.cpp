#include "widget.h"
#include "ui_widget.h"
#include "infodialog.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_showInfoButton_clicked()
{
    infoDialog * dialog = new infoDialog();

    connect(dialog, &QDialog::accepted, [=](){
        qDebug() << "Dialog:Accepted";
    });
    connect(dialog, &QDialog::rejected, [=](){
        qDebug() << "Dialog:Rejected";
    });

    dialog->show();
    dialog->raise();
    dialog->activateWindow();
}
