#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushB1_clicked();

    void on_pushB2_clicked();

    void on_pushB3_clicked();

    void on_pushB4_clicked();

    void on_pushB5_clicked();

    void on_pushB6_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
