#ifndef PERSONNELUPDATA_H
#define PERSONNELUPDATA_H

#include <QDialog>

namespace Ui {
class PersonnelUpdata;
}

class PersonnelUpdata : public QDialog
{
    Q_OBJECT

public:
    explicit PersonnelUpdata(QWidget *parent = 0);
    ~PersonnelUpdata();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::PersonnelUpdata *ui;
};

#endif // PERSONNELUPDATA_H
