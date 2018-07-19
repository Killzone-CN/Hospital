#include "adddept.h"
#include "ui_adddept.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QComboBox>
#include <QCompleter>
#include <QStringList>
#include "QDebug"
#include <QCloseEvent>
#include "QMessageBox"

AddDept::AddDept(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDept)
{
    ui->setupUi(this);
    QStringList strings;
    QSqlQuery query("select emp_no from personnel");
    while (query.next()) {
    QString goodsno = query.value(0).toString();
    strings.append(goodsno);
    ui->comboBox->clear();
    ui->comboBox->addItems(strings);
    ui->comboBox->setCompleter(new QCompleter(strings, this));
    }

    strings.clear();
    QSqlQuery query1("select emp_no from personnel");
    while (query1.next()) {
    QString goodsno = query1.value(0).toString();
    strings.append(goodsno);
    ui->comboBox_2->clear();
    ui->comboBox_2->addItems(strings);
    ui->comboBox_2->setCompleter(new QCompleter(strings, this));
    }
}

AddDept::~AddDept()
{
    delete ui;
}

void AddDept::on_pushButton_clicked()
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
           QString c=this->ui->comboBox->currentText();
           QString d=this->ui->comboBox_2->currentText();
           query.prepare("INSERT INTO dept (dept_id, dept_name, dept_manager,dept_vicemanager) VALUES (:a, :b, :c,:d)");

           query.bindValue(":a", a);
           query.bindValue(":b", b);
           query.bindValue(":c",c);
           query.bindValue(":d",d);
           if(query.exec()){
               QMessageBox msgBox;
               msgBox.setText("录入成功");
               msgBox.exec();
           }
           this->close();
       }
}

void AddDept::on_pushButton_2_clicked()
{
    this->close();
}
