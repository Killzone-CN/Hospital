#ifndef TMS_H
#define TMS_H

#include <QDialog>

namespace Ui {
class tms;
}

class tms : public QDialog
{
    Q_OBJECT

public:
    explicit tms(QWidget *parent = 0);
    ~tms();
protected:
    void changeEvent(QEvent *e);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::tms *ui;
};

#endif // TMS_H
