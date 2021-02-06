#ifndef ADDNODE_H
#define ADDNODE_H

#include <QDialog>

namespace Ui {
class AddNode;
}

class AddNode : public QDialog
{
    Q_OBJECT

public:
    explicit AddNode(QWidget *parent = nullptr);
    ~AddNode();

    QString getIndex() const;

    QString getValue() const;

    bool getEndNodeCheckBoxStatus() const;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_addEndCheckBox_stateChanged(int arg1);

private:
    Ui::AddNode *ui;

    QString index;
    QString value;
    bool endNodeCheckBoxStatus;
};

#endif // ADDNODE_H
