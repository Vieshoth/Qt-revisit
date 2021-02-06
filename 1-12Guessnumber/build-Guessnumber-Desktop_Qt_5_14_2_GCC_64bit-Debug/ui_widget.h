/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QSpinBox *spinBox;
    QPushButton *guessButton;
    QPushButton *startoverButton;
    QLabel *messageLabel;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 110, 211, 31));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        spinBox = new QSpinBox(Widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(230, 200, 42, 26));
        spinBox->setMinimum(1);
        spinBox->setMaximum(10);
        guessButton = new QPushButton(Widget);
        guessButton->setObjectName(QString::fromUtf8("guessButton"));
        guessButton->setGeometry(QRect(310, 200, 89, 25));
        startoverButton = new QPushButton(Widget);
        startoverButton->setObjectName(QString::fromUtf8("startoverButton"));
        startoverButton->setGeometry(QRect(460, 200, 89, 25));
        messageLabel = new QLabel(Widget);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));
        messageLabel->setGeometry(QRect(220, 290, 351, 31));
        messageLabel->setFont(font);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Guess My Number", nullptr));
        guessButton->setText(QCoreApplication::translate("Widget", "Guess", nullptr));
        startoverButton->setText(QCoreApplication::translate("Widget", "Start over", nullptr));
        messageLabel->setText(QCoreApplication::translate("Widget", "Guess My Number", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
