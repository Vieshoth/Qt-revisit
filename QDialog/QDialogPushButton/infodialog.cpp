#include "infodialog.h"
#include "ui_infodialog.h"
#include <QAbstractButton>
#include <QDebug>

infoDialog::infoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infoDialog)
{
    ui->setupUi(this);
}

infoDialog::~infoDialog()
{
    delete ui;
}

void infoDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    QDialogButtonBox::StandardButton stdButton = ui->buttonBox->standardButton(button);

    if(stdButton == QDialogButtonBox::Ok){
        qDebug() << "QDialogButtonBox::Ok";
        accept();
    }
    if(stdButton == QDialogButtonBox::Cancel){
        qDebug() << "QDialogButtonBox::Cancel";
        reject();
    }
}
