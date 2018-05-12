#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem(QIcon(":/res/pics/add.png"),"Add");
    ui->comboBox->addItem(QIcon(":/res/pics/open.png"),"Open");
    ui->comboBox->addItem(QIcon(":/res/pics/exit.png"),"Exit");
    int i;
    for(i = 0; i< 6; i++){

        ui->comboBox->addItem("Item "+ QString::number(i));
    }

    //ui->comboBox->insertItem(4,QIcon(":/res/pics/open.png"),"Open");
    ui->comboBox->insertItem(4,"Open");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ok_clicked()
{
    QMessageBox::information(this, "Select", ui->comboBox->currentText());
    QString str = ui->comboBox->currentText();
    if(str == "Exit")
        QApplication::exit();
}
