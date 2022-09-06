#include "reporteradminpanel.h"
#include "ui_reporteradminpanel.h"

ReporterAdminPanel::ReporterAdminPanel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ReporterAdminPanel)
{
    ui->setupUi(this);
}

ReporterAdminPanel::~ReporterAdminPanel()
{
    delete ui;
}

