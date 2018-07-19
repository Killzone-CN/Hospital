#ifndef PERSONNELDEL_H
#define PERSONNELDEL_H

#include <QDialog>

namespace Ui {
class PersonnelDel;
}

class PersonnelDel : public QDialog
{
    Q_OBJECT

public:
    explicit PersonnelDel(QWidget *parent = 0);
    ~PersonnelDel();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::PersonnelDel *ui;
};

#endif // PERSONNELDEL_H
