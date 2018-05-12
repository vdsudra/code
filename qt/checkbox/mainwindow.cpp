#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->checkBox_r->setChecked(true);
//    ui->checkBox_s->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_submit_clicked()
{
    if(ui->checkBox_r->isChecked()){





        qDebug() << "Can Read";
    }
    else{
        qDebug() << "Can't Read";
    }

    if(ui->checkBox_w->isChecked()){
        qDebug() << "Can Write";
    }
    else{
        qDebug() << "Can't Write";

    }

    if(ui->checkBox_s->isChecked()){
        qDebug() << "Can Speak";
    }
    else{
        qDebug() << "Can't Speak";
    }
    QMessageBox::information(this, "Checked", "Ok");

}

void MainWindow::on_checkBox_r_stateChanged(int arg1)
{
    if(arg1)
        QMessageBox::information(this, "Read", "Ok");
}

void MainWindow::on_checkBox_w_stateChanged(int arg1)
{
    if(arg1)
        QMessageBox::information(this, "Write", "Ok");
}

void MainWindow::on_checkBox_s_stateChanged(int arg1)
{
    if(arg1)
        QMessageBox::information(this, "Speak", "Ok");
}
