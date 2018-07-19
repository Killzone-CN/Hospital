#include "salary.h"
#include "ui_salary.h"
#include <QSqlQueryModel>
#include <QSqlQuery>

Salary::Salary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Salary)
{
    ui->setupUi(this);
}

Salary::~Salary()
{
    delete ui;
}

void Salary::on_pushButton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select * from salary");//这里直接设置SQL语句，忽略最后一个参数
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
