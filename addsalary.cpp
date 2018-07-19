#include "addsalary.h"
#include "ui_addsalary.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QComboBox>
#include <QCompleter>
#include <QStringList>
#include "QDebug"
#include <QCloseEvent>
#include "QMessageBox"

AddSalary::AddSalary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSalary)
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

AddSalary::~AddSalary()
{
    delete ui;
}

void AddSalary::on_pushButton_clicked()
{
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this, tr("确认"),QString(tr("是否修改此信息？")),QMessageBox::Yes | QMessageBox::No);
       if (button == QMessageBox::No) {
             this->close();  //忽略退出信号，程序继续运行
       }
       else if (button == QMessageBox::Yes) {
           QSqlQueryModel *model = new QSqlQueryModel;
           QString strSQL="update salary set ";
           strSQL+="SALARY=";
           strSQL+=""+this->ui->b->text().trimmed()+"";
           strSQL+=" where EMP_NO=";
           strSQL+=""+this->ui->comboBox->currentText()+"";
       //    query.exec(QObject::tr("update potion set id=333 where id=5"));
       //这里直接设置SQL语句，忽略最后一个参数
           model->setQuery(strSQL);
               QMessageBox msgBox;
               msgBox.setText("修改成功");
               msgBox.exec();

           this->close();
       }

}

void AddSalary::on_pushButton_2_clicked()
{
    this->close();
}
