#include "tms.h"
#include "ui_tms.h"
#include "QMessageBox.h"
#include "QTextCodec.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "QDebug"

tms::tms(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tms)
{
    ui->setupUi(this);
    ui->Tpwd->setEchoMode(QLineEdit::Password);//当输入密码时，显示为*******
}

tms::~tms()
{
    delete ui;
}
void tms::changeEvent(QEvent *e)
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

void tms::on_pushButton_clicked()
{
    QSqlQuery query;
    QString gg="HH";
    QString user="'"+this->ui->Tuser->text()+"'";
    QString pwd=this->ui->Tpwd->text();
    QString s=QString("select * from tms where TMS_USER=%1").arg(user);
    query.exec(s);
    if(!query.first())
    {
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB18030"));
        QMessageBox::warning(this,tr("警告"),tr("用户不存在！"),QMessageBox::Yes);
        this->ui->Tuser->clear();//清空用户名输入框
        this->ui->Tpwd->clear();//清空密码输入框
        this->ui->Tuser->setFocus();//将光标转到用户名输入框
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
            QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB18030"));
            QMessageBox::warning(this,tr("警告"),tr("权限不足!请使用超级管理员登录!"),QMessageBox::Yes);
            this->ui->Tuser->clear();//清空用户名输入框
            this->ui->Tpwd->clear();//清空密码输入框
            this->ui->Tuser->setFocus();//将光标转到用户名输入框
        }
    }else
    {QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB18030"));
    QMessageBox::warning(this,tr("警告"),tr("密码错误!"),QMessageBox::Yes);
    this->ui->Tuser->clear();//清空用户名输入框
    this->ui->Tpwd->clear();//清空密码输入框
    this->ui->Tuser->setFocus();//将光标转到用户名输入框
    }
    }
}

void tms::on_pushButton_2_clicked()
{
        this->close();

}
