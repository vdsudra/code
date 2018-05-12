#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->MainWindow)
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bt1_clicked()
{
    ui->l1->setText("@#$%^&*");
}
