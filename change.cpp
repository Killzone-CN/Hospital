#include "change.h"
#include "ui_change.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QComboBox>
#include <QCompleter>
#include <QStringList>
#include "QDebug"
#include <QCloseEvent>
#include "QMessageBox"

Change::Change(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Change)
{
    ui->setupUi(this);
/*    QSqlQuery query;
    QString s=QString("select dept_name from dept");
    query.exec(s);
    while(query.next()){
        ui->comboBox->clear();
        ui->comboBox->addItem(""+query.value(0).toString()+"");
    }

    ui->comboBox->addItem(tr("院长"));
    ui->comboBox->addItem(tr("老师"));
    ui->comboBox->addItem(tr("学生"));
    ui->comboBox->setCurrentIndex(1);*/
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
    QSqlQuery query1("select dept_id from dept");
    while (query1.next()) {
    QString goodsno = query1.value(0).toString();
    strings.append(goodsno);
    ui->comboBox_2->clear();
    ui->comboBox_2->addItems(strings);
    ui->comboBox_2->setCompleter(new QCompleter(strings, this));
    }

    strings.clear();
    QSqlQuery query2("select job_id from job");
    while (query2.next()) {
    QString goodsno = query2.value(0).toString();
    strings.append(goodsno);
    ui->comboBox_3->clear();
    ui->comboBox_3->addItems(strings);
    ui->comboBox_3->setCompleter(new QCompleter(strings, this));
    }


}

Change::~Change()
{
    delete ui;
}

void Change::on_pushButton_clicked()
{
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this, tr("确认"),QString(tr("是否修改此信息？")),QMessageBox::Yes | QMessageBox::No);
       if (button == QMessageBox::No) {
             this->close();  //忽略退出信号，程序继续运行
       }
       else if (button == QMessageBox::Yes) {
           QSqlQueryModel *model = new QSqlQueryModel;
           QString temStr,strSQL="update personnel set ";
           temStr="emp_dept_id=";
           strSQL+=temStr;
           strSQL+=""+this->ui->comboBox_2->currentText()+",";
           strSQL+="emp_duty=";
           strSQL+="'"+this->ui->a->text().trimmed()+"',";
           strSQL+="emp_job_id=";
           strSQL+=""+this->ui->comboBox_3->currentText()+"";
           strSQL+=" where emp_no=";
           strSQL+=""+this->ui->comboBox->currentText()+"";
       //    query.exec(QObject::tr("update potion set id=333 where id=5"));
       //    qDebug()<<strSQL;
           model->setQuery(strSQL);
           QMessageBox msgBox;
           msgBox.setText("修改成功");
           msgBox.exec();
           this->close();
       }



}

void Change::on_pushButton_2_clicked()
{
    this->close();
}
