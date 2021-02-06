#include "addnode.h"
#include "ui_addnode.h"

AddNode::AddNode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNode)
{
    ui->setupUi(this);
}

AddNode::~AddNode()
{
    delete ui;
}

void AddNode::on_pushButton_clicked()
{
    this->index = ui->indexLineEdit->text();
    this->value = ui->valueLlineEdit->text();
    this->endNodeCheckBoxStatus = ui->addEndCheckBox->isChecked();

    accept();
}

void AddNode::on_pushButton_2_clicked()
{
    reject();
}

void AddNode::on_addEndCheckBox_stateChanged(int arg1)
{
    if(arg1){
        ui->indexLineEdit->setDisabled(true);
    }
    else{
        ui->indexLineEdit->setDisabled(false);
    }

}

bool AddNode::getEndNodeCheckBoxStatus() const
{
    return endNodeCheckBoxStatus;
}

QString AddNode::getValue() const
{
    return value;
}

QString AddNode::getIndex() const
{
    return index;
}
