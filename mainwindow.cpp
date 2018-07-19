#include "mainwindow.h"
#include "ui_mainwindow.h"
//手工添加以下引用
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "tms.h"
#include "salary.h"
#include "change.h"
#include "addapparatus.h"
#include "addpotion.h"
#include "addsalary.h"
#include "addchuang.h"
#include "addpersonnel.h"
#include "addpatient.h"
#include "personnelcha.h"
#include "personneldel.h"
#include "personnelupdata.h"
#include "addjob.h"
#include "adddept.h"
#include "logindlg.h"
#include "QDebug"
#include "QSqlError"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);//setupUi(this)是由.ui文件生成的类的构造函数

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select * from patient");//这里直接设置SQL语句，忽略最后一个参数
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

Dialog::Dialog(QDialog *parent)
    :QDialog(parent)
{
    wa=new QDialog();
    wa->setWindowTitle(tr("Manuel2"));
    dialog=new QDialog();
    dialog->setWindowTitle(tr("Manuel1"));
}
void Dialog::dialogUse()
{
    dialog->show();

}
void Dialog::waUse()
{
    wa->show();

}
void Dialog::findClick()
{
}
void Dialog::enableFindButton()
{

}
Dialog::~Dialog()  //Dialog类的析构函数里面不知道写什么，就没写，哈哈......
{

}
void MainWindow::on_pushButton_2_clicked()
{
    Dialog *dialogLogin=new Dialog;
    dialogLogin->dialogUse();
}
void MainWindow::on_pushButton_3_clicked()
{
    Dialog *dialogLogin1=new Dialog;
    dialogLogin1->waUse();
}

void MainWindow::on_action_triggered()
{
    AddPersonnel personnel;
    personnel.exec();
}



void MainWindow::on_pushButton_5_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select * from personnel");//这里直接设置SQL语句，忽略最后一个参数
    ui->tableView_2->setModel(model);

    //以下是视觉方面的效果，不加也没影响

    //隔行变色
    ui->tableView_2->setAlternatingRowColors(true);

    //设置行高
    int row_count = model->rowCount();
    for(int i =0; i < row_count; i++)
    {
        ui->tableView_2->setRowHeight(i, 20);
    }
}



void MainWindow::on_pushButton_12_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select * from chuang");//这里直接设置SQL语句，忽略最后一个参数
    ui->tableView_3->setModel(model);

    //以下是视觉方面的效果，不加也没影响

    //隔行变色
    ui->tableView_3->setAlternatingRowColors(true);

    //设置行高
    int row_count = model->rowCount();
    for(int i =0; i < row_count; i++)
    {
        ui->tableView_3->setRowHeight(i, 20);
    }
}

void MainWindow::on_pushButton_14_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select * from apparatus");//这里直接设置SQL语句，忽略最后一个参数
    ui->tableView_4->setModel(model);

    //以下是视觉方面的效果，不加也没影响

    //隔行变色
    ui->tableView_4->setAlternatingRowColors(true);

    //设置行高
    int row_count = model->rowCount();
    for(int i =0; i < row_count; i++)
    {
        ui->tableView_4->setRowHeight(i, 20);
    }
}

void MainWindow::on_pushButton_18_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select * from potion");//这里直接设置SQL语句，忽略最后一个参数
    ui->tableView_5->setModel(model);

    //以下是视觉方面的效果，不加也没影响

    //隔行变色
    ui->tableView_5->setAlternatingRowColors(true);

    //设置行高
    int row_count = model->rowCount();
    for(int i =0; i < row_count; i++)
    {
        ui->tableView_5->setRowHeight(i, 20);
    }
}

void MainWindow::on_pushButton_19_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QString temStr,strSQL="SELECT * FROM potion where ";
    temStr=this->ui->comboBox_6->currentText();
    strSQL+=temStr+"=";
    strSQL+="'"+this->ui->potion_cha->text()+"'";
    model->setQuery(strSQL);//这里直接设置SQL语句，忽略最后一个参数
    ui->tableView_5->setModel(model);

    //以下是视觉方面的效果，不加也没影响

    //隔行变色
    ui->tableView_5->setAlternatingRowColors(true);

    //设置行高
    int row_count = model->rowCount();
    for(int i =0; i < row_count; i++)
    {
        ui->tableView_5->setRowHeight(i, 20);
    }
}


void MainWindow::on_pushButton_21_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QString temStr,strSQL="delete FROM potion where ";
    temStr=this->ui->comboBox_7->currentText();
    strSQL+=temStr+"=";
    strSQL+="'"+this->ui->potion_del->text()+"'";
    model->setQuery(strSQL);//这里直接设置SQL语句，忽略最后一个参数
    model->setQuery("select * from potion");//这里直接设置SQL语句，忽略最后一个参数
    ui->tableView_5->setModel(model);

    //以下是视觉方面的效果，不加也没影响

    //隔行变色
    ui->tableView_5->setAlternatingRowColors(true);

    //设置行高
    int row_count = model->rowCount();
    for(int i =0; i < row_count; i++)
    {
        ui->tableView_5->setRowHeight(i, 20);
    }
}


void MainWindow::on_pushButton_20_clicked()
{
//    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel;
    QString temStr,strSQL="update potion set ";
    temStr=this->ui->comboBox_8->currentText();
    strSQL+=temStr+"=";
    strSQL+="'"+this->ui->potion_updata->text().trimmed()+"'";
    strSQL+=" where 药剂代号=";
    strSQL+=""+this->ui->potion_id->text().trimmed()+"";
//    query.exec(QObject::tr("update potion set id=333 where id=5"));
    model->setQuery(strSQL);//这里直接设置SQL语句，忽略最后一个参数
    model->setQuery("select * from potion");//这里直接设置SQL语句，忽略最后一个参数
    ui->tableView_5->setModel(model);

    //以下是视觉方面的效果，不加也没影响

    //隔行变色
    ui->tableView_5->setAlternatingRowColors(true);

    //设置行高
    int row_count = model->rowCount();
    for(int i =0; i < row_count; i++)
    {
        ui->tableView_5->setRowHeight(i, 20);
    }
}

void MainWindow::on_pushButton_15_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QString temStr,strSQL="SELECT * FROM apparatus where ";
    temStr=this->ui->comboBox_4->currentText();
    strSQL+=temStr+"=";
    strSQL+="'"+this->ui->apparatus_cha->text()+"'";
    model->setQuery(strSQL);//这里直接设置SQL语句，忽略最后一个参数
    ui->tableView_4->setModel(model);

    //以下是视觉方面的效果，不加也没影响

    //隔行变色
    ui->tableView_4->setAlternatingRowColors(true);

    //设置行高
    int row_count = model->rowCount();
    for(int i =0; i < row_count; i++)
    {
        ui->tableView_4->setRowHeight(i, 20);
    }
}

void MainWindow::on_pushButton_17_clicked()
{
    //    QSqlQuery query;
        QSqlQueryModel *model = new QSqlQueryModel;
        QString temStr,strSQL="update apparatus set ";
        temStr=this->ui->comboBox_9->currentText();
        strSQL+=temStr+"=";
        strSQL+="'"+this->ui->apparatus_updata->text().trimmed()+"'";
        strSQL+=" where 仪器代号=";
        strSQL+=""+this->ui->apparatus_id->text().trimmed()+"";
    //    query.exec(QObject::tr("update potion set id=333 where id=5"));
        model->setQuery(strSQL);//这里直接设置SQL语句，忽略最后一个参数
        model->setQuery("select * from apparatus");//这里直接设置SQL语句，忽略最后一个参数
        ui->tableView_4->setModel(model);

        //以下是视觉方面的效果，不加也没影响

        //隔行变色
        ui->tableView_4->setAlternatingRowColors(true);

        //设置行高
        int row_count = model->rowCount();
        for(int i =0; i < row_count; i++)
        {
            ui->tableView_4->setRowHeight(i, 20);
        }
}

void MainWindow::on_pushButton_16_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QString temStr,strSQL="delete FROM apparatus where ";
    temStr=this->ui->comboBox_5->currentText();
    strSQL+=temStr+"=";
    strSQL+="'"+this->ui->apparatus_del->text()+"'";
    model->setQuery(strSQL);//这里直接设置SQL语句，忽略最后一个参数
    model->setQuery("select * from apparatus");//这里直接设置SQL语句，忽略最后一个参数
    ui->tableView_4->setModel(model);

    //以下是视觉方面的效果，不加也没影响

    //隔行变色
    ui->tableView_4->setAlternatingRowColors(true);

    //设置行高
    int row_count = model->rowCount();
    for(int i =0; i < row_count; i++)
    {
        ui->tableView_4->setRowHeight(i, 20);
    }
}

void MainWindow::on_pushButton_13_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QString temStr,strSQL="SELECT * FROM chuang where ";
    temStr=this->ui->comboBox_3->currentText();
    strSQL+=temStr+"=";
    strSQL+="'"+this->ui->chuang_cha->text()+"'";
    model->setQuery(strSQL);//这里直接设置SQL语句，忽略最后一个参数
    ui->tableView_3->setModel(model);

    //以下是视觉方面的效果，不加也没影响

    //隔行变色
    ui->tableView_3->setAlternatingRowColors(true);

    //设置行高
    int row_count = model->rowCount();
    for(int i =0; i < row_count; i++)
    {
        ui->tableView_3->setRowHeight(i, 20);
    }
}

void MainWindow::on_pushButton_11_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QString temStr,strSQL="SELECT * FROM patient where ";
    temStr=this->ui->comboBox->currentText();
    strSQL+=temStr+"=";
    strSQL+="'"+this->ui->patient_cha->text()+"'";
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

void MainWindow::on_pushButton_22_clicked()
{
    //    QSqlQuery query;
        QSqlQueryModel *model = new QSqlQueryModel;
        QString temStr,strSQL="update patient set ";
        temStr=this->ui->comboBox_10->currentText();
        strSQL+=temStr+"=";
        strSQL+="'"+this->ui->patient_updata->text().trimmed()+"'";
        strSQL+=" where patient_name=";
        strSQL+="'"+this->ui->patient_id->text().trimmed()+"'";
    //    query.exec(QObject::tr("update potion set id=333 where id=5"));
        model->setQuery(strSQL);//这里直接设置SQL语句，忽略最后一个参数
        model->setQuery("select * from patient");//这里直接设置SQL语句，忽略最后一个参数
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
void MainWindow::on_pushButton_4_clicked()
{
    QString str,qqstr;
    QSqlQueryModel *model = new QSqlQueryModel;
    QString temStr,strSQL="delete FROM patient where ";
    str=this->ui->comboBox_2->currentText();
    qqstr="update chuang set STATE='free' where BED in(select patient_bed from patient where ";
    qqstr+=str+"=";
    qqstr+="'"+this->ui->patient_del->text().trimmed()+"')";
    qDebug()<<qqstr;
    model->setQuery(qqstr);

    temStr=this->ui->comboBox_2->currentText();
    strSQL+=temStr+"=";
    strSQL+="'"+this->ui->patient_del->text()+"'";
    model->setQuery(strSQL);//这里直接设置SQL语句，忽略最后一个参数
    model->setQuery("select * from patient");//这里直接设置SQL语句，忽略最后一个参数
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

void MainWindow::on_pushButton_6_clicked()
{
    tms user;
    if( user.exec()==QDialog::Accepted)
    {
        Salary salary;
        salary.exec();
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    tms user;
    if( user.exec()==QDialog::Accepted)
    {
        Change change;
        change.exec();
    }
}

void MainWindow::on_action_6_triggered()
{
    AddApparatus apparatus;
    apparatus.exec();
}

void MainWindow::on_action_5_triggered()
{
    AddPotion potion;
    potion.exec();
}

void MainWindow::on_action_4_triggered()
{
    AddChuang chuang;
    chuang.exec();
}

void MainWindow::on_action_3_triggered()
{
    AddPatient patient;
    patient.exec();
}

void MainWindow::on_action_2_triggered()
{
    AddJob addjob;
    addjob.exec();

}

void MainWindow::on_action_7_triggered()
{
    AddSalary salary;
    salary.exec();
}

void MainWindow::on_pushButton_8_clicked()
{
    PersonnelUpdata personnelupdata;
    personnelupdata.exec();
}

void MainWindow::on_pushButton_10_clicked()
{
    PersonnelDel personneldel;
    personneldel.exec();
}

void MainWindow::on_pushButton_9_clicked()
{
    PersonnelCha personnelcha;
    personnelcha.exec();
}

void MainWindow::on_pushButton_23_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QString strSQL="SELECT * FROM job";
    model->setQuery(strSQL);//这里直接设置SQL语句，忽略最后一个参数
    ui->tableView_6->setModel(model);

    //以下是视觉方面的效果，不加也没影响

    //隔行变色
    ui->tableView_6->setAlternatingRowColors(true);

    //设置行高
    int row_count = model->rowCount();
    for(int i =0; i < row_count; i++)
    {
        ui->tableView_6->setRowHeight(i, 20);
    }
}

void MainWindow::on_pushButton_24_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QString strSQL="SELECT * FROM dept ";
    model->setQuery(strSQL);//这里直接设置SQL语句，忽略最后一个参数
    ui->tableView_6->setModel(model);

    //以下是视觉方面的效果，不加也没影响

    //隔行变色
    ui->tableView_6->setAlternatingRowColors(true);

    //设置行高
    int row_count = model->rowCount();
    for(int i =0; i < row_count; i++)
    {
        ui->tableView_6->setRowHeight(i, 20);
    }
}

void MainWindow::on_action_8_triggered()
{
    AddDept adddept;
    adddept.exec();
}

void MainWindow::on_pushButton_25_clicked()
{
    //删除数据库中的选中行
    QSqlQueryModel *model = new QSqlQueryModel;
    QItemSelectionModel *selections = ui->tableView_5->selectionModel();
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
         int curRow = ui->tableView_5->currentIndex().row();

          QModelIndex index = ui->tableView_5->currentIndex();

          int id=index.sibling(curRow,0).data().toInt();


          QSqlQuery query;

              query.prepare("delete from potion where 药剂代号 =:id ");

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
              QString strSQL="SELECT * FROM potion";
              model->setQuery(strSQL);//这里直接设置SQL语句，忽略最后一个参数
              ui->tableView_5->setModel(model);

              //以下是视觉方面的效果，不加也没影响

              //隔行变色
              ui->tableView_5->setAlternatingRowColors(true);

              //设置行高
              int row_count = model->rowCount();
              for(int i =0; i < row_count; i++)
              {
                  ui->tableView_5->setRowHeight(i, 20);
              }
}

void MainWindow::on_pushButton_26_clicked()
{
    //删除数据库中的选中行
    QSqlQueryModel *model = new QSqlQueryModel;
    QItemSelectionModel *selections = ui->tableView_4->selectionModel();
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
         int curRow = ui->tableView_4->currentIndex().row();

          QModelIndex index = ui->tableView_4->currentIndex();

          int id=index.sibling(curRow,0).data().toInt();


          QSqlQuery query;

              query.prepare("delete from apparatus where 仪器代号 =:id ");

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

              QString strSQL="SELECT * FROM apparatus";
              model->setQuery(strSQL);//这里直接设置SQL语句，忽略最后一个参数
              ui->tableView_4->setModel(model);

              //以下是视觉方面的效果，不加也没影响

              //隔行变色
              ui->tableView_4->setAlternatingRowColors(true);

              //设置行高
              int row_count = model->rowCount();
              for(int i =0; i < row_count; i++)
              {
                  ui->tableView_4->setRowHeight(i, 20);
              }
}
