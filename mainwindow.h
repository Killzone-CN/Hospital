#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QDialog>

namespace Ui {
class MainWindow;
class Dialog;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_action_triggered();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_21_clicked();


    void on_pushButton_20_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_22_clicked();


    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();


    void on_action_6_triggered();

    void on_action_5_triggered();

    void on_action_4_triggered();

    void on_action_3_triggered();

    void on_action_2_triggered();

    void on_action_7_triggered();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_action_8_triggered();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

private:
    Ui::MainWindow *ui;
};


class Dialog:public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QDialog *parent=0);
    ~Dialog();
    void dialogUse();
    void waUse();
private slots:
    //这两个槽函数是当用户登陆到系统之后我规划要做的事情，但是后面我没有对其进行实现
    void findClick();
    void enableFindButton();
private:
    QDialog *dialog;
    QDialog *wa;
};
#endif // MAINWINDOW_H
