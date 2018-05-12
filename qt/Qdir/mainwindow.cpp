#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QMessageBox>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QDir dir("/home/vinay");
    QDir dir;
//    if(dir.exists()){
//        //QMessageBox::information(this,"Exist","Ok");
//        foreach (QFileInfo var, dir.drives()){
//            ui->comboBox->addItem(var.absoluteFilePath());
//        }
//    }
    QDir dir1("/home/vinay");
    foreach (QFileInfo var, dir1.entryInfoList()){
        ui->comboBox->addItem(var.absoluteFilePath());
        ui->listWidget->addItem(var.absoluteFilePath());
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug()<< ui->comboBox->currentText();
    qDebug() << ui->listWidget->currentItem()->text();
}
