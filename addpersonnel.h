#ifndef ADDPERSONNEL_H
#define ADDPERSONNEL_H

#include <QDialog>

namespace Ui {
class AddPersonnel;
}

class AddPersonnel : public QDialog
{
    Q_OBJECT

public:
    explicit AddPersonnel(QWidget *parent = 0);
    ~AddPersonnel();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddPersonnel *ui;
};

#endif // ADDPERSONNEL_H
