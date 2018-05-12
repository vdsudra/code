#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "seconddilog.h"
namespace Ui {
class loginWindow;
}

class loginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = 0);
    ~loginWindow();

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::loginWindow *ui;
    seconddilog *sec;
};

#endif // LOGINWINDOW_H
