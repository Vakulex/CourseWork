#include "databaseoptions.h"
#include "ui_databaseoptions.h"

DataBaseOptions::DataBaseOptions(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataBaseOptions)
{
    ui->setupUi(this);
}

DataBaseOptions::~DataBaseOptions()
{
    delete ui;
}

void DataBaseOptions::on_ApplyButton_clicked()
{
    DatabaseManager::GetInstance()->editDatabase(ui->HostnameLineEdit->text(),
                                                 ui->UserNameLineEdit->text(),
                                                 ui->PasswordLineEdit->text(),
                                                 ui->DBNameLineEdit->text());
    if(DatabaseManager::GetInstance()->checkDatabaseConnection())
    DataBaseOptions::~DataBaseOptions();
}
