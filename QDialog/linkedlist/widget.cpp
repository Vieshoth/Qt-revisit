#include "widget.h"
#include "ui_widget.h"
#include "linkedlist.h"
#include <QGraphicsView>
#include <QInputDialog>
#include <QDebug>
#include "addnode.h"
#include <QDialog>
#include "deletenodedialog.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    bool ok;
    int i = QInputDialog::getInt(this, tr("QInputDialog::getInt()"),
                                       tr("Enter the value of first linkedlist:"), 25, 0, 100, 1, &ok);

    if (ok){
        llist = new Linkedlist(i);
        ui->setupUi(this);
    }else{

    }
    viewList();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_addNodeButton_clicked()
{
    AddNode *addNodeDialog = new AddNode();

    int ret = addNodeDialog->exec();

    if (ret == QDialog::Accepted){
        qDebug() << "QDialog accepted" << endl;
        if(addNodeDialog->getEndNodeCheckBoxStatus()){
            llist->addNode(addNodeDialog->getValue().toInt());
        }
        else{
            qDebug() << "Index: " << addNodeDialog->getIndex().toInt() << "Value: " << addNodeDialog->getValue().toInt()<< endl;
            llist->addNode(addNodeDialog->getIndex().toInt(), addNodeDialog->getValue().toInt());
        }
        viewList();
    }
    else{

    }
}

void Widget::on_viewListButton_clicked()
{
    ui->listWidget->clear();
    if(llist->isEmpty() == false){
        QStringList valueList = llist->traverse();

        for ( const auto & i : valueList  )
        {
            qDebug() << i;
            ui->listWidget->addItem(i);
        }

    }
}

void Widget::viewList()
{
    ui->listWidget->clear();
    if(llist->isEmpty() == false){
        QStringList valueList = llist->traverse();

        for ( const auto & i : valueList  )
        {
            qDebug() << i;
            ui->listWidget->addItem(i);
        }

    }
}

void Widget::on_deleteNodeButton_clicked()
{
    DeleteNodeDialog *deleteNodeDialog = new DeleteNodeDialog();
    QString index, value;

    connect(deleteNodeDialog, &DeleteNodeDialog::accepted, [=](){

        if(deleteNodeDialog->getDeleteEndNodeStatus()){
            qDebug() << "deleteNodeDialog accepted: getDeleteEndNodeStatus" << endl;
            llist->deleteNode();
            viewList();
        }
        else{
            if(deleteNodeDialog->getDeleteByIndexStatus()){
                qDebug() << "deleteNodeDialog accepted: getDeleteByIndexStatus" << endl;
            }
            else if(deleteNodeDialog->getDeleteByValueStatus()){
                qDebug() << "deleteNodeDialog accepted: getDeleteByValueStatus" << endl;
            }
        }

    });

    connect(deleteNodeDialog, &DeleteNodeDialog::rejected, [=](){
        qDebug() << "deleteNodeDialog rejected" << endl;
    });
    deleteNodeDialog->exec();
}
