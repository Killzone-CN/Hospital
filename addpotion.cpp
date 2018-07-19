#include "addpotion.h"
#include "ui_addpotion.h"
#include "QSqlQuery"
#include <QCloseEvent>
#include "QMessageBox"

AddPotion::AddPotion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPotion)
{
    ui->setupUi(this);
}

AddPotion::~AddPotion()
{
    delete ui;
}

void AddPotion::on_pushButton_clicked()
{
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this, tr("确认"),QString(tr("是否录入此信息？")),QMessageBox::Yes | QMessageBox::No);
       if (button == QMessageBox::No) {
             this->close();  //忽略退出信号，程序继续运行
       }
       else if (button == QMessageBox::Yes) {

           QSqlQuery query;
           QString a=this->ui->a->text();
           QString b=this->ui->b->text();
           QString c=this->ui->c->text();
           QString d=this->ui->d->text();
           QString e=this->ui->e->text();
           query.prepare("INSERT INTO potion (药剂代号, 药剂名称, 药剂价格,药剂库存数量,备注) VALUES (:a, :b, :c,:d,:e)");

           query.bindValue(":a", a);
           query.bindValue(":b", b);
           query.bindValue(":c",c);
           query.bindValue(":d",d);
           query.bindValue(":e",e);
           if(query.exec()){
               QMessageBox msgBox;
               msgBox.setText("录入成功");
               msgBox.exec();
           }
           this->close();
       }

}

void AddPotion::on_pushButton_2_clicked()
{
    this->close();
}
