#ifndef ADDCHUANG_H
#define ADDCHUANG_H

#include <QDialog>

namespace Ui {
class AddChuang;
}

class AddChuang : public QDialog
{
    Q_OBJECT

public:
    explicit AddChuang(QWidget *parent = 0);
    ~AddChuang();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddChuang *ui;
};

#endif // ADDCHUANG_H
