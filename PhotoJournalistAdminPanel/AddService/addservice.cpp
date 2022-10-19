#include "addservice.h"
#include "ui_addservice.h"

AddService::AddService(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddService)
{
    ui->setupUi(this);
}

AddService::~AddService()
{
    delete ui;
}

void AddService::on_AddServiceButton_clicked()
{
    query->prepare("INSERT into services(name_service, type_service, service_price, commentary) "
                   "VALUES (" + ui->ServiceTitleLineEdit->text() + "," + ui->ServiceTypeComboBox->currentText() + "," + ui->PriceSpinBox->text() + "," + ui->CommentaryTextEdit->toPlainText() + ");");
    if(CheckFields())
        query->exec();
    AddService::~AddService();
}

bool AddService::CheckFields()
{
    bool isTitleCorrect = !ui->ServiceTitleLineEdit->text().isEmpty();
    bool isPriceCorrect = !ui->PriceSpinBox->text().isEmpty();
    if(isTitleCorrect && isPriceCorrect)
        return true;
    return false;
}

