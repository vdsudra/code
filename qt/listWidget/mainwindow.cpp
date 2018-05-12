#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QListWidgetItem *item = new QListWidgetItem(QIcon(":/res/pics/open.png"),"Open");
    ui->listWidget->addItem(item);
    item = new QListWidgetItem(QIcon(":/res/pics/exit.png"),"Close");
    ui->listWidget->addItem(item);
     item = new QListWidgetItem(QIcon(":/res/pics/add.png"),"Add");
    ui->listWidget->addItem(item);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ok_clicked()
{
//QMessageBox::information(this, "Clicked",ui->listWidget->currentItem()->text());
    ui->listWidget->currentItem()->setBackgroundColor(Qt::red);
    ui->listWidget->currentItem()->setForeground(Qt::white);
}
