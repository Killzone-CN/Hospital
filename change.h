#ifndef CHANGE_H
#define CHANGE_H

#include <QDialog>

namespace Ui {
class Change;
}

class Change : public QDialog
{
    Q_OBJECT

public:
    explicit Change(QWidget *parent = 0);
    ~Change();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Change *ui;
};

#endif // CHANGE_H
