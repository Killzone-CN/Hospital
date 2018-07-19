#-------------------------------------------------
#
# Project created by QtCreator 2017-06-03T13:07:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = student
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    logindlg.cpp \
    tms.cpp \
    salary.cpp \
    change.cpp \
    addapparatus.cpp \
    addpotion.cpp \
    addchuang.cpp \
    addpatient.cpp \
    addsalary.cpp \
    addpersonnel.cpp \
    personneldel.cpp \
    personnelcha.cpp \
    personnelupdata.cpp \
    addjob.cpp \
    adddept.cpp

HEADERS  += mainwindow.h \
    logindlg.h \
    tms.h \
    salary.h \
    change.h \
    addapparatus.h \
    addpotion.h \
    addchuang.h \
    addpatient.h \
    addsalary.h \
    addpersonnel.h \
    personneldel.h \
    personnelcha.h \
    personnelupdata.h \
    addjob.h \
    adddept.h

FORMS    += mainwindow.ui \
    logindlg.ui \
    tms.ui \
    salary.ui \
    change.ui \
    addapparatus.ui \
    addpotion.ui \
    addchuang.ui \
    addpatient.ui \
    addsalary.ui \
    addpersonnel.ui \
    personneldel.ui \
    personnelcha.ui \
    personnelupdata.ui \
    addjob.ui \
    adddept.ui
QT+=sql
RC_FILE = a.rc
