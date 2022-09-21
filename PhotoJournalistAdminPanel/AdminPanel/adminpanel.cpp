#include "adminpanel.h"
#include "ui_adminpanel.h"

AdminPanel::AdminPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminPanel)
{
    ui->setupUi(this);
    setWindowState(Qt::WindowMaximized);
    show();
}

AdminPanel::~AdminPanel()
{
    delete ui;
}
