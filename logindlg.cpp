#include "logindlg.h"
#include "ui_logindlg.h"
#include "QMessageBox.h"
#include "QTextCodec.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QInputDialog>
#include "QDebug"
LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);
    ui->txtpwd->setEchoMode(QLineEdit::Password);//当输入密码时，显示为*******
}

LoginDlg::~LoginDlg()
{
    delete ui;
}
void LoginDlg::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void LoginDlg::on_pushButton_clicked()
{
    QSqlQuery query;
    QString gg="HH";
    QString user="'"+this->ui->txtname->text().trimmed()+"'";
    QString pwd=this->ui->txtpwd->text().trimmed();
    QString s=QString("select * from tms where TMS_USER=%1").arg(user);
    query.exec(s);
    if(!query.first())
    {
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB18030"));
        QMessageBox::warning(this,tr("警告"),tr("用户不存在！"),QMessageBox::Yes);
        this->ui->txtname->clear();//清空用户名输入框
        this->ui->txtpwd->clear();//清空密码输入框
        this->ui->txtname->setFocus();//将光标转到用户名输入框
    }
    else{
    query.first();
    QString i1=query.value(0).toString();
    QString i2=query.value(1).toString();
    qDebug()<<i1;
    qDebug()<<i2;
    if(pwd==query.value(1).toString())
    {
        if(query.value(2).toString()==gg)
        {
        QMessageBox msgBox;
        msgBox.setText("欢迎超级管理员！");
        msgBox.exec();
        accept();
        }else{
            QMessageBox msgBox;
            msgBox.setText("欢迎管理员！");
            msgBox.exec();
            accept();
        }
    }else
    {
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB18030"));
   // QMessageBox::about(this, "About", " <font color='blue'>信息</font>");
        QMessageBox msg;
        msg.setWindowTitle(tr("Title"));
        msg.setText(tr("Text"));
        msg.setIcon(QMessageBox::Information);
       // msg.setIconPixmap(QPixmap("1.png"));
        msg.addButton(tr("NO"),QMessageBox::NoRole);
        msg.addButton(tr("YES"),QMessageBox::YesRole);
        if(msg.exec())
        {
           QMessageBox::about(this, "About", " <font color='blue'>信息</font>");
        }
        else
           this->close();
   // QMessageBox::information(this, "Title", "Text");
 /*       QMessageBox::StandardButton test;
        test = QMessageBox::question(this, "Title", "确定?", QMessageBox::Yes | QMessageBox::No);
        if(test == QMessageBox::Yes)
        {
        }
        else
        {
        }
    QMessageBox::StandardButton test;
    test:QMessageBox::critical(this,tr("错误"),tr("错误原因"), QMessageBox::Yes | QMessageBox::No);
    if(test == QMessageBox::Yes)
    {
    }
    else
    {
    }
        QMessageBox::StandardButton test;
        test:QMessageBox::warning(this,tr("警告"),tr("密码错误!"),QMessageBox::Yes | QMessageBox::No);
        if(test == QMessageBox::Yes)
        {
        }
        else
        {
        }


           bool ok;
           QString name=QInputDialog::getText(this,tr("标准输入对话框"),tr("请输入姓名："),  QLineEdit::Normal,ui->name->text(),&ok);
           if(ok&&!name.isEmpty())
               ui->name->setText(name);

           QStringList SexList;
           SexList<<tr("男")<<tr("女");
           bool ok;
           QString SexItem=QInputDialog::getItem(this,tr("标准条目选择对话框"),tr("请选择性别："),  SexList,0,false,&ok);
           if(ok&&!SexItem.isEmpty())
               ui->sex->setText(SexItem);

           bool ok;
              int ageInt=QInputDialog::getInt(this,tr("标准整数输入对话框"),tr("请输入年龄："), ui->age->text().toInt(&ok),1,200,1,&ok);
              if(ok)
                  ui->age->setText(QString(tr("%1")).arg(ageInt));

              bool ok;
              double score=QInputDialog::getDouble(this,tr("标准浮点数输入对话框"),tr("请输入成绩："),  ui->grade->text().toDouble(&ok),1,100,1,&ok);
              if(ok)
                  ui->grade->setText(QString(tr("%1")).arg(score));  */

    this->ui->txtname->clear();//清空用户名输入框
    this->ui->txtpwd->clear();//清空密码输入框
    this->ui->txtname->setFocus();//将光标转到用户名输入框
    }
    }
}

void LoginDlg::on_pushButton_2_clicked()
{
    this->close();
}

