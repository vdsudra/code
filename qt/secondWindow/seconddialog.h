#ifndef SECONDDIALOG_H
#define SECONDDIALOG_H

#include <QDialog>

namespace Ui {
class secondDialog;
}

class secondDialog : public QDialog
{
    Q_OBJECT

public:
    explicit secondDialog(QWidget *parent = 0);
    ~secondDialog();

private:
    Ui::secondDialog *ui;
};

#endif // SECONDDIALOG_H
