#include "adminpanel.h"
#include "ui_adminpanel.h"

AdminPanel::AdminPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminPanel)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);;
}

AdminPanel::~AdminPanel()
{
    delete ui;
}
