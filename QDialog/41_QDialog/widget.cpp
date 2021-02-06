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


void Widget::on_provideInfoButton_clicked()
{
    InfoDialog * dialog = new InfoDialog(this);
    /*
    int ret = dialog->exec();

    if(ret == QDialog::Accepted){
        QString position = dialog->getPosition();
        QString favouritOS = dialog->getFavouriteOs();
        qDebug() << "Dialog accepted, postion : " << position << "faouritOS: " << favouritOS;

    }

    if(ret == QDialog::Rejected){
        qDebug() << "Dialog rejected";
    }
    */
    connect(dialog, &InfoDialog::accepted, [=](){
        QString position = dialog->getPosition();
        QString favouritOS = dialog->getFavouriteOs();
        qDebug() << "Dialog accepted, postion : " << position << "faouritOS: " << favouritOS;
        ui->infoLabel->setText("Dialog accepted, postion : " + position + "faouritOS: " + favouritOS);
    });
    connect(dialog, &InfoDialog::rejected, [=](){
        qDebug() << "Dialog rejected";
    });

    dialog->show();
    dialog->raise();
    dialog->activateWindow();

}


