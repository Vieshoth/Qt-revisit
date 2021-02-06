#include "rockwidget.h"
#include "QLabel"
#include "QPushButton"
#include <QMessageBox>

RockWidget::RockWidget(QWidget *parent) : QWidget(parent)
{
    //setWindowTitle("Rock Widget");
    QPalette label1palette;
    label1palette.setColor(QPalette::Window, Qt::green);
    label1palette.setColor(QPalette::WindowText, Qt::blue);

    QLabel * label = new QLabel("This is my label", this);

    QLabel *label1 = new QLabel(this);
    label1->setText("My colored label");
    label1->move(50,50);
    label1->setPalette(label1palette);

    QFont serifFont("Times", 10, QFont::Bold);
    label1->setFont(serifFont);

    QPushButton * button = new QPushButton(this);
    button->setText("Click Me");
    button->move(100,100);

    connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));

}

void RockWidget::buttonClicked()
{
    QMessageBox::information(this, "Message", "You clicked the push button");

}
