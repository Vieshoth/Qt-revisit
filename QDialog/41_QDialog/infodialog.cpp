#include "infodialog.h"
#include "ui_infodialog.h"


InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::on_okButton_clicked()
{
    QString userPosition = ui->positionLineEdit->text();
    if (!userPosition.isEmpty()){
        position = userPosition;

        if(ui->windowsRadioButton->isChecked()){
            favouriteOs = "Windows";
        }
        if(ui->linuxRadioButton->isChecked()){
            favouriteOs = "Linux";
        }
        if(ui->macRadioButton->isChecked()){
            favouriteOs = "Mac";
        }
    }

    accept();

}


void InfoDialog::on_cancelButton_clicked()
{
    reject();
}

QString InfoDialog::getFavouriteOs() const
{
    return favouriteOs;
}


QString InfoDialog::getPosition() const
{
    return position;
}
