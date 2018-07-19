#ifndef ADDDEPT_H
#define ADDDEPT_H

#include <QDialog>

namespace Ui {
class AddDept;
}

class AddDept : public QDialog
{
    Q_OBJECT

public:
    explicit AddDept(QWidget *parent = 0);
    ~AddDept();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddDept *ui;
};

#endif // ADDDEPT_H
