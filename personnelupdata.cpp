#include "personnelupdata.h"
#include "ui_personnelupdata.h"
#include "QSqlQueryModel"
#include <QSqlQuery>
#include <QComboBox>
#include <QCompleter>
#include <QStringList>
#include "QDebug"
#include "QMessageBox"
#include <QCloseEvent>

PersonnelUpdata::PersonnelUpdata(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonnelUpdata)
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
}

PersonnelUpdata::~PersonnelUpdata()
{
    delete ui;
}

void PersonnelUpdata::on_pushButton_clicked()
{
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this, tr("确认"),QString(tr("是否修改此信息？")),QMessageBox::Yes | QMessageBox::No);
       if (button == QMessageBox::No) {
             this->close();  //忽略退出信号，程序继续运行
       }
       else if (button == QMessageBox::Yes) {
           QSqlQueryModel *model = new QSqlQueryModel;
           QString temStr,strSQL="update personnel set ";
           temStr=this->ui->comboBox_2->currentText();
           strSQL+=temStr+"=";
           strSQL+="'"+this->ui->a->text().trimmed()+"'";
           strSQL+=" where emp_no=";
           strSQL+=""+this->ui->comboBox->currentText()+"";
       //    query.exec(QObject::tr("update potion set id=333 where id=5"));
           model->setQuery(strSQL);
               QMessageBox msgBox;
               msgBox.setText("修改成功");
               msgBox.exec();
           this->close();
       }
}

void PersonnelUpdata::on_pushButton_2_clicked()
{
    this->close();
}
