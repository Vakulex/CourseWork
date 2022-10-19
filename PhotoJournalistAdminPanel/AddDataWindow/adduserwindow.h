#ifndef ADDUSERWINDOW_H
#define ADDUSERWINDOW_H

#include <QMainWindow>

namespace Ui {
class adduserwindow;
}

class adduserwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit adduserwindow(QWidget *parent = nullptr);
    ~adduserwindow();

private:
    Ui::adduserwindow *ui;
};

#endif // ADDUSERWINDOW_H
