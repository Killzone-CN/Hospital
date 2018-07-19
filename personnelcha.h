#ifndef PERSONNELCHA_H
#define PERSONNELCHA_H

#include <QDialog>

namespace Ui {
class PersonnelCha;
}

class PersonnelCha : public QDialog
{
    Q_OBJECT

public:
    explicit PersonnelCha(QWidget *parent = 0);
    ~PersonnelCha();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::PersonnelCha *ui;
};

#endif // PERSONNELCHA_H
