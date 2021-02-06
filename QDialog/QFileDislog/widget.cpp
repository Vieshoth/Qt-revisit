#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QDebug>
#include <QFontDialog>
#include <QInputDialog>

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


void Widget::on_pushButton_clicked()
{
//    QString fileName = QFileDialog::getOpenFileName(this,
//          tr("Open Image"), "/home/jana", tr("Image Files (*.png *.jpg *.bmp)"));

//    QStringList fileName = QFileDialog::getOpenFileNames(this,
//          tr("Open Text"), "/home/vieshoth", tr("Text Files (*.txt)"));

//    qDebug() << "The opened file name is " << fileName;


    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                "/home/vieshoth",
                                tr("Images (*.png *.xpm *.jpg)"));

    qDebug() << "The opened file name is " << fileName;




}

void Widget::on_changeFontPushButton_clicked()
{
    bool ok;
      QFont font = QFontDialog::getFont(
                      &ok, QFont("Helvetica [Cronyx]", 10), this);
//      if (ok) {

//            qDebug() << "selected font is ";
//      } else {
//          // the user canceled the dialog; font is set to the initial
//          // value, in this case Helvetica [Cronyx], 10
//      }
}

void Widget::on_choosePushButton_clicked()
{
    bool ok;
        QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                             tr("User name:"), QLineEdit::Normal,
                                             QDir::home().dirName(), &ok);
        if (ok && !text.isEmpty())
            qDebug() << "Entered string is " << text;
}
