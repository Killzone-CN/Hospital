#include "addchuang.h"
#include "ui_addchuang.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QCloseEvent>
#include "QMessageBox"

AddChuang::AddChuang(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddChuang)
{
    ui->setupUi(this);
}

AddChuang::~AddChuang()
{
    delete ui;
}

void AddChuang::on_pushButton_clicked()
{
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this, tr("确认"),QString(tr("是否录入此信息？")),QMessageBox::Yes | QMessageBox::No);
       if (button == QMessageBox::No) {
             this->close();  //忽略退出信号，程序继续运行
       }
       else if (button == QMessageBox::Yes) {
           QSqlQuery query;
           QString a=this->ui->a->text();
           query.prepare("INSERT INTO chuang (BED,STATE) VALUES (:a, :b)");

           query.bindValue(":a", a);
           query.bindValue(":b", "free");
           if(query.exec()){
               QMessageBox msgBox;
               msgBox.setText("录入成功");
               msgBox.exec();
           }
           this->close();
       }

}

void AddChuang::on_pushButton_2_clicked()
{
    this->close();
}
