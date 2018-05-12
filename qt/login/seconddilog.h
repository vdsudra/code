#ifndef SECONDDILOG_H
#define SECONDDILOG_H

#include <QDialog>

namespace Ui {
class seconddilog;
}

class seconddilog : public QDialog
{
    Q_OBJECT

public:
    explicit seconddilog(QWidget *parent = 0);
    ~seconddilog();

private:
    Ui::seconddilog *ui;
};

#endif // SECONDDILOG_H
