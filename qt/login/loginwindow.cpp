#include "loginwindow.h"
#include "ui_loginwindow.h"
#include  <qmessagebox.h>
#include <qpixmap.h>
loginWindow::loginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);
    QPixmap pix("/home/vinay/Pictures/ledboard/20.jpg");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    //ui->label_pic->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->status_login->addPermanentWidget(ui->label);
    ui->status_login->addPermanentWidget(ui->progressBar);
}

loginWindow::~loginWindow()
{
    delete ui;
}

void loginWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_userName->text();
    QString pass = ui->lineEdit_password->text();
    if(username == "test" &&  pass == "test"){
        QMessageBox::information(this, "Login", "Login successfull");
        ui->status_login->showMessage("User name and password is correct...");
        //sec = new seconddilog(this);
        //sec->show();
        //QDebug("Login successfull");
    }
    else{
        QMessageBox::warning(this, "Error", "Incorrect user name and password");
        ui->status_login->showMessage("Username and password is incorrect...",1000);
        //QDebug("Wrong username and password");
    }

}
