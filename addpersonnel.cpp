#include "addpersonnel.h"
#include "ui_addpersonnel.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QComboBox>
#include <QCompleter>
#include <QStringList>
#include "QDebug"
#include <QCloseEvent>
#include "QMessageBox"


AddPersonnel::AddPersonnel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPersonnel)
{
    ui->setupUi(this);
    QStringList strings;
    QSqlQuery query("select dept_id from dept");
    while (query.next()) {
    QString goodsno = query.value(0).toString();
    strings.append(goodsno);
    ui->comboBox->clear();
    ui->comboBox->addItems(strings);
    ui->comboBox->setCompleter(new QCompleter(strings, this));
    }

    strings.clear();
    QSqlQuery query1("select job_id from job");
    while (query1.next()) {
    QString goodsno = query1.value(0).toString();
    strings.append(goodsno);
    ui->comboBox_2->clear();
    ui->comboBox_2->addItems(strings);
    ui->comboBox_2->setCompleter(new QCompleter(strings, this));
    }
}

AddPersonnel::~AddPersonnel()
{
    delete ui;
}

void AddPersonnel::on_pushButton_clicked()
{
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this, tr("确认"),QString(tr("是否录入此信息？")),QMessageBox::Yes | QMessageBox::No);
       if (button == QMessageBox::No) {
             this->close();  //忽略退出信号，程序继续运行
       }
       else if (button == QMessageBox::Yes) {

           QSqlQuery query;
           QSqlQuery query1;
           QString a=this->ui->a->text();
           QString b=this->ui->b->text();
           QString c=this->ui->comboBox->currentText();
           QString d=this->ui->d->text();
           QString e=this->ui->e->text();
           QString f=this->ui->f->text();
           QString g=this->ui->g->text();
           QString h=this->ui->h->text();
           QString i=this->ui->i->text();
           QString j=this->ui->j->text();
           QString k=this->ui->k->text();
           QString l=this->ui->l->text();
           QString m=this->ui->m->text();
           QString n=this->ui->n->text();
           QString o=this->ui->o->text();
           QString p=this->ui->p->text();
           QString q=this->ui->q->text();
           QString r=this->ui->r->text();
           QString s=this->ui->comboBox_2->currentText();
           query.prepare("INSERT INTO personnel (emp_no, emp_name, emp_dept_id,emp_duty,emp_xl,emp_gender,emp_birthday,emp_hometown,emp_couniry,emp_nation,emp_id,emp_marriage,emp_health,emp_startwork,emp_state,emp_homeaddress,emp_teleno,emp_email,emp_job_id) VALUES (:a, :b, :c,:d,:e,:f,:g,:h, :i, :j,:k,:l,:m,:n,:o, :p, :q,:r,:s)");
           query1.prepare("INSERT INTO salary (EMP_NO,SALARY) VALUES (:a,:gg)");
           query.bindValue(":a", a);
           query.bindValue(":b", b);
           query.bindValue(":c",c);
           query.bindValue(":d",d);
           query.bindValue(":e",e);
           query.bindValue(":f",f);
           query.bindValue(":g",g);
           query.bindValue(":h",h);
           query.bindValue(":i",i);
           query.bindValue(":j",j);
           query.bindValue(":k",k);
           query.bindValue(":l",l);
           query.bindValue(":m",m);
           query.bindValue(":n",n);
           query.bindValue(":o",o);
           query.bindValue(":p",p);
           query.bindValue(":q",q);
           query.bindValue(":r",r);
           query.bindValue(":s",s);

           query1.bindValue(":a", a);
           query1.bindValue(":gg", 5000);
           if(query.exec()){
               if(query1.exec()){
                   QMessageBox msgBox;
                   msgBox.setText("录入成功");
                   msgBox.exec();
               }else{
                   QMessageBox msgBox1;
                   msgBox1.setText("失败");
                   msgBox1.exec();
               }

           }
           this->close();
       }

}

void AddPersonnel::on_pushButton_2_clicked()
{
    this->close();
}
