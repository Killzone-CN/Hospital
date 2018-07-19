#include "addjob.h"
#include "ui_addjob.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QComboBox>
#include <QCompleter>
#include <QStringList>
#include "QDebug"
#include <QCloseEvent>
#include "QMessageBox"

AddJob::AddJob(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddJob)
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
}

AddJob::~AddJob()
{
    delete ui;
}

void AddJob::on_pushButton_clicked()
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
           query.prepare("INSERT INTO job (job_id, job_name, dept_id) VALUES (:a, :b, :c)");

           query.bindValue(":a", a);
           query.bindValue(":b", b);
           query.bindValue(":c",c);
           if(query.exec()){
               QMessageBox msgBox;
               msgBox.setText("录入成功");
               msgBox.exec();
           }
           this->close();
       }

}

void AddJob::on_pushButton_2_clicked()
{
    this->close();
}
