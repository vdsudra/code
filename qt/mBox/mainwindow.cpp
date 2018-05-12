#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushB1_clicked()
{
    QMessageBox::about(this, "My Title", "Clicked Button");
}

void MainWindow::on_pushB2_clicked()
{
    QMessageBox::aboutQt(this, "Qt Info");
}

void MainWindow::on_pushB3_clicked()
{
    QMessageBox::critical(this, "Critical", "This is critical mesaage");
}

void MainWindow::on_pushB4_clicked()
{
    QMessageBox::information(this, "Information", "Just Information");
    ui->lab1->hide();
}

void MainWindow::on_pushB5_clicked()
{
    //QMessageBox::question(this, "Question", "Are you sure?");
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Question",
                                        "Are you sure?",QMessageBox::YesAll | QMessageBox::No);
    if(reply == QMessageBox::YesAll){

        qDebug()<< "Yes Pressed..............";
    }
    else{
        qDebug()<<"No Pressed..............";
    }
}

void MainWindow::on_pushB6_clicked()
{
    QMessageBox::warning(this, "Warning !!", "@#$%");
}
