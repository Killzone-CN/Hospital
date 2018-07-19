#include "personnelcha.h"
#include "ui_personnelcha.h"
#include "QSqlQueryModel"
#include "QMessageBox"
#include "QSqlQuery"
#include "QItemSelectionModel"
#include "QModelIndexList"
#include "QModelIndex"
#include "QMap"
#include "QMapIterator"
#include "QDebug"
#include "QSqlError"

PersonnelCha::PersonnelCha(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonnelCha)
{
    ui->setupUi(this);
    QSqlQueryModel *model1 = new QSqlQueryModel;
    model1->setQuery("SELECT * FROM personnel");//这里直接设置SQL语句，忽略最后一个参数
    ui->tableView->setModel(model1);

    //以下是视觉方面的效果，不加也没影响

    //隔行变色
    ui->tableView->setAlternatingRowColors(true);

    //设置行高
    int row_count = model1->rowCount();
    for(int i =0; i < row_count; i++)
    {
        ui->tableView->setRowHeight(i, 20);
    }

}

PersonnelCha::~PersonnelCha()
{
    delete ui;
}

void PersonnelCha::on_pushButton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QString temStr,strSQL="SELECT * FROM personnel where ";
    temStr=this->ui->comboBox->currentText();
    strSQL+=temStr+"=";
    strSQL+="'"+this->ui->a->text()+"'";
    model->setQuery(strSQL);//这里直接设置SQL语句，忽略最后一个参数
    ui->tableView->setModel(model);

    //以下是视觉方面的效果，不加也没影响

    //隔行变色
    ui->tableView->setAlternatingRowColors(true);

    //设置行高
    int row_count = model->rowCount();
    for(int i =0; i < row_count; i++)
    {
        ui->tableView->setRowHeight(i, 20);
    }
}

void PersonnelCha::on_pushButton_2_clicked()
{
    this->close();
}

void PersonnelCha::on_pushButton_3_clicked()
{
    //删除数据库中的选中行
    QSqlQueryModel *model = new QSqlQueryModel;
    QItemSelectionModel *selections = ui->tableView->selectionModel();
    QModelIndexList selected = selections->selectedIndexes();
    QMap<int, int> rows;
    foreach (QModelIndex index, selected)
       rows.insert(index.row(), 0);
    QMapIterator<int, int> r(rows);
    r.toBack();
    while (r.hasPrevious()) {
           r.previous();
       model->removeRow(r.key());
    }
         int curRow = ui->tableView->currentIndex().row();

          QModelIndex index = ui->tableView->currentIndex();

          int id=index.sibling(curRow,0).data().toInt();


          QSqlQuery query;

              query.prepare("delete from personnel where emp_no =:id ");

              query.bindValue(":id",id);
              qDebug("shuzi is %d",id);
              bool ok=query.exec();
              if(ok)
              {
                  qDebug()<<"delete success";
              }
              else
              {
                  qDebug()<<"delete error"<<query.lastError().text();

              }
}
