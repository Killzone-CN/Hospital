#ifndef ADDSALARY_H
#define ADDSALARY_H

#include <QDialog>

namespace Ui {
class AddSalary;
}

class AddSalary : public QDialog
{
    Q_OBJECT

public:
    explicit AddSalary(QWidget *parent = 0);
    ~AddSalary();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddSalary *ui;
};

#endif // ADDSALARY_H
