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
    createUserModel(model);
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

    ui->ProfileAction->setIcon(QIcon(":/icons/img/b_user_icon.png"));
    ui->OptionsAction->setIcon(QIcon(":/icons/img/b_gear_icon.png"));
}

void AdminPanel::createUserModel(QSqlTableModel *model)
{
    model->setTable("users");
    model->select();

    model->setHeaderData(1, Qt::Horizontal, tr("Ім'я"));
    model->setHeaderData(2, Qt::Horizontal, tr("Прізвище"));
    model->setHeaderData(3, Qt::Horizontal, tr("По-батькові"));
    model->setHeaderData(4, Qt::Horizontal, tr("Номер телефону"));

    ui->UsersTable->setModel(model);
    ui->UsersTable->hideColumn(0);
}

void AdminPanel::WidgetSettings()
{
    ui->UsersTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->UsersTable->horizontalHeader()->setStretchLastSection(true);
}
