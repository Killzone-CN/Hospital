#ifndef ADDPOTION_H
#define ADDPOTION_H

#include <QDialog>

namespace Ui {
class AddPotion;
}

class AddPotion : public QDialog
{
    Q_OBJECT

public:
    explicit AddPotion(QWidget *parent = 0);
    ~AddPotion();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddPotion *ui;
};

#endif // ADDPOTION_H
