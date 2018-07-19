#include "addpatient.h"
#include "ui_addpatient.h"
#include "QSqlQuery"
#include <QComboBox>
#include <QCompleter>
#include <QStringList>
#include "QDebug"
#include <QSqlQueryModel>
#include <QCloseEvent>
#include "QMessageBox"

AddPatient::AddPatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPatient)
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
    QString no="free";
    QSqlQuery query1("select * from chuang");
    while (query1.next()) {
    if(query1.value(1).toString()==no){
        QString goodsno = query1.value(0).toString();
        strings.append(goodsno);
        ui->comboBox_2->clear();
        ui->comboBox_2->addItems(strings);
        ui->comboBox_2->setCompleter(new QCompleter(strings, this));
    }
    }
}

AddPatient::~AddPatient()
{
    delete ui;
}

void AddPatient::on_pushButton_clicked()
{
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this, tr("确认"),QString(tr("是否录入此信息？")),QMessageBox::Yes | QMessageBox::No);
       if (button == QMessageBox::No) {
             this->close();  //忽略退出信号，程序继续运行
       }
       else if (button == QMessageBox::Yes) {

           QSqlQuery query,query1;
           QString a=this->ui->a->text();
           QString b=this->ui->b->text();
           QString c=this->ui->c->text();
           QString d=this->ui->d->text();
           QString e=this->ui->e->text();
           QString f=this->ui->comboBox->currentText();
           QString g=this->ui->g->text();
           QString h=this->ui->comboBox_2->currentText();
           query.prepare("INSERT INTO patient (patient_name, patient_gender, patient_date_start,patient_dept,patient_state,patient_doc,patient_room,patient_bed) VALUES (:a, :b, :c,:d,:e,:f,:g,:h)");
            QString strSQL="update chuang set STATE='employ' where BED='",temStr=this->ui->comboBox_2->currentText();
           strSQL+=temStr+"'";
           query1.prepare(strSQL);
           query1.exec();

           query.bindValue(":a", a);
           query.bindValue(":b", b);
           query.bindValue(":c",c);
           query.bindValue(":d",d);
           query.bindValue(":e",e);
           query.bindValue(":f",f);
           query.bindValue(":g",g);
           query.bindValue(":h",h);
           if(query.exec()){
               QMessageBox msgBox;
               msgBox.setText("录入成功");
               msgBox.exec();
           }
           this->close();
       }

}

void AddPatient::on_pushButton_2_clicked()
{
    this->close();
}
