#ifndef DELETENODEDIALOG_H
#define DELETENODEDIALOG_H

#include <QDialog>
#include <QAbstractButton>
namespace Ui {
class DeleteNodeDialog;
}

class DeleteNodeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteNodeDialog(QWidget *parent = nullptr);
    ~DeleteNodeDialog();

    bool getDeleteEndNodeStatus() const;

    bool getDeleteByIndexStatus() const;

    bool getDeleteByValueStatus() const;

    QString getDeleteValue() const;

    QString getDeleteIndex() const;

private slots:

    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::DeleteNodeDialog *ui;
    bool deleteEndNodeStatus;
    bool deleteByIndexStatus;
    bool deleteByValueStatus;
    QString deleteValue;
    QString deleteIndex;

};

#endif // DELETENODEDIALOG_H
