#ifndef ADDAPPARATUS_H
#define ADDAPPARATUS_H

#include <QDialog>

namespace Ui {
class AddApparatus;
}

class AddApparatus : public QDialog
{
    Q_OBJECT

public:
    explicit AddApparatus(QWidget *parent = 0);
    ~AddApparatus();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddApparatus *ui;
};

#endif // ADDAPPARATUS_H
