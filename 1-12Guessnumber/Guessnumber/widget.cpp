#include "widget.h"
#include "ui_widget.h"
#include <stdlib.h>
#include <time.h>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    srand(time(NULL));

    secretNumber = rand() % 10 + 1;
    qDebug() << "The secretnumner is : " << secretNumber;

    ui->startoverButton->setDisabled(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_guessButton_clicked()
{

    guessNumber = ui->spinBox->value();
    qDebug() << "The guessed number is : " << QString::number(guessNumber);
    if (guessNumber > secretNumber){
        ui->messageLabel->setText("number is greater than secretNumber");
    }
    else if (guessNumber < secretNumber){
        ui->messageLabel->setText("number is lesser than secretNumber");
    }
    else {
        ui->messageLabel->setText("You won");
        ui->guessButton->setDisabled(true);
        ui->startoverButton->setDisabled(false);

    }

}

void Widget::on_startoverButton_clicked()
{

    //Enable the Guess Button
      ui->guessButton->setDisabled(false);

      //Disable the Start Over Button
      ui->startoverButton->setDisabled(true);

      //Put the spinbox back to 1
      ui->spinBox->setValue(1);

      //Regenerate the random number
      secretNumber = rand() % 10 + 1;

      //Clear the message label
      ui->messageLabel->setText("");



}
