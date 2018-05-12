#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>
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

void MainWindow::on_actionNew_triggered()
{
    QMessageBox::information(this, "New", "New file");
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}
