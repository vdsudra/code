#include "seconddilog.h"
#include "ui_seconddilog.h"

seconddilog::seconddilog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::seconddilog)
{
    ui->setupUi(this);
}

seconddilog::~seconddilog()
{
    delete ui;
}
