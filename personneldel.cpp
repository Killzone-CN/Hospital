#include "personneldel.h"
#include "ui_personneldel.h"
#include "QSqlQueryModel"
#include <QCloseEvent>
#include "QMessageBox"

PersonnelDel::PersonnelDel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonnelDel)
{
    ui->setupUi(this);
}

PersonnelDel::~PersonnelDel()
{
    delete ui;
}

void PersonnelDel::on_pushButton_clicked()
{
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this, tr("确认"),QString(tr("是否删除此信息？")),QMessageBox::Yes | QMessageBox::No);
       if (button == QMessageBox::No) {
             this->close();  //忽略退出信号，程序继续运行
       }
       else if (button == QMessageBox::Yes) {
           QSqlQueryModel *model = new QSqlQueryModel;
           QString temStr,strSQL="delete FROM personnel where ";
           temStr=this->ui->comboBox->currentText();
           strSQL+=temStr+"=";
           strSQL+="'"+this->ui->a->text()+"'";
           model->setQuery(strSQL);
               QMessageBox msgBox;
               msgBox.setText("删除成功");
               msgBox.exec();
           this->close();
       }

}

void PersonnelDel::on_pushButton_2_clicked()
{
    this->close();
}
