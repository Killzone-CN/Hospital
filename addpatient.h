#ifndef ADDPATIENT_H
#define ADDPATIENT_H

#include <QDialog>

namespace Ui {
class AddPatient;
}

class AddPatient : public QDialog
{
    Q_OBJECT

public:
    explicit AddPatient(QWidget *parent = 0);
    ~AddPatient();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddPatient *ui;
};

#endif // ADDPATIENT_H
