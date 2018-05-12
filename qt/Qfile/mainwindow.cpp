#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include<QTextStream>
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

void MainWindow::on_pushButton_read_clicked()
{
    QFile file("myfile.txt");
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
       qDebug() << "Error to open in read mode..";
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();
    }

void MainWindow::on_pushButton_write_clicked()
{
    QFile file("myfile.txt");
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug()<< "Error to open in write mode..";
    }
    QTextStream out(&file);
    QString text = ui->plainTextEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}
