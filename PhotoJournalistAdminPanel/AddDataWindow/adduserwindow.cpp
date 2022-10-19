#include "adduserwindow.h"
#include "ui_adduserwindow.h"

adduserwindow::adduserwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adduserwindow)
{
    ui->setupUi(this);
}

adduserwindow::~adduserwindow()
{
    delete ui;
}
