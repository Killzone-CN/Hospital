#ifndef SALARY_H
#define SALARY_H

#include <QDialog>

namespace Ui {
class Salary;
}

class Salary : public QDialog
{
    Q_OBJECT

public:
    explicit Salary(QWidget *parent = 0);
    ~Salary();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Salary *ui;
};

#endif // SALARY_H
