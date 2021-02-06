#include "deletenodedialog.h"
#include "ui_deletenodedialog.h"
#include <QAbstractButton>

DeleteNodeDialog::DeleteNodeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteNodeDialog)
{
    ui->setupUi(this);
}

DeleteNodeDialog::~DeleteNodeDialog()
{
    delete ui;
}


void DeleteNodeDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    QDialogButtonBox::StandardButton stdButton = ui->buttonBox->standardButton(button);

    if(stdButton == QDialogButtonBox::Ok){
        deleteEndNodeStatus = ui->delEndNodeRadioButton->isChecked();
        deleteByIndexStatus = ui->delByIndexRadioButton->isChecked();
        deleteByValueStatus = ui->delByValueRadioButton->isChecked();
        deleteValue = ui->delByValueLineEdit->text();
        deleteIndex = ui->delByIndexLineEdit->text();
        accept();
    }
    if(stdButton == QDialogButtonBox::Cancel){
        reject();
    }
}

QString DeleteNodeDialog::getDeleteIndex() const
{
    return deleteIndex;
}

QString DeleteNodeDialog::getDeleteValue() const
{
    return deleteValue;
}

bool DeleteNodeDialog::getDeleteByValueStatus() const
{
    return deleteByValueStatus;
}

bool DeleteNodeDialog::getDeleteByIndexStatus() const
{
    return deleteByIndexStatus;
}

bool DeleteNodeDialog::getDeleteEndNodeStatus() const
{
    return deleteEndNodeStatus;
}
