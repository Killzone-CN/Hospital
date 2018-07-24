#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include "logindlg.h"

void OpenDatabase()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName(QString("DRIVER={SQL SERVER};"
                               "SERVER=%1;" //服务器名称
                               "DATABASE=%2;"//数据库名
                               ).arg("HASEE-PC\\SQLEXPRESS")
                       .arg("student")
                       );
    if (!db.open())
    {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
        db.lastError().databaseText(), QMessageBox::Cancel);

    }
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    OpenDatabase();
//    LoginDlg login; //登陆界面
//    if(login.exec()==QDialog::Accepted)
//    {
      w.show();
      //打开数据库
      return a.exec();
//    }
//    else return 0;
}
