#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
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

void MainWindow::on_pushButton_radio_clicked()
{
    if(ui->radioButton_yes->isChecked())
        QMessageBox::information(this, "Radio Button", "Yes Clicked.. ");
    else
        QMessageBox::information(this, "Radio Button", "No Clicked.. ");
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->checkBox_yes->isChecked())
        QMessageBox::information(this, "Check Box", "Yes Clicked.. ");
    else
        QMessageBox::information(this, "Check Box", "No Clicked.. ");
}
