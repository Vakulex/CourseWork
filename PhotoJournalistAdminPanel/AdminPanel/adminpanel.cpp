#include "adminpanel.h"
#include "DatabaseManager/databasemanager.h"
#include "ui_adminpanel.h"
#include "qsqlquery.h"
#include "qdebug.h"

AdminPanel::AdminPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminPanel)
{
    ui->setupUi(this);

    DatabaseManager::Get().ConnectToDatabase();
    model = new QSqlTableModel();
    createModel(model);
    WidgetSettings();
    initResources();
}

AdminPanel::~AdminPanel()
{
    delete ui;
}

void AdminPanel::initResources()
{
    ui->AddButton->setIcon(QIcon(":/icons/img/b_plus_icon.png"));
    ui->DeleteButton->setIcon(QIcon(":/icons/img/b_minus_icon.png"));
    ui->ProfileMenu->setIcon(QIcon(":/icons/img/b_user_icon.png"));
    ui->FilterComboBox->setItemIcon(0, QIcon(":/icons/img/filter_icon.png"));
}

void AdminPanel::createModel(QSqlTableModel *model)
{
    model->setTable("users");
    model->select();
    ui->UsersTable->setModel(model);
    ui->UsersTable->hideColumn(0);
}

void AdminPanel::WidgetSettings()
{
    ui->UsersTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->UsersTable->horizontalHeader()->setStretchLastSection(true);

    ui->OptionsAction->setIcon(QIcon(":/icons/img/b_gear_icon.png"));
    ui->SaveAction->setIcon(QIcon(":/icons/img/b_save_icon.png"));
}
